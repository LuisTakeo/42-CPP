#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    {
        ClapTrap clap;
        ClapTrap ctrap (clap);
        ClapTrap cother("AnteDEGUEMON");
        ctrap = cother;
    }
    {
        std::cout << "----------------------" << std::endl;
        ScavTrap scav;
        ScavTrap trap (scav);
        ScavTrap other("AnteDEGUEMON");
        trap = other;
    }
    {
        std::cout << "----------------------" << std::endl;
        FragTrap frag;
        FragTrap ftrap (frag);
        FragTrap fother("FRANKLY");
        ftrap = fother;

        std::cout << "----------------------" << std::endl;
    }
    std::cout << "----------------------" << std::endl;
    ClapTrap clap("clapDEGUEMON");
    clap.announceDetails();
    std::cout << "----------------------" << std::endl;
    ScavTrap scav("scavDEGUEMON");
    scav.announceDetails();
    std::cout << "----------------------" << std::endl;
    FragTrap frag("fragDEGUEMON");
    frag.announceDetails();
    std::cout << "----------------------" << std::endl;
    scav.attack(frag.getName());
    frag.takeDamage(scav.getAttackDamage());
    frag.attack(scav.getName());
    scav.takeDamage(frag.getAttackDamage());
    clap.attack(frag.getName());
    frag.takeDamage(clap.getAttackDamage());
    frag.beRepaired(20);
    scav.guardGate();
    frag.highFiveGuys();
    frag.takeDamage(3);
    frag.takeDamage(200);
    frag.highFiveGuys();
    frag.attack("enemy");
    std::cout << "----------------------" << std::endl;
    frag.takeDamage(200);
    std::cout << "----------------------" << std::endl;
    return 0;
}