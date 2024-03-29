/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:23:05 by tas               #+#    #+#             */
/*   Updated: 2023/12/26 13:41:32 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cout << "\x1b[38;5;205mError: wrong amount of argument\x1b[0m" << std::endl;
		return (0);
	}
	BitcoinExchange btc;
	std::cout << "\n\x1b[38;5;228m**************TEST**************\x1b[0m\n" << std::endl;
	btc.parseFile(argv[1]);
	std::cout << "\n\x1b[38;5;228m********************************\x1b[0m\n" << std::endl;
}