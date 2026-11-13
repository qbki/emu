export module arch.x86.instruction;

import arch.x86.cpu;

namespace arch::x86 {

export
class Instruction {
public:
  Instruction() = default;
  Instruction(const Instruction&) = default;
  Instruction(Instruction&&) = delete;
  Instruction& operator=(const Instruction&) = default;
  Instruction& operator=(Instruction&&) = delete;
  virtual ~Instruction() = default;

  virtual void execute(CPU& cpu) const = 0;
};

}
