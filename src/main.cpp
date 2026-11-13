#include <print>

import arch.x86.cpu;
import arch.x86.xor_instructions;
import arch.x86.mov_instructions;
import arch.x86.utils;

int main() {
  using namespace arch::x86;

  CPU cpu {};
  cpu.memory({0x80, 42, 0x32, 0x04, 42});
  cpu.si(4);

  std::println("{}", cpu.al());

  Mov80Instruction instruction_mov {};
  tick(cpu, instruction_mov);

  std::println("{}", cpu.al());

  Xor32Instruction instruction_xor {};
  tick(cpu, instruction_xor);

  std::println("{}", cpu.al());

  return 0;
}
