#include "Item.h"

#include <utility>

Item::Item()
	: Item("", 0, 0, 0)
{
}

Item::Item(std::string name, const int dexterity_bonus, const int endurance_bonus, const int luck_bonus)
	: name_(std::move(name)), dexterity_bonus_(dexterity_bonus), endurance_bonus_(endurance_bonus), luck_bonus_(luck_bonus)
{

}
