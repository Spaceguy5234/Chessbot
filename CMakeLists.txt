cmake_minimum_required(VERSION 3.15...4.0)
project(Chessbot VERSION 0.1.0 
        DESCRIPTION "A really bad chessbot for learning lol"
        LANGUAGES CXX)

add_executable(Chessbot src/chessbot.cpp include/board.cpp include/board.hpp include/piece.cpp include/piece.hpp)
target_include_directories(Chessbot PUBLIC include)