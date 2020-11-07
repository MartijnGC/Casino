cmake_minimum_required(VERSION 3.17)
project(Casino)

set(CMAKE_CXX_STANDARD 14)

add_executable(Casino main.cpp Deck.cpp Deck.h Card.cpp Card.h Blackjack.cpp Blackjack.h)
