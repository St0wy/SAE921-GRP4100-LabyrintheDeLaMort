#pragma once
#include <string>

class Item
{
private:
	std::string name_;
	int dexterity_bonus_;
	int endurance_bonus_;
	int luck_bonus_;
public:
	Item();
	Item(std::string name, int dexterity_bonus, int endurance_bonus, int luck_bonus);

};

