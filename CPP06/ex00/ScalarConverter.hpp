/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:00:09 by tas               #+#    #+#             */
/*   Updated: 2023/11/16 09:33:12 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

/******************************************************************************/
/*                                   Classes                                  */
/******************************************************************************/

class ScalarConverter
{
    public:

        ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(const ScalarConverter &assign);
        ~ScalarConverter();

        void    convert(std::string nb);
        
        /* conversions */
        void    toChar(std::string nb);
        void    toInt(std::string nb);
        void    toFloat(std::string nb);
        void    toDouble(std::string nb);
		
	private:
		
};

long long	ft_atoi(std::string nptr);
int	ft_strcmp(std::string s1, std::string s2);

#endif