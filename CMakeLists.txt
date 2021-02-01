cmake_minimum_required(VERSION 3.10)

include_directories(${CMAKE_CURRENT_LIST_DIR})

add_executable(myApp ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/atom_set.hpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/valuation.cpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/valuation.hpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/base_formula.cpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/base_formula.hpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/atomic_formula.cpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/atomic_formula.hpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/constant.cpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/constant.hpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/unary_connective.cpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/unary_connective.hpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/not.cpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/not.hpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/binary_connective.cpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/binary_connective.hpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/and.cpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/and.hpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/or.cpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/or.hpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/iff.cpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/iff.hpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/imp.cpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/imp.hpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/atom.cpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/atom.hpp
                 ${CMAKE_CURRENT_LIST_DIR}/src/propositional_logic.hpp)
