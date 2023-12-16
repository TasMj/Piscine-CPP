/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:27:45 by tas               #+#    #+#             */
/*   Updated: 2023/12/15 19:36:13 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << PINK << "Error: No argument" << EOC << std::endl;
    else if (argc > 2)
        std::cout << PINK << "Error: Too much argument" << EOC << std::endl;
    else
        ScalarConverter::convert(argv[1]);
    return (0);
}