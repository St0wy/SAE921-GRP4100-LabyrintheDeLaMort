#pragma once
#include "Potion.h"
class EndurancePotion :
    public Potion
{
public:
    void drink(Hero& hero) override;
};

