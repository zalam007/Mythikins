#include "Mythicube.h"

Mythicube::Mythicube(string name, unsigned quant, unsigned cap, unsigned rate)
                    : Item(name, quant, cap), catchRate(rate){}

bool Mythicube::caught(Mythikin &victim) const
{
    // Calculate percentage of health the victim has
    double hpPercent = ((victim.getHP()) / static_cast<double>(victim.getMaxHP())) * 100;

    double chance = 11 + static_cast<double>(rand() % 41); // 0.25 to 0.5

cout << "HP: " << hpPercent << endl;
cout << "chance: " << chance << endl;
cout << "Success?: " << hpPercent / catchRate << "<=" << chance - LV/10 << endl;

    if (hpPercent / catchRate <= chance - LV/10)
    {
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
    //changeQuantity(getQuantity() - 1);
}