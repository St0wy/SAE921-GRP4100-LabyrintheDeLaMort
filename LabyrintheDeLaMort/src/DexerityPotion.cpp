#include "DexerityPotion.h"

void DexerityPotion::drink(Hero& hero)
{
	hero.set_dexterity(hero.get_base_dexterity());
}
