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
    // Weitere Methoden können hier definiert werden, je nach Bedarf.
};


#endif //FIGHTCLUB_SCHEUER_ICOMBATANT_H
