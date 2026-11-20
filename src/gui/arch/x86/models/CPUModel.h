#pragma once
#include <cstdint>

#include <QObject>
#include <QtQml>
#include <QPointer>

namespace arch::x86 { class CPU; }

namespace gui::models {

class CPUModel : public QObject {
  Q_OBJECT
  QML_ELEMENT

  Q_PROPERTY(std::uint32_t eax READ eax WRITE setEax NOTIFY eaxChanged)
  Q_PROPERTY(std::uint32_t ebx READ ebx WRITE setEbx NOTIFY ebxChanged)
  Q_PROPERTY(std::uint32_t ecx READ ecx WRITE setEcx NOTIFY ecxChanged)
  Q_PROPERTY(std::uint32_t edx READ edx WRITE setEdx NOTIFY edxChanged)

  Q_PROPERTY(std::uint32_t esi READ esi WRITE setEsi NOTIFY esiChanged)
  Q_PROPERTY(std::uint32_t edi READ edi WRITE setEdi NOTIFY ediChanged)
  Q_PROPERTY(std::uint32_t ebp READ ebp WRITE setEbp NOTIFY ebpChanged)
  Q_PROPERTY(std::uint32_t esp READ esp WRITE setEsp NOTIFY espChanged)

  Q_PROPERTY(std::uint16_t cs READ cs WRITE setCs NOTIFY csChanged)
  Q_PROPERTY(std::uint16_t ds READ ds WRITE setDs NOTIFY dsChanged)
  Q_PROPERTY(std::uint16_t ss READ ss WRITE setSs NOTIFY ssChanged)
  Q_PROPERTY(std::uint16_t es READ es WRITE setEs NOTIFY esChanged)
  Q_PROPERTY(std::uint16_t fs READ fs WRITE setFs NOTIFY fsChanged)
  Q_PROPERTY(std::uint16_t gs READ gs WRITE setGs NOTIFY gsChanged)

public:
  CPUModel(QObject *parent = nullptr);
  CPUModel(const CPUModel&) = delete;
  CPUModel(CPUModel&&) = delete;
  CPUModel& operator=(const CPUModel&) = delete;
  CPUModel& operator=(CPUModel&&) = delete;
  ~CPUModel() override;


  [[nodiscard]] std::uint32_t eax() const;
  void setEax(std::uint32_t v);

  [[nodiscard]] std::uint32_t ebx() const;
  void setEbx(std::uint32_t v);

  [[nodiscard]] std::uint32_t ecx() const;
  void setEcx(std::uint32_t v);

  [[nodiscard]] std::uint32_t edx() const;
  void setEdx(std::uint32_t v);


  [[nodiscard]] std::uint32_t esi() const;
  void setEsi(std::uint32_t v);

  [[nodiscard]] std::uint32_t edi() const;
  void setEdi(std::uint32_t v);

  [[nodiscard]] std::uint32_t ebp() const;
  void setEbp(std::uint32_t v);

  [[nodiscard]] std::uint32_t esp() const;
  void setEsp(std::uint32_t v);


  [[nodiscard]] std::uint16_t cs() const;
  void setCs(std::uint16_t v);

  [[nodiscard]] std::uint16_t ds() const;
  void setDs(std::uint16_t v);

  [[nodiscard]] std::uint16_t ss() const;
  void setSs(std::uint16_t v);

  [[nodiscard]] std::uint16_t es() const;
  void setEs(std::uint16_t v);

  [[nodiscard]] std::uint16_t fs() const;
  void setFs(std::uint16_t v);

  [[nodiscard]] std::uint16_t gs() const;
  void setGs(std::uint16_t v);


  arch::x86::CPU& cpu();

  Q_INVOKABLE void tick();

signals:
  void eaxChanged(std::uint32_t value);
  void ebxChanged(std::uint32_t value);
  void ecxChanged(std::uint32_t value);
  void edxChanged(std::uint32_t value);

  void esiChanged(std::uint32_t value);
  void ediChanged(std::uint32_t value);
  void ebpChanged(std::uint32_t value);
  void espChanged(std::uint32_t value);

  void csChanged(std::uint16_t value);
  void dsChanged(std::uint16_t value);
  void ssChanged(std::uint16_t value);
  void esChanged(std::uint16_t value);
  void fsChanged(std::uint16_t value);
  void gsChanged(std::uint16_t value);

private:
  std::unique_ptr<arch::x86::CPU> _cpu;
};

}

