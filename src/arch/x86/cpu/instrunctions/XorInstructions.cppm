module;
#include <cstdint>
export module arch.x86.xor_instructions;

import arch.x86.cpu;
import arch.x86.instruction;
import utils.flow;

namespace arch::x86 {

/**
 * Opcode: 32
 * Instruction: XOR r8 r/m8
 */
export
class Xor32Instruction : public Instruction {
public:
  void execute(CPU& cpu) const {
    cpu.inc_ip(); // opcode

    auto regs = cpu.get_mem_byte();
    cpu.inc_ip(); // ModR/M

    auto mod = regs >> 6;
    auto rm_a = (regs >> 3) & 0b111;
    auto rm_b = regs & 0b111;

    switch (mod) {
      case 0b00: {
        auto value_a = get_reg_value(cpu, rm_a);
        auto value_b = get_mem_value(cpu, rm_b);
        set_reg_value(cpu, rm_a, value_a ^ value_b);
        break;
      }
      case 0b01: {
        auto disp = cpu.get_mem_byte();
        cpu.inc_ip();
        auto value_a = get_reg_value(cpu, rm_a);
        auto value_b = get_mem_value(cpu, rm_b, disp);
        set_reg_value(cpu, rm_a, value_a ^ value_b);
        break;
      }
      case 0b10: {
        auto disp = cpu.get_mem_word();
        cpu.inc_ip();
        cpu.inc_ip();
        auto value_a = get_reg_value(cpu, rm_a);
        auto value_b = get_mem_value(cpu, rm_b, disp);
        set_reg_value(cpu, rm_a, value_a ^ value_b);
        break;
      }
      case 0b11: {
        auto value_a = get_reg_value(cpu, rm_a);
        auto value_b = get_reg_value(cpu, rm_b);
        set_reg_value(cpu, rm_a, value_a ^ value_b);
        break;
      }
      default:
        utils::die("Unexpected mode");
        break;
    }
  }

private:
  static std::uint8_t get_reg_value(const CPU& cpu, std::uint8_t rm) {
    switch (rm) {
      case 0b000: return cpu.al();
      case 0b001: return cpu.cl();
      case 0b010: return cpu.dl();
      case 0b011: return cpu.bl();
      case 0b100: return cpu.ah();
      case 0b101: return cpu.ch();
      case 0b110: return cpu.dh();
      case 0b111: return cpu.bh();
      default: utils::die("Unexpected register"); break;
    }
  }


  static void set_reg_value(CPU& cpu, std::uint8_t rm, std::uint8_t value) {
    switch (rm) {
      case 0b000: cpu.al(value); break;
      case 0b001: cpu.cl(value); break;
      case 0b010: cpu.dl(value); break;
      case 0b011: cpu.bl(value); break;
      case 0b100: cpu.ah(value); break;
      case 0b101: cpu.ch(value); break;
      case 0b110: cpu.dh(value); break;
      case 0b111: cpu.bh(value); break;
      default: utils::die("Unexpected register"); break;
    }
  }


  static std::uint8_t get_mem_value(const CPU& cpu, std::uint8_t rm, int disp = 0) {
    switch (rm) {
      case 0b000: return cpu.peek(cpu.bx() + cpu.si() + disp);
      case 0b001: return cpu.peek(cpu.bx() + cpu.di() + disp);
      case 0b010: return cpu.peek(cpu.bp() + cpu.si() + disp);
      case 0b011: return cpu.peek(cpu.bp() + cpu.di() + disp);
      case 0b100: return cpu.peek(cpu.si() + disp);
      case 0b101: return cpu.peek(cpu.di() + disp);
      case 0b110: return cpu.peek(cpu.bp() + disp);
      case 0b111: return cpu.peek(cpu.bx() + disp);
      default: utils::die("Unexpected memory access"); break;
    }
  }
};

}
