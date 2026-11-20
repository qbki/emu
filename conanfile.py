from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMakeDeps, cmake_layout
from conan.tools.env import VirtualRunEnv

class App(ConanFile):
  name = "qbki-emu"
  version = "0.0.1"
  settings = "os", "compiler", "build_type", "arch"

  default_options = {
    "qt/*:qtdeclarative": True,
    "qt/*:qtlanguageserver": True,
    "qt/*:qtshadertools": True,
    "qt/*:qttools": True,
    "qt/*:qttranslations": True,
    "qt/*:qtwayland": True,
    "qt/*:shared": True,
    "qt/*:widgets": False,
    "qt/*:with_egl": True,
    "qt/*:with_icu": True,
    "qt/*:with_md4c": False,
    "qt/*:with_mysql": False,
    "qt/*:with_odbc": False,
    "qt/*:with_pq": False,
    "qt/*:with_sqlite3": False,
    "qt/*:with_vulkan": True,
    "qt/*:with_x11": True,
  }


  def requirements(self):
    self.requires("qt/6.12.0")


  def layout(self):
    cmake_layout(self)


  def generate(self):
    tc = CMakeToolchain(self)
    tc.user_presets_path = 'ConanPresets.json'
    tc.generate()
    deps = CMakeDeps(self)
    deps.generate()
    # Example `$ source ./build/Release/generators/conanrun.sh`
    ms = VirtualRunEnv(self)
    ms.generate()
