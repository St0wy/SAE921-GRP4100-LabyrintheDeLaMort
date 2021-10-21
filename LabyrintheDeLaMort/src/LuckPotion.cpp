#include "LuckPotion.h"

void LuckPotion::drink(Hero& hero)
{
	hero.increment_base_luck();
	hero.set_luck(hero.get_base_luck());
}
