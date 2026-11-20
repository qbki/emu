module;
#include <memory>
#include <unordered_map>
export module arch.x86.utils.tick;

import arch.x86.cpu;
import arch.x86.instruction;
import arch.x86.mov_instructions;
import arch.x86.xor_instructions;

namespace arch::x86 {

std::unordered_map<std::uint32_t, std::unique_ptr<Instruction>> get_instructions() {
  std::unordered_map<std::uint32_t, std::unique_ptr<Instruction>> opcode_mapping {};
  opcode_mapping.insert({0x80, std::make_unique<Mov80Instruction>()});
  opcode_mapping.insert({0x31, std::make_unique<Xor31Instruction>()});
  opcode_mapping.insert({0x32, std::make_unique<Xor32Instruction>()});
  return opcode_mapping;
}


export
void tick(CPU& cpu) {
  static auto opcode_mapping = get_instructions();

  auto opcode = cpu.get_mem_byte();
  if (opcode_mapping.contains(opcode)) {
    opcode_mapping.at(opcode)->execute(cpu);
  }
}

}
