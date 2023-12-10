/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:22:35 by tas               #+#    #+#             */
/*   Updated: 2023/08/23 00:41:51 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"



int main(int argc, char **argv)
{
    std::string buffer;
    
    if (argc != 4)
    {
        std::cout << ("wrong number of parameters") << std::endl;
        return(0);
    }
    Sed s(argv[1], argv[2], argv[3]);
    while(std::getline(s.get_infile(), buffer, '\0'))
    {
        buffer = ft_replace(buffer, argv[2], argv[3]);
        s.get_outfile() << buffer.c_str();
    }
    return (0);
}