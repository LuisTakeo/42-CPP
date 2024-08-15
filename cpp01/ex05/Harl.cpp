/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 05:23:08 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/08/15 05:23:08 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(/* args */)
{
	this->_levels[0] = "DEBUG";
	this->_levels[1] = "INFO";
	this->_levels[2] = "WARNING";
	this->_levels[3] = "ERROR";
	this->_callFunc[0] = &Harl::debug;
	this->_callFunc[1] = &Harl::info;
	this->_callFunc[2] = &Harl::warning;
	this->_callFunc[3] = &Harl::error;
}

Harl::~Harl()
{

}

void	Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (level == this->_levels[i])
		{
			(this->*_callFunc[i])();
			return ;
		}
	}
	std::cout << "Level not found. Insert one of the options: (DEBUG/INFO/WARNING/ERROR)" << std::endl;
}

void		Harl::debug(void)
{
	std::cout << "Debugging, debbugging, ZIP, ZOP, ZIP... So many bugs, oh..." << std::endl;
}

void		Harl::info(void)
{
	std::cout << "This is a info message without a subject. Thank you for reading this text about nothing." << std::endl;
}

void		Harl::warning(void)
{
	std::cout << "WARNING: Watch out! Behind you! Ops, sorry! It's just a bug xD" << std::endl;
}

void		Harl::error(void)
{
	std::cout << "Its an Europe country. In a past it invaded Brazil. His language is Dutch. WRONG! ERRO(u)R!" << std::endl;
}
