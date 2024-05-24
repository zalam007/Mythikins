#include "Mythicube.h"

Mythicube::Mythicube(string name, unsigned quant, unsigned cap, unsigned rate)
                    : Item(name, quant, cap), catchRate(rate), capturedMythikin(nullptr){}

bool Mythicube::isCaught(Mythikin &victim) const
{
    // Calculate percentage of health the victim has
    double hpPercent = ((victim.getHP()) / static_cast<double>(victim.getMaxHP())) * 100;

    double chance = 11 + static_cast<double>(rand() % 41); // Ranges 11 to 51 (inclusive)

    //Victim is catchable at 50%. Guarenteed catch at 10% or lower.
    /*
        Formula:
        HP%/catchrate <= (#11-#51) - (#0.1-#10)

        Improve catch chances by lower HP, raising catchrate of the cube
        Increase difficulty by increasing victim's level. Only slightly makes it difficult

        As long as left side is less or equal to right side, success is ensured.
        
        Influences:
        - HP: damage done to victim
        - Built in catchrate of cube (defualt is 1)
        - Random chance of the game
        - Sligth influence by the victim's level. 
    */
    if (hpPercent / catchRate <= chance - victim.getLevel()/10)
    {
        return true;
    }
    return false;
}

void Mythicube::use(Mythikin &victim)
{
    if (isCaught(victim)) //If formula returned successful, store Mythikin caught
    {
        capturedMythikin = new Mythikin(victim);
    }
    changeQuantity(getQuantity() - 1);  //decrement quanitity
}