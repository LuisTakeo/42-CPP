/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 05:22:44 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/08/15 05:22:44 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
	{
		std::cerr << "Error! Insert only: ./harl [LEVEL]. Levels = (DEBUG/INFO/WARNING/ERROR)" << std::endl;
		return (1);
	}
	else
		harl.complain(argv[1]);
	return (0);
}