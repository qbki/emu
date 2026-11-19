module;
#include <cstdint>
#include <vector>
export module arch.x86.cpu;

import utils.setter;
import utils.flow;

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


  std::uint32_t esp() const { return _esp.get(); }
  void esp(std::uint32_t value) { _esp.set(value); }

  std::uint16_t sp() const { return static_cast<std::uint16_t>(_esp.get()); }
  void sp(std::uint16_t value) { _esp.set(value); }


  std::uint32_t ebp() const { return _ebp.get(); }
  void ebp(std::uint32_t value) { _ebp.set(value); }

  std::uint16_t bp() const { return static_cast<std::uint16_t>(_ebp.get()); }
  void bp(std::uint16_t value) { _ebp.set(value); }


  std::uint32_t esi() const { return _esi.get(); }
  void esi(std::uint32_t value) { _esi.set(value); }

  std::uint16_t si() const { return static_cast<std::uint16_t>(_esi.get()); }
  void si(std::uint16_t value) { _esi.set(value); }


  std::uint32_t edi() const { return _edi.get(); }
  void edi(std::uint32_t value) { _edi.set(value); }

  std::uint16_t di() const { return static_cast<std::uint16_t>(_edi.get()); }
  void di(std::uint16_t value) { _edi.set(value); }


  std::uint32_t ip() { return _ip.get(); };
  void inc_ip() { _ip.set(_ip.get() + 1); }
  std::uint8_t get_mem_byte() const { return _memory.at(_ip.get()); }
  std::uint16_t get_mem_word() const {
    auto lo = _memory.at(_ip.get());
    auto hi = _memory.at(_ip.get() + 1);
    return (hi << 8) | lo;
  }


  std::vector<std::uint8_t>& memory() { return _memory; }
  void memory(const std::vector<std::uint8_t>& value) { _memory = value; }


  std::uint8_t peek(uint32_t address) const { return _memory.at(address); }


  std::uint8_t get_reg_value_8(std::uint8_t rm) const {
    switch (rm) {
      case 0b000: return al();
      case 0b001: return cl();
      case 0b010: return dl();
      case 0b011: return bl();
      case 0b100: return ah();
      case 0b101: return ch();
      case 0b110: return dh();
      case 0b111: return bh();
      default: utils::die("Unexpected register"); break;
    }
  }


  void set_reg_value_8(std::uint8_t rm, std::uint8_t value) {
    switch (rm) {
      case 0b000: al(value); break;
      case 0b001: cl(value); break;
      case 0b010: dl(value); break;
      case 0b011: bl(value); break;
      case 0b100: ah(value); break;
      case 0b101: ch(value); break;
      case 0b110: dh(value); break;
      case 0b111: bh(value); break;
      default: utils::die("Unexpected register"); break;
    }
  }


  std::uint16_t get_reg_value_16(std::uint8_t rm) const {
    switch (rm) {
      case 0b000: return ax();
      case 0b001: return cx();
      case 0b010: return dx();
      case 0b011: return bx();
      case 0b100: return sp();
      case 0b101: return bp();
      case 0b110: return si();
      case 0b111: return di();
      default: utils::die("Unexpected register"); break;
    }
  }


  void set_reg_value_16(std::uint8_t rm, std::uint16_t value) {
    switch (rm) {
      case 0b000: ax(value); break;
      case 0b001: cx(value); break;
      case 0b010: dx(value); break;
      case 0b011: bx(value); break;
      case 0b100: sp(value); break;
      case 0b101: bp(value); break;
      case 0b110: si(value); break;
      case 0b111: di(value); break;
      default: utils::die("Unexpected register"); break;
    }
  }


  std::uint8_t get_mem_value(std::uint8_t rm, int disp = 0) {
    switch (rm) {
      case 0b000: return peek(bx() + si() + disp);
      case 0b001: return peek(bx() + di() + disp);
      case 0b010: return peek(bp() + si() + disp);
      case 0b011: return peek(bp() + di() + disp);
      case 0b100: return peek(si() + disp);
      case 0b101: return peek(di() + disp);
      case 0b110: return peek(bp() + disp);
      case 0b111: return peek(bx() + disp);
      default: utils::die("Unexpected memory access"); break;
    }
  }


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
