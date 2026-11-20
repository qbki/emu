qbki-emu
========

x86 emulator.


Build
-----

```sh
$ conan install . --profile=./configs/profiles/x64-linux-rel -pr:b=./configs/profiles/x64-linux-rel --lockfile=conan.lock --build=missing
$ conan install . --profile=./configs/profiles/x64-linux-deb -pr:b=./configs/profiles/x64-linux-deb --lockfile=conan.lock --build=missing -s build_type=Debug
$ cmake --preset x64-linux-release
$ cmake --build --preset x64-linux-release
```


License
-------

[MIT](./LICENSE)
