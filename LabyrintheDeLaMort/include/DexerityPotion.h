#pragma once
#include "Potion.h"

class DexerityPotion :
    public Potion
{
public:
    void drink(Hero& hero) override;
};

