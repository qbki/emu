#include <memory>
#include <print>
#include <unordered_map>

import arch.x86.cpu;
import arch.x86.instruction;
import arch.x86.xor_instructions;
import arch.x86.mov_instructions;
import arch.x86.utils;

int main() {
  using namespace arch::x86;

  std::unordered_map<std::uint32_t, std::unique_ptr<Instruction>> opcode_mapping {};
  opcode_mapping.insert({0x80, std::make_unique<Mov80Instruction>()});
  opcode_mapping.insert({0x32, std::make_unique<Xor32Instruction>()});

  CPU cpu {};
  cpu.memory({0x80, 42, 0x32, 0x04, 42});
  cpu.si(4);

  std::println("{}", cpu.al());

  while (true) {
    auto opcode = cpu.get_mem_byte();
    if (opcode_mapping.contains(opcode)) {
      tick(cpu, *(opcode_mapping.at(opcode)));
    } else {
      break;
    }
  }

  std::println("{}", cpu.al());

  return 0;
}
