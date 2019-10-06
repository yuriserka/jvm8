#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_BASE_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_BASE_H_

#include <string>
#include <vector>
#include "utils/types.h"

namespace Instructions {
class Instruction {
 public:
  explicit Instruction(const Utils::Types::u1 &op) : opcode{op} {}

  virtual ~Instruction() = default;

  // virtual void execute() = 0;
  virtual int toBytecode(std::vector<Utils::Types::u1>::iterator *, int *,
                         const bool &) = 0;

  virtual std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *, int *, int *,
      const bool &) = 0;

  const Utils::Types::u1 opcode;
};
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_BASE_H_
