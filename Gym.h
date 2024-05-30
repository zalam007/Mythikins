#include "Location.h"

class Gym: protected Location {
private:
    bool defeated;
public:
    void startBattle();
};