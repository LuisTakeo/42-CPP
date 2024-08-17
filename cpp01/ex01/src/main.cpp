#include <iostream>
#include "Zombie.hpp"


int main()
{
    int     qtdZombies;
    Zombie  *zombie;

    qtdZombies = 5;
    zombie = zombieHorde(qtdZombies, "AnteDEGUEMOOOOOOON");
    for (int i = 0; i < qtdZombies; i++)
        zombie[i].announce();
    delete [] zombie;
    return 0;
}