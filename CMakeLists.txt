cmake_minimum_required(VERSION 3.6)
project(Cshell)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")

set(SOURCE_FILES
        cshell.h
        cshell.l
        CSM.h
        CSM_dev.h
        DBG.h
        create.c
        execute.c
        cshell.c
        MEM.h
        MEM/mem.h
        MEM/memory.c
        MEM/manage.h
        MEM/manage.c string.c errors.h errors.c string.h)
set(MEM_SRC_FILES
        MEM.h
		MEM/manage.c
        MEM/memory.c
        MEM/test.c)

set(LEX_ANALYSISER_TEST_FILE
		${MEM_SRC_FILES}
		expression.h
		create.c
		)

add_executable(Cshell ${SOURCE_FILES} string.c errors.h errors.c string.h)
add_executable(MEM ${MEM_SRC_FILES})