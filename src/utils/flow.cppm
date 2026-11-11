module;
#include <cstdio>
#include <cstdlib>
#include <print>
#include <string>
export module utils.flow;

namespace utils {
  export
  [[noreturn]]
  void die(const std::string& message) {
    std::println(stderr, "Unexpected error: {}", message);
    exit(1);
  }
}
