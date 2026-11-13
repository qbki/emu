module;
#include <cstdint>
#include <tuple>
export module utils.cpu;

namespace utils {

export
std::tuple<std::uint8_t, std::uint8_t, std::uint8_t>
get_modrm(std::uint8_t value) {
  const auto mod = value >> 6;
  const auto rm_a = (value >> 3) & 0b111;
  const auto rm_b = value & 0b111;
  return {mod, rm_a, rm_b};
}

}
