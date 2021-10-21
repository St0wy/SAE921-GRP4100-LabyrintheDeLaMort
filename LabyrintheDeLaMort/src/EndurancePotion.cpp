#include "EndurancePotion.h"

void EndurancePotion::drink(Hero& hero)
{
	hero.set_endurance(hero.get_base_endurance());
}
