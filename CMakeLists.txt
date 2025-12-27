cmake_minimum_required(VERSION 3.10)
project(Lab03)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
  TLS_VERIFY false
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Включаем директории
include_directories(include)

# Все исходные файлы
set(SOURCES
    src/trapezoid.cpp
    src/rhombus.cpp
    src/pentagon.cpp
    src/array.cpp
)

# Основная программа
add_executable(${CMAKE_PROJECT_NAME} 
    src/main.cpp
    ${SOURCES}
)

enable_testing()

# Тесты
add_executable(tests 
    tests/test.cpp
    ${SOURCES}
)
target_link_libraries(tests gtest_main)

add_test(NAME AllTests COMMAND tests)