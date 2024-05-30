#include "../header/Mythicube.h"


bool Mythicube::calculatedToBeCaught(Mythikin &victim) const
{
    // Calculate percentage of health the victim has
    double hpPercent = ((victim.getHP()) / static_cast<double>(victim.getMaxHP())) * 100;

    double chance = 11 + static_cast<double>(rand() % 41); // Chance = 11-51 (inclusive)

    //Victim is catchable at 50%. Guarenteed catch at 10% or lower.
    /*
        Formula:
        HP%/catchrate <= Chance - Level

        Improve catch chances by lower HP, raising catchrate of the cube
        Increase difficulty by increasing victim's level. Only slightly makes it difficult

        As long as left side is less or equal to right side, success is ensured.
        
        Influences:
        - HP: damage done to victim
        - Built in catchrate of cube (defualt is 1)
        - Random chance of the game
        - Slight influence by the victim's level. 
    */
    if (hpPercent / catchRate <= chance - victim.getLevel()/10)
    {
        return true;    // true gaurnteeded to be catch
    }
    return false;
}

void Mythicube::use(Mythikin& victim)
{
    //If formula returned successful, store Mythikin caught
    if (calculatedToBeCaught(victim))
    {
        capturedMythikin = new Mythikin(victim);
    }
    changeQuantity(getQuantity() - 1);  //decrement quanitity
}