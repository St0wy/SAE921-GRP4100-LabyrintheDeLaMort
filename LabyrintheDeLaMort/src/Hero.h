#pragma once
#include "Entity.h"
#include "Jewel.h"
#include <vector>
#include <memory>
#include "Weapon.h"
#include "Armor.h"

class Hero :
    public Entity
{
private:
    int luck_;
    std::vector<Jewel> jewels_;
    int gold_;
    std::vector<std::unique_ptr<Item>> items_;
    std::unique_ptr<Weapon> weapon_;
    std::unique_ptr<Armor> armor_;


};

