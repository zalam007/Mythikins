#include "../header/Potion.h"

/*
    Formula: Current HP + (Potion heal HP% of Patient's maxHP)

    EX: Current HP 50, maxHP 100, potion heals 25%.
        25% of 100 = 25. 25 + 50 = 75
        Current HP = 75 after use().

    Influences:
    - Current HP of Mythikin
    - MaxHP of Mythikin (determined by level and base health at spawn)
    - potion's heal power
*/

void Potion::use(Mythikin &patient)
{
    patient.setHP(patient.getHP() + (healPowerPercent * patient.getMaxHP()) / 100);
    setQuantity(getQuantity() - 1); // decrement quanitity
}