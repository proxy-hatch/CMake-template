# CMake-template
Modern CMake template in conjunction with CLion

Avoided many of the bad practices includding globbing files, manually setting C/C++ versions with `CMAKE_CXX_FLAGS`, and using questionable compiler flags like `-Werror`, `include_directories()`, etc.

### Compiling
##### CLion
Simply click the "Reload CMake Project" button to generate makefiles, and "Build" button to generate executable
##### Command Line
- navitage to your `cd ./cmake-build-debug/` directory
- `cmake -G` displays your generator options. You most likely want `Unix Makefiles`
- clear the directory and run CMake pointing it to the root directory: `rm -rf *; cmake -G "Unix Makefiles" ..`
- Now you're ready to build! `make` will output your app to the corresponding directory tree `../root/cmake-build-debug/app/A208Handler`

### References
* Daniel Pfeifer’s C++Now 2017 talk [Effective CMake](https://github.com/boostcon/cppnow_presentations_2017/blob/master/05-19-2017_friday/effective_cmake__daniel_pfeifer__cppnow_05-19-2017.pdf) ([video](https://youtu.be/bsXLMQ6WgIk))
* So, so many things collected in [onqtam/awesome-cmake](https://github.com/onqtam/awesome-cmake)
* And [some](https://rix0r.nl/blog/2015/08/13/cmake-guide/) [examples](https://pabloariasal.github.io/2018/02/19/its-time-to-do-cmake-right/)
