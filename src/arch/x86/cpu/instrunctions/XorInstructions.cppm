module;
#include <cstdint>
export module arch.x86.xor_instructions;

import arch.x86.cpu;
import arch.x86.instruction;
import utils.flow;

namespace arch::x86 {

export
class Xor32Instruction : public Instruction {
public:
  void execute(CPU& cpu) const {
    cpu.inc_ip();
    auto regs = cpu.get_mem_byte();
    auto mod = regs >> 6;
    switch (mod) {
      case 0b11: {
        auto reg_a = (regs >> 3) & 0b111;
        auto reg_b = regs & 0b111;
        auto value_a = get_reg_value(cpu, reg_a);
        auto value_b = get_reg_value(cpu, reg_b);
        set_reg_value(cpu, reg_a, value_a ^ value_b);
        break;
      }
      default:
        utils::die("Unexpected mode");
        break;
    }
  }

private:
  static std::uint8_t get_reg_value(const CPU& cpu, std::uint8_t reg) {
    switch (reg) {
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

  static void set_reg_value(CPU& cpu, std::uint8_t reg, std::uint8_t value) {
    switch (reg) {
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
};

}
