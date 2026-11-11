export module utils.setter;

import utils.events;

namespace utils {

export
template<typename T>
class Setter {
public:
  void set(T value) {
    if (value == _value) {
      return;
    }
    _value = value;
    _events.emit(_value);
  }


  T get() const {
    return _value;
  }


private:
  T _value {0};
  Events<T> _events;
};

}
