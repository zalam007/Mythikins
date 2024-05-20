#include "Potion.h"

void Potion::use(Mythikin &patient)
{
    patient.setHP(patient.getHP() + (healPowerPercent * patient.getMaxHP())/100);
}