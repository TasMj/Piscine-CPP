/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 08:11:09 by tas               #+#    #+#             */
/*   Updated: 2023/10/05 12:28:13 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

# include <iostream>
# include <cmath>

/******************************************************************************/
/*                                   Classes                                  */
/******************************************************************************/

class Fixed
{

    public:
    /* Constructors & Destructors */
        Fixed();
        Fixed(const int a);
        Fixed(const float a);
        Fixed(const Fixed &p);
        ~Fixed();
        Fixed   &operator=(Fixed const &p);
        
    /* Comparaison operator */
        bool operator<(const Fixed &p) const;
        bool operator<=(const Fixed &p) const;
        bool operator>=(const Fixed &p) const;
        bool operator!=(const Fixed &p) const;
        bool operator==(const Fixed &p) const;
        bool operator>(const Fixed &p) const;
        
    /* Arithmetic operators */
        Fixed operator+(const Fixed &p) const;
        Fixed operator-(const Fixed &p) const;
        Fixed operator*(const Fixed &p) const;
        Fixed operator/(const Fixed &p) const;
        
    /* Increment operators */

        Fixed &operator++( void );
        Fixed operator++( int );
        Fixed &operator--( void );
        Fixed operator--( int );
        
    /* Static overload */
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);

    /* Member functions */
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
