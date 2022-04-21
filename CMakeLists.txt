cmake_minimum_required(VERSION 3.21)
project(Lab_8_tema_bun2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab_8_tema_bun2 main.cpp Domain/Expense.cpp Domain/Expense.h Menu/menu.h Menu/menu.cpp Repo/Repo.cpp Repo/Repo.h Service/Service.cpp Service/Service.h UI/UI.cpp UI/UI.h Tests/tests.h Tests/tests.cpp)
