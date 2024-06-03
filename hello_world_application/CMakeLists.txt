cmake_minimum_required(VERSION 3.20)
project(hello_world)				 # Название проекта

set(SOURCE_EXE hello_world.cpp)			 # Установка переменной со списком исходников

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../formatter_ex_lib/)

add_executable(main ${SOURCE_EXE})	 # Создает исполняемый файл с именем main

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../formatter_ex_lib/ formatter_ex_lib)

target_link_libraries(main formatter_ex_lib)
