cmake_minimum_required(VERSION 3.22) # Проверка версии CMake.
									# Если версия установленой программы
									# старее указаной, произайдёт аварийный выход.

project(solver_lib)				# Название проекта

set(SOURCE_LIB solver.cpp solver.h)		# Установка переменной со списком исходников

add_library(solver_lib STATIC ${SOURCE_LIB})# Создание статической библиотеки
