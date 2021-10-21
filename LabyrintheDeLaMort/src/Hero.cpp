#include "Hero.h"

int Hero::get_base_luck() const
{
	return base_luck_;
}

int Hero::get_luck() const
{
	return luck_;
}

void Hero::increment_base_luck()
{
	base_luck_++;
}

void Hero::set_luck(const int luck)
{
	luck_ = luck;
}
