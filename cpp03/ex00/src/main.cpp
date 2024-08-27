#include "ClapTrap.hpp"

int main()
{
    std::cout << "Tests constructors clap trap" << std::endl;
    std::cout << "----------------------" << std::endl;
    ClapTrap clap;
    ClapTrap trap (clap);
    ClapTrap other("AnteDEGUEMON");

    trap = other;
    std::cout << "----------------------" << std::endl;
    clap.announceDetails();
    std::cout << "----------------------" << std::endl;
    clap.attack("enemy");
    clap.beRepaired(1);
    clap.takeDamage(3);
    clap.takeDamage(10);
    clap.attack("enemy");
    clap.beRepaired(1);
    clap.beRepaired(1);
    clap.beRepaired(1);
    clap.beRepaired(1);
    clap.beRepaired(1);
    clap.beRepaired(1);
    clap.beRepaired(1);
    clap.beRepaired(1);
    clap.beRepaired(1);
    clap.attack("enemy");
    return 0;
}