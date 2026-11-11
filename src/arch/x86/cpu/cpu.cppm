module;
#include <cstdint>
#include <vector>
export module arch.x86.cpu;

import utils.setter;

namespace arch::x86 {

export
class CPU {
public:
  std::uint32_t eax() const { return _eax.get(); }
  void eax(std::uint32_t value) { _eax.set(value); }

  std::uint16_t ax() const { return get_xs(_eax); }
  void ax(std::uint16_t value) { set_xs(_eax, value); }

  std::uint8_t ah() const { return get_hs(_eax); }
  void ah(std::uint8_t value) { set_hs(_eax, value); }

  std::uint8_t al() const { return get_ls(_eax); }
  void al(std::uint8_t value) { set_ls(_eax, value); }


  std::uint32_t ecx() const { return _ecx.get(); }
  void ecx(std::uint32_t value) { _ecx.set(value); }

  std::uint16_t cx() const { return get_xs(_ecx); }
  void cx(std::uint16_t value) { set_xs(_ecx, value); }

  std::uint8_t ch() const { return get_hs(_ecx); }
  void ch(std::uint8_t value) { set_hs(_ecx, value); }

  std::uint8_t cl() const { return get_ls(_ecx); }
  void cl(std::uint8_t value) { set_ls(_ecx, value); }


  std::uint32_t edx() const { return _edx.get(); }
  void edx(std::uint32_t value) { _edx.set(value); }

  std::uint16_t dx() const { return get_xs(_edx); }
  void dx(std::uint16_t value) { set_xs(_edx, value); }

  std::uint8_t dh() const { return get_hs(_edx); }
  void dh(std::uint8_t value) { set_hs(_edx, value); }

  std::uint8_t dl() const { return get_ls(_edx); }
  void dl(std::uint8_t value) { set_ls(_edx, value); }


  std::uint32_t ebx() const { return _ebx.get(); }
  void ebx(std::uint32_t value) { _ebx.set(value); }

  std::uint16_t bx() const { return get_xs(_ebx); }
  void bx(std::uint16_t value) { set_xs(_ebx, value); }

  std::uint8_t bh() const { return get_hs(_ebx); }
  void bh(std::uint8_t value) { set_hs(_ebx, value); }

  std::uint8_t bl() const { return get_ls(_ebx); }
  void bl(std::uint8_t value) { set_ls(_ebx, value); }


  void inc_ip() { _ip.set(_ip.get() + 1); }
  std::uint8_t get_mem_byte() const { return _memory.at(_ip.get()); }


  void memory(const std::vector<std::uint8_t>& value) { _memory = value; }


private:
  static std::uint16_t get_xs(const utils::Setter<std::uint32_t>& setter) {
    return static_cast<std::uint16_t>(setter.get());
  }

  static void set_xs(utils::Setter<std::uint32_t>& setter, std::uint16_t value) {
    setter.set((setter.get() & 0xffff0000) | value);
  }

  static std::uint8_t get_hs(const utils::Setter<std::uint32_t>& setter) {
    return static_cast<std::uint8_t>(setter.get() >> 8);
  }

  static void set_hs(utils::Setter<std::uint32_t>& setter, std::uint8_t value) {
    setter.set((setter.get() & 0xffff00ff) | (value << 8));
  }

  static std::uint8_t get_ls(const utils::Setter<std::uint32_t>& setter) {
    return static_cast<std::uint8_t>(setter.get());;
  }

  static void set_ls(utils::Setter<std::uint32_t>& setter, std::uint8_t value) {
    setter.set((setter.get() & 0xffffff00) | value);
  }

  utils::Setter<std::uint32_t> _eax;
  utils::Setter<std::uint32_t> _ebx;
  utils::Setter<std::uint32_t> _ecx;
  utils::Setter<std::uint32_t> _edx;

  utils::Setter<std::uint32_t> _esi;
  utils::Setter<std::uint32_t> _edi;
  utils::Setter<std::uint32_t> _ebp;
  utils::Setter<std::uint32_t> _esp;

  utils::Setter<std::uint16_t> _cs;
  utils::Setter<std::uint16_t> _ds;
  utils::Setter<std::uint16_t> _ss;
  utils::Setter<std::uint16_t> _es;
  utils::Setter<std::uint16_t> _fs;
  utils::Setter<std::uint16_t> _gs;

  utils::Setter<std::uint32_t> _ip;
  utils::Setter<std::uint32_t> _flags;

  std::vector<std::uint8_t> _memory {};
};

}
