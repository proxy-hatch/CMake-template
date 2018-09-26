project(rs232)
include(GNUInstallDirs)

add_library(${PROJECT_NAME}
    src/rs232.c
	)
add_library(rs232:rs232 ALIAS ${PROJECT_NAME})


# Define headers for this library. PUBLIC headers are used for
# compiling the library, and will be added to consumers' build
# paths.
# Install dir '${CMAKE_CURRENT_SOURCE_DIR}/include' already includes the .h file for this lib.
target_include_directories(rs232 PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/rs232>
	$<INSTALL_INTERFACE:include>
	PRIVATE src
)

# 'make install' to the correct locations (provided by GNUInstallDirs).
install(TARGETS rs232 EXPORT rs232Config
	LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
#    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR}    # This is for Windows to generate .dll
	INCLUDES DESTINATION include
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
# just go into 'cmake'.
install(EXPORT rs232Config DESTINATION lib/cmake/rs232)

