cmake_minimum_required(VERSION 3.14)
project(Filler C)

set(NAME fsmith.filler)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

include_directories(includes)
include_directories(lib/libft/includes)
add_subdirectory(lib/libft)

set(FILLER_INC includes/filler.h)

set(FILLER_SRC src/main.c)

add_executable(NAME ${FILLER_INC} ${FILLER_SRC})

target_link_libraries(NAME libft)
