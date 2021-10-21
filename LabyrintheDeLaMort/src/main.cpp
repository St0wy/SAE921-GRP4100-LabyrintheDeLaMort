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
	// Get the current time
	const uint32_t current_time = static_cast<uint32_t>(
		std::chrono::high_resolution_clock::now().time_since_epoch().count());

	// Create the rnd generator
	// Takes the current time as a seed
	std::default_random_engine generator(current_time);

	//Entity one = Entity(generator);
	//Entity two = Entity(generator);


	//Item i = Item("Pomme", 2, 5, 13);
	//cout << i.name_ << endl;
}