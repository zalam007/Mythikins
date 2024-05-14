#include "Mythicube.h"

Mythicube::Mythicube(string name, unsigned quant, unsigned cap, unsigned rate)
    : Item(name, quant, cap), catchRate(rate){}

bool Mythicube::caught(Mythikin &victim) const
{
    // Calculate percentage of health the victim has
    double hpPercent = ((victim.getHP()) / static_cast<double>(victim.getMaxHP())) * catchRate;

    double chance = 0.25 + static_cast<double>(rand() / 5) / (RAND_MAX); // 0.25 to 0.5

    if (hpPercent <= chance)
    { // if HP percent is atleast 50% or lower, the victim is catchable
        return true;
    }
    return false;
}

void Mythicube::use(Mythikin &victim)
{
    if (caught(victim))
    {
        //Incomplete
    }
    changeQuantity(getQuantity() - 1);
}