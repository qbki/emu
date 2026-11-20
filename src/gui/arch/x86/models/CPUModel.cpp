#include "CPUModel.h"
#include <memory>

import arch.x86.cpu;
import arch.x86.utils.tick;
import utils.events;

namespace gui::models {

CPUModel::CPUModel(QObject *parent)
  : QObject(parent)
  , _cpu(std::make_unique<arch::x86::CPU>())
{
  _cpu->memory({0x80, 42, 0x32, 0x04, 42});
  _cpu->si(4);

  auto eax_fn = std::make_shared<std::function<void(std::uint32_t)>>(
    [this](auto value) { this->eaxChanged(value); }
  );
  _cpu->setter_eax().add(eax_fn);

  auto ebx_fn = std::make_shared<std::function<void(std::uint32_t)>>(
    [this](auto value) { this->ebxChanged(value); }
  );
  _cpu->setter_ebx().add(ebx_fn);

  auto ecx_fn = std::make_shared<std::function<void(std::uint32_t)>>(
    [this](auto value) { this->ecxChanged(value); }
  );
  _cpu->setter_ecx().add(ecx_fn);

  auto edx_fn = std::make_shared<std::function<void(std::uint32_t)>>(
    [this](auto value) { this->edxChanged(value); }
  );
  _cpu->setter_edx().add(edx_fn);

  auto esi_fn = std::make_shared<std::function<void(std::uint32_t)>>(
    [this](auto value) { this->esiChanged(value); }
  );
  _cpu->setter_esi().add(esi_fn);

  auto edi_fn = std::make_shared<std::function<void(std::uint32_t)>>(
    [this](auto value) { this->ediChanged(value); }
  );
  _cpu->setter_edi().add(edi_fn);

  auto ebp_fn = std::make_shared<std::function<void(std::uint32_t)>>(
    [this](auto value) { this->ebpChanged(value); }
  );
  _cpu->setter_ebp().add(ebp_fn);

  auto esp_fn = std::make_shared<std::function<void(std::uint32_t)>>(
    [this](auto value) { this->espChanged(value); }
  );
  _cpu->setter_esp().add(esp_fn);

  auto cs_fn = std::make_shared<std::function<void(std::uint16_t)>>(
    [this](auto value) { this->csChanged(value); }
  );
  _cpu->setter_cs().add(cs_fn);

  auto ds_fn = std::make_shared<std::function<void(std::uint16_t)>>(
    [this](auto value) { this->dsChanged(value); }
  );
  _cpu->setter_ds().add(ds_fn);

  auto ss_fn = std::make_shared<std::function<void(std::uint16_t)>>(
    [this](auto value) { this->ssChanged(value); }
  );
  _cpu->setter_ss().add(ss_fn);

  auto es_fn = std::make_shared<std::function<void(std::uint16_t)>>(
    [this](auto value) { this->esChanged(value); }
  );
  _cpu->setter_es().add(es_fn);

  auto fs_fn = std::make_shared<std::function<void(std::uint16_t)>>(
    [this](auto value) { this->fsChanged(value); }
  );
  _cpu->setter_fs().add(fs_fn);

  auto gs_fn = std::make_shared<std::function<void(std::uint16_t)>>(
    [this](auto value) { this->gsChanged(value); }
  );
  _cpu->setter_gs().add(gs_fn);
}


CPUModel::~CPUModel() {
}


std::uint32_t
CPUModel::eax() const {
  return _cpu->eax();
}


void
CPUModel::setEax(std::uint32_t value) {
  if (value == _cpu->eax()) return;
  _cpu->eax(value);
  eaxChanged(_cpu->eax());
}


std::uint32_t
CPUModel::ebx() const {
  return _cpu->ebx();
}


void
CPUModel::setEbx(std::uint32_t value) {
  if (value == _cpu->ebx()) return;
  _cpu->ebx(value);
  ebxChanged(_cpu->ebx());
}


std::uint32_t
CPUModel::ecx() const {
  return _cpu->ecx();
}


void
CPUModel::setEcx(std::uint32_t value) {
  if (value == _cpu->ecx()) return;
  _cpu->ecx(value);
  ecxChanged(_cpu->ecx());
}


std::uint32_t
CPUModel::edx() const {
  return _cpu->edx();
}


void
CPUModel::setEdx(std::uint32_t value) {
  if (value == _cpu->edx()) return;
  _cpu->edx(value);
  edxChanged(_cpu->edx());
}


std::uint32_t
CPUModel::esi() const {
  return _cpu->esi();
}


void
CPUModel::setEsi(std::uint32_t value) {
  if (value == _cpu->esi()) return;
  _cpu->esi(value);
  esiChanged(_cpu->esi());
}


std::uint32_t
CPUModel::edi() const {
  return _cpu->edi();
}


void
CPUModel::setEdi(std::uint32_t value) {
  if (value == _cpu->edi()) return;
  _cpu->edi(value);
  ediChanged(_cpu->edi());
}


std::uint32_t
CPUModel::ebp() const {
  return _cpu->ebp();
}


void
CPUModel::setEbp(std::uint32_t value) {
  if (value == _cpu->ebp()) return;
  _cpu->ebp(value);
  ebpChanged(_cpu->ebp());
}


std::uint32_t
CPUModel::esp() const {
  return _cpu->esp();
}


void
CPUModel::setEsp(std::uint32_t value) {
  if (value == _cpu->esp()) return;
  _cpu->esp(value);
  espChanged(_cpu->esp());
}


std::uint16_t
CPUModel::cs() const {
  return _cpu->cs();
}


void
CPUModel::setCs(std::uint16_t value) {
  if (value == _cpu->cs()) return;
  _cpu->cs(value);
  csChanged(_cpu->cs());
}


std::uint16_t
CPUModel::ds() const {
  return _cpu->ds();
}


void
CPUModel::setDs(std::uint16_t value) {
  if (value == _cpu->ds()) return;
  _cpu->ds(value);
  dsChanged(_cpu->ds());
}


std::uint16_t
CPUModel::ss() const {
  return _cpu->ss();
}


void
CPUModel::setSs(std::uint16_t value) {
  if (value == _cpu->ss()) return;
  _cpu->ss(value);
  ssChanged(_cpu->ss());
}


std::uint16_t
CPUModel::es() const {
  return _cpu->es();
}


void
CPUModel::setEs(std::uint16_t value) {
  if (value == _cpu->es()) return;
  _cpu->es(value);
  ssChanged(_cpu->es());
}


std::uint16_t
CPUModel::fs() const {
  return _cpu->fs();
}


void
CPUModel::setFs(std::uint16_t value) {
  if (value == _cpu->fs()) return;
  _cpu->fs(value);
  fsChanged(_cpu->fs());
}


std::uint16_t
CPUModel::gs() const {
  return _cpu->gs();
}


void
CPUModel::setGs(std::uint16_t value) {
  if (value == _cpu->gs()) return;
  _cpu->gs(value);
  gsChanged(_cpu->gs());
}


void
CPUModel::tick() {
  arch::x86::tick(*_cpu);
}

}
