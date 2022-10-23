cmake_minimum_required(VERSION 3.2)
project(ip_filter VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

configure_file(version.h.in version.h)

add_executable(ip_filter_cli main.cpp)
add_library(ip_filter filtr_ip_lib.cpp)

set_target_properties(ip_filter_cli ip_filter_test PROPERTIES
	COMPILE_OPTIONS -Wpedantic -Wall -Wextra
	CMAKE_CXX_STANDARD 17
	CMAKE_CXX_STANDARD_REQUIRED ON
)

set(CMAKE_CXX_FLAGS "-std=c++1z")

target_link_libraries(ip_filter_cli
	ip_filter
)

install(TARGETS ip_filter_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT Alttaira@yandex.ru)

include(CPack)

enable_testing()

add_test(ip_filter_test ip_filter_test)
