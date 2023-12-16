/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:00:09 by tas               #+#    #+#             */
/*   Updated: 2023/12/15 19:36:29 by tmejri           ###   ########.fr       */
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
/*                                 Includes                                   */
/******************************************************************************/
#define PINK "\x1b[38;5;205m"
#define EOC "\x1b[0m"

/******************************************************************************/
/*                                   Classes                                  */
/******************************************************************************/

class ScalarConverter
{
    private:

        ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(const ScalarConverter &assign);
        ~ScalarConverter();

    public:
    
        static void    convert(std::string nb);
		
};

#endif