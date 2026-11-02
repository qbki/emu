from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMakeDeps, cmake_layout
from conan.tools.env import VirtualRunEnv

class App(ConanFile):
  name = "qbki-emu"
  version = "0.0.1"
  settings = "os", "compiler", "build_type", "arch"


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
