/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:27:45 by tas               #+#    #+#             */
/*   Updated: 2023/11/16 09:40:19 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc > 2)
    {
        std::cout << "Too much argument" << std::endl;
    }
    else
    {
        ScalarConverter scalar;

        scalar.convert(argv[1]);
        return (0);
    }
}