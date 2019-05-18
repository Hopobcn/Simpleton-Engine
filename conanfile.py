from conans import ConanFile, CMake, tools


class SimpletonConan(ConanFile):
    name = "simpleton"
    version = "0.1.0"
    license = "MIT License"
    description = "A collection of utility classes to make videogames packed into a library"
    topics = ("game dev", "ecs", "conan", "cpp")
    url = "https://github.com/Hopobcn/Simpleton-Engine"
    author = "Indi Kernichk"
    exports = ["LICENSE"]
    exports_sources = ["Simpleton/*"]
    no_copy_source = True
    generators = "cmake"

    # No settings/options are necessary, this is header only

    requires = (
                 "entt/3.0.0@skypjack/stable",
                 "glm/0.9.9.4@g-truc/stable",
                 "libpng/1.6.37@bincrafters/stable",
                 "jsonformoderncpp/3.6.1@vthiery/stable",
                 "glew/2.1.0@bincrafters/stable",
                 "sdl2/2.0.9@bincrafters/stable",
                 "sdl2_ttf/2.0.15@bincrafters/stable"
               )
    build_requires = ( "cmake_installer/3.12.4@conan/stable" )

    def package(self):
        self.copy(pattern="LICENSE", dst="licenses")
        self.copy(pattern="*", dst="include")

    def package_id(self):
        self.info.header_only()