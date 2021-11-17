#pragma once
#include "Potion.h"
class LuckPotion :
    public Potion
{
    void drink(Hero& hero) override;
};

