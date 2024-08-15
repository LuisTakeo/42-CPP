/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaim-yu <tpaim-yu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:34:59 by tpaim-yu          #+#    #+#             */
/*   Updated: 2024/08/15 00:34:59 by tpaim-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Invalid number of arguments. Try: ./sed_for_losers [filename] [search] [replace]" << std::endl;
		return (1);
	}

	std::string 	line;
	std::string		outfileName = std::string(argv[1]) + ".replace";
	std::string		search = argv[2];
	std::string		replace = argv[3];

	std::ifstream 	infile(argv[1]);
    if (!infile)
	{
        std::cerr << "Error on opening file " << argv[1] << std::endl;
        return 1;
    }
	std::ofstream	outfile(outfileName.c_str());
	if (!outfile)
	{
		std::cerr << "Error on opening file " << outfileName << std::endl, infile.close();
		return 1;
	}
    while (std::getline(infile, line))
	{
		size_t	find_pos = 0;
		size_t	actual_pos = 0;
		while ((find_pos = line.find(search, actual_pos)) != std::string::npos)
		{
			outfile << line.substr(actual_pos, find_pos - actual_pos) << replace;
			actual_pos = find_pos + search.size();
		}
		outfile << line.substr(actual_pos) << std::endl;
    }

    infile.close();
	outfile.close();
	return (0);
}