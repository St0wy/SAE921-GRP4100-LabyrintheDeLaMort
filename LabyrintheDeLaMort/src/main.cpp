#include "Entity.h"
#include "Item.h"


#include <iostream>
#include <chrono>
#include <random>
#include "Potion.h"

using std::cout;
using std::endl;

int main()
{
	Potion p;
	p.drink();

	// obtain a seed from the system clock
	const uint32_t seed = static_cast<uint32_t>(
		std::chrono::high_resolution_clock::now().time_since_epoch().count());

	// Create the rnd generator
	std::default_random_engine generator(seed);

	//Entity one = Entity(generator);
	//Entity two = Entity(generator);


	//Item i = Item("Pomme", 2, 5, 13);
	//cout << i.name_ << endl;
}