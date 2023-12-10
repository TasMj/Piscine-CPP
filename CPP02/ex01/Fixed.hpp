/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 08:05:03 by tas               #+#    #+#             */
/*   Updated: 2023/10/05 11:42:15 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

# include <iostream>
# include <string.h>
# include <cmath>

/******************************************************************************/
/*                                   Classes                                  */
/******************************************************************************/

class Fixed
{

    public:
        Fixed();
        Fixed(const int a);
        Fixed(const float a);
        Fixed(const Fixed &p);
        Fixed   &operator=(Fixed const &p);
        ~Fixed();
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
    
    private:
        int fix_stock;
        static const int bits_stock = 8;
};

std::ostream	&operator<<( std::ostream &o, Fixed const &i);

#endif