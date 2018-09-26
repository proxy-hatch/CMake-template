# this is a good place to start with CMake! https://youtu.be/bsXLMQ6WgIk
cmake_minimum_required(VERSION 3.5)
project(A208Handler)
include(GNUInstallDirs)

set(CMAKE_PREFIX_PATH "rs232")

# the boilerplate that handles it all:
#System package: either finds FooConfig.cmake in the system or uses FindFoo.cmake to find the lib in system
#Prebuilt lib: either finds FooConfig.cmake in the CMAKE_PREFIX_PATH or use FindFoo.cmake to find the lib in CMAKE_PREFIX_PATH
#Subproject: find_package (Foo) does nothing, as Foo::Foo is a part of the proj
set(as_subproject rs232)
macro(find_package)
	if (NOT "${ARGV0}" IN_LIST as_subproject)
		_find_package(${ARGV})
	endif ()
endmacro()
find_package(rs232)


add_subdirectory(rs232)
add_subdirectory(app)

