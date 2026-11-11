module;
#include <algorithm>
#include <functional>
#include <memory>
export module utils.events;

namespace utils {

export
template<typename T>
class Events {
public:
  using Fn = std::shared_ptr<std::function<void(T)>>;


  void add(Fn fn) {
    _fns.push_back(std::move(fn));
  }


  void emit(T value) {
    for (auto& fn : _fns) {
      (*fn)(value);
    }
  }


  void remove(const Fn& fn) {
    auto begin = std::remove(_fns.begin(), _fns.end(), fn);
    _fns.erase(begin, _fns.end());
  }

private:
  std::vector<Fn> _fns;
};

}
