cmake_minimum_required(VERSION 3.22) # Проверка версии CMake.
									# Если версия установленой программы
									# старее указаной, произайдёт аварийный выход.

project(solver)				# Название проекта

set(SOURCE_EXE equation.cpp)			# Установка переменной со списком исходников

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../formatter_ex_lib/"
					"${CMAKE_CURRENT_SOURCE_DIR}/../solver_lib/")

add_executable(main ${SOURCE_EXE})	# Создает исполняемый файл с именем main

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../formatter_ex_lib/ formatter_ex_lib)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../solver_lib/ solver_lib)

target_link_libraries(main formatter_ex_lib solver_lib)		# Линковка программы с библиотекой
