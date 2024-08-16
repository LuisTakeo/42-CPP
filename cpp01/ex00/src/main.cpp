#include <iostream>
#include "Zombie.hpp"


int main()
{
    Zombie  *zombie;

    zombie = new Zombie("Antedeguemon");
    zombie->announce();
    delete zombie;
    randomChump("AnteDEGUEMON");
    return 0;
}
