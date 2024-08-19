#include "ScavTrap.hpp"

int main()
{
    {
        ScavTrap scav;
        ScavTrap trap (scav);
        ScavTrap other("AnteDEGUEMON");
        trap = other;
    }

    std::cout << "----------------------" << std::endl;
    ScavTrap scav("anteDEGUEMON");
    scav.announceDetails();
    std::cout << "----------------------" << std::endl;
    scav.attack("enemy");
    scav.beRepaired(1);
    scav.guardGate();
    scav.takeDamage(3);
    scav.takeDamage(200);
    scav.guardGate();
    scav.attack("enemy");
    std::cout << "----------------------" << std::endl;
    for (int i = 0; i < 50; i++)
    {
        scav.beRepaired(1);
        scav.attack("enemy");
        scav.guardGate();
    }
    scav.takeDamage(200);
    std::cout << "----------------------" << std::endl;
    return 0;
}