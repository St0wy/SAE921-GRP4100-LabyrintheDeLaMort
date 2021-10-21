#include <iostream>
#include "Item.h"

using std::cout;
using std::endl;

int main()
{
    Item i = Item("Pomme", 2, 5, 13);
    cout << i.name_ << endl;
}