project(TP1)

set(CMAKE_C_FLAGS, '-Wall -Wextra -ansi -pedantic')

add_executable(
        tp1
        agenda.c
        agenda.h
        main.c
        action.c action.h list.c list.h helper.h parser.h parser.c controller.c controller.h)