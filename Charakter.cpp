//
// Created by Petra Scheuer on 11.03.24.
//

#include "Charakter.h"

void Charakter::setName(std::string Name){
    Name_=Name;
}
void Charakter::setLifepoints(int lifepoints){
    lifepoints_=lifepoints;
}
void Charakter::setStrength(int strength){
    strength_=strength;
}

std::string Charakter :: getName(){
    return Name_;
}
int Charakter::getLifepoints(){
    return lifepoints_;
}
int Charakter::getStrength(){
    return strength_;
}
int Charakter::getWincount(){
    return wincount_;
}
int Charakter::getLosecount() {
    return losecount_;
}
