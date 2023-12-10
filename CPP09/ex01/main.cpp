/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:55:08 by tas               #+#    #+#             */
/*   Updated: 2023/11/24 17:15:38 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "\x1b[38;5;205mError: no argument\x1b[0m" << std::endl;
	if (argc > 2)
		std::cout << "\x1b[38;5;205mError: too many arguments\x1b[0m" << std::endl;
	else
    {
		if (parseArgv(argv[1]) == 1)
			return (0);
		std::cout << "\n\x1b[38;5;228m**************TEST 1**************\x1b[0m\n" << std::endl;
		RPN	rpn;
		rpn.doCalcul(argv[1]);
		std::cout << "\n\x1b[38;5;228m**************TEST 2**************\x1b[0m\n" << std::endl;
		RPN	rpnCopy(rpn);
		rpnCopy.doCalcul(argv[1]);
	}
	return (0);
}