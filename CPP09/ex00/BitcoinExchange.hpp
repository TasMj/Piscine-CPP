/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:22:07 by tas               #+#    #+#             */
/*   Updated: 2023/12/26 13:53:34 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <cstdlib>
#include <sstream>

/******************************************************************************/
/*                                   Classes                                  */
/******************************************************************************/

class BitcoinExchange
{
    public:
        /* constructors and destructor */
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);

		/* operator */
		BitcoinExchange &operator=(const BitcoinExchange &cpy);
		
		/* function member */
		bool	parseFile(std::string file);
		int		checkLine(std::string line);
		void	getData();
    	std::map<std::string, float>::iterator it;
		int		printResult(std::string line);
    	std::map<std::string, float>::iterator ite;
		float	findClosest(std::string lineSub);

	private:
    	std::map<std::string, float> _data;
};

bool	checkYear(std::string str);
bool	checkMonth(std::string str);
bool	checkDay(std::string str);

#endif