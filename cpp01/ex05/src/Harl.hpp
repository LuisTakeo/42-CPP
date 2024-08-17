/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 05:23:03 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/08/15 05:23:03 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CPP
# define HARL_CPP

# include <string>
# include <iostream>

class Harl
{
private:
	std::string	_levels[4];
	void		(Harl::*_callFunc[4])(void);

	void		debug(void);
	void		info(void);
	void		warning(void);
	void		error(void);

public:
	Harl();
	~Harl();

	void		complain(std::string level);
};


#endif