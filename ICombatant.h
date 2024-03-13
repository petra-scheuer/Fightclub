//
// Created by Petra Scheuer on 12.03.24.
//

#ifndef FIGHTCLUB_SCHEUER_ICOMBATANT_H
#define FIGHTCLUB_SCHEUER_ICOMBATANT_H


class ICombatant {
public:
    virtual ~ICombatant() {}
    virtual void attack(ICombatant& target) = 0;
    virtual void takeDamage(int amount) = 0;

};


#endif //FIGHTCLUB_SCHEUER_ICOMBATANT_H
