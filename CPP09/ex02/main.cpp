/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:23:11 by tmejri            #+#    #+#             */
/*   Updated: 2023/12/26 16:22:14 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << PINK << "Error: no argument" << EOC << std::endl;
        return (0);
    }
    PmergeMe P;
    if (P.parseArgs(argc, argv) == false)
        return (0);
    P.displayRes();
}
