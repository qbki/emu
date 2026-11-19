module;
#include <cstdint>
#include <tuple>
export module arch.x86.xor_instructions;

import arch.x86.cpu;
import arch.x86.instruction;
import utils.cpu;
import utils.flow;

namespace arch::x86 {

/**
 * Opcode: 31
 * Instruction: XOR	r/m16/32	r16/32
 */
export
class Xor31Instruction : public Instruction {
  void execute(CPU& cpu) const {
    cpu.inc_ip(); // ModR/M

    auto modrm = cpu.get_mem_byte();
    cpu.inc_ip(); // Next opcode or displacement

    std::uint8_t mod, rm_a, rm_b;
    std::tie(mod, rm_a, rm_b) = utils::get_modrm(modrm);

    switch (mod) {
      case 0b00: {
        auto value_a = cpu.get_reg_value_16(rm_a);
        auto value_b = cpu.get_mem_value(rm_b);
        cpu.set_reg_value_16(rm_a, value_a ^ value_b);
        break;
      }
      case 0b01: {
        auto disp = cpu.get_mem_byte();
        cpu.inc_ip();
        auto value_a = cpu.get_reg_value_16(rm_a);
        auto value_b = cpu.get_mem_value(rm_b, disp);
        cpu.set_reg_value_16(rm_a, value_a ^ value_b);
        break;
      }
      case 0b10: {
        auto disp = cpu.get_mem_word();
        cpu.inc_ip();
        cpu.inc_ip();
        auto value_a = cpu.get_reg_value_16(rm_a);
        auto value_b = cpu.get_mem_value(rm_b, disp);
        cpu.set_reg_value_16(rm_a, value_a ^ value_b);
        break;
      }
      case 0b11: {
        auto value_a = cpu.get_reg_value_16(rm_a);
        auto value_b = cpu.get_reg_value_16(rm_b);
        cpu.set_reg_value_16(rm_a, value_a ^ value_b);
        break;
      }
      default:
        utils::die("Unexpected mode");
        break;
    }
  }
};


/**
 * Opcode: 32
 * Instruction: XOR r8 r/m8
 */
export
class Xor32Instruction : public Instruction {
public:
  void execute(CPU& cpu) const {
    cpu.inc_ip(); // ModR/M

    auto modrm = cpu.get_mem_byte();
    cpu.inc_ip(); // Next opcode or displacement

    std::uint8_t mod, rm_a, rm_b;
    std::tie(mod, rm_a, rm_b) = utils::get_modrm(modrm);

    switch (mod) {
      case 0b00: {
        auto value_a = cpu.get_reg_value_8(rm_a);
        auto value_b = cpu.get_mem_value(rm_b);
        cpu.set_reg_value_8(rm_a, value_a ^ value_b);
        break;
      }
      case 0b01: {
        auto disp = cpu.get_mem_byte();
        cpu.inc_ip();
        auto value_a = cpu.get_reg_value_8(rm_a);
        auto value_b = cpu.get_mem_value(rm_b, disp);
        cpu.set_reg_value_8(rm_a, value_a ^ value_b);
        break;
      }
      case 0b10: {
        auto disp = cpu.get_mem_word();
        cpu.inc_ip();
        cpu.inc_ip();
        auto value_a = cpu.get_reg_value_8(rm_a);
        auto value_b = cpu.get_mem_value(rm_b, disp);
        cpu.set_reg_value_8(rm_a, value_a ^ value_b);
        break;
      }
      case 0b11: {
        auto value_a = cpu.get_reg_value_8(rm_a);
        auto value_b = cpu.get_reg_value_8(rm_b);
        cpu.set_reg_value_8(rm_a, value_a ^ value_b);
        break;
      }
      default:
        utils::die("Unexpected mode");
        break;
    }
  }
};

}
