//
// Created by Petra Scheuer on 12.03.24.
//
#ifndef FIGHTCLUB_SCHEUER_SPIELFIGUREN_H
#define FIGHTCLUB_SCHEUER_SPIELFIGUREN_H
#include <iostream>
#include <string>
#include <vector>

class Spielfigur {
private:
    std::string name_;
    std::string item_;
    std::string typ_;

public:
    Spielfigur(const std::string& name, const std::string& item, std::string typ)
            : name_(name), item_(item), typ_(typ) {}
    static std::vector<Spielfigur> erstelleVerfuegbareSpielfiguren();

    // Getter und Setter
    void setName(const std::string& name);

    void setItem(const std::string& item);

    void setTyp(std::string typ);

    std::string getName() const;

    std::string getItem() const;

    std::string getTyp() const;
};



#endif //FIGHTCLUB_SCHEUER_SPIELFIGUREN_H
