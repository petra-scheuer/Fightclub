cmake_minimum_required(VERSION 3.27)
project(FightClub_SCHEUER)

set(CMAKE_CXX_STANDARD 17)

add_executable(FightClub_SCHEUER main.cpp
        Game.cpp
        Game.h
        Charakter.cpp
        Charakter.h
        Player.cpp
        Player.h
        Header.h
        Enemy.cpp
        Enemy.h
        Spielfiguren.cpp
        Spielfiguren.h
        ICombatant.cpp
        ICombatant.h)
