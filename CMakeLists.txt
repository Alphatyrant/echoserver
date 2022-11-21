cmake_minimum_required(VERSION 3.9)

project(echoserver C)

# Exibindo dados de compilacao
message ( " => Processando ${CMAKE_CURRENT_BINARY_DIR}")
message ( " => Compilador: ${CMAKE_C_COMPILER}")
message ( " => Fonte:      ${PROJECT_SOURCE_DIR}" ) 
message ( " => Binary:     ${PROJECT_BINARY_DIR}/build" )
message ( " => Library:    ${CMAKE_SOURCE_DIR}/lib" )

# Definição dos arquivos
set(SOURCE_FILES
    src/echoserver_loop.c
    src/echoserver_main.c
)

# Executavel
add_executable(echoserver ${SOURCE_FILES})
set_target_properties(echoserver PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/build")

# Target include always after add_executable
target_include_directories(echoserver
    PUBLIC 
        inc/
)

# Add a custom target to make run
add_custom_target(run
    COMMAND echoserver
    DEPENDS echoserver
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/build
)