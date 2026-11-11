#include <print>

import arch.x86.cpu;
import arch.x86.xor_instructions;
import arch.x86.utils;

int main() {
  using namespace arch::x86;

  CPU cpu {};
  cpu.memory({0x32, 0xc0});
  cpu.eax(43);

  Xor32Instruction instruction {};
  tick(cpu, instruction);

  std::println("{}", cpu.eax());
  return 0;
}
