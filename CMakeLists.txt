cmake_minimum_required(VERSION 3.20)
project(projekat)

set(CMAKE_CXX_STANDARD 17)

add_executable(projekat main.cpp Datum.cpp Datum.h Knjiga.cpp Knjiga.h Biblioteka.cpp Biblioteka.h Admin.cpp Admin.h Clan.cpp Clan.h Zaduzenje.cpp Zaduzenje.h)
