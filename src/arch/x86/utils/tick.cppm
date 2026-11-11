export module arch.x86.utils;

import arch.x86.cpu;
import arch.x86.instruction;

namespace arch::x86 {

export
void tick(CPU& cpu, const Instruction& instruction) {
  instruction.execute(cpu);
}

}
