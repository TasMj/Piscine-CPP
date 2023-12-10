/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 08:10:50 by tas               #+#    #+#             */
/*   Updated: 2023/10/05 13:14:54 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/******************************************************************************/
/*                          Constructors & Destructors                        */
/******************************************************************************/

Fixed::Fixed()
{
    fix_stock = 0;
}

Fixed::Fixed(const int a)
{
    this->fix_stock = a << bits_stock;
}

Fixed::Fixed(const float a)
{
    this->fix_stock = roundf(a * (1 << bits_stock));
}

Fixed::~Fixed()
{
    return ;
}

Fixed::Fixed(const Fixed &p)
{
    *this = p;
}

Fixed   &Fixed::operator=(Fixed const &p)
{
    if (this != &p) 
        this->fix_stock = p.getRawBits();
    return (*this);
}

/******************************************************************************/
/*                          Comparative operator                              */
/******************************************************************************/

bool Fixed::operator<(const Fixed &p) const
{
    return (this->getRawBits() < p.getRawBits());
}

bool Fixed::operator>(const Fixed &p) const
{
    return (this->getRawBits() > p.getRawBits());
}

bool Fixed::operator<=(const Fixed &p) const
{
    return (this->getRawBits() <= p.getRawBits());
}

bool Fixed::operator>=(const Fixed &p) const
{
    return (this->getRawBits() >= p.getRawBits());
}

bool Fixed::operator!=(const Fixed &p) const
{
    return (this->getRawBits() != p.getRawBits());
}

bool Fixed::operator==(const Fixed &p) const
{
    return (this->getRawBits() == p.getRawBits());
}


/******************************************************************************/
/*                          Arithmetic operators                              */
/******************************************************************************/

Fixed Fixed::operator+(const Fixed &p) const
{
    Fixed res;
	res.setRawBits(this->getRawBits() + p.getRawBits());
    return (res);
}

Fixed Fixed::operator-(const Fixed &p) const
{
    Fixed res;
	res.setRawBits(this->getRawBits() - p.getRawBits());
    return (res);
}

Fixed Fixed::operator*(const Fixed &p) const
{
    Fixed res;
    res.setRawBits((this->getRawBits() * p.getRawBits()) >> bits_stock);
    return res;
}

Fixed Fixed::operator/(const Fixed &p) const
{
    Fixed res;
	res.setRawBits(this->getRawBits() / p.getRawBits());
    return (res);
}

/*********** Increment operators ***********/

Fixed &Fixed::operator++( void )
{
    ++fix_stock;
    return (*this);
}

Fixed Fixed::operator++( int )
{
    Fixed temp = *this;
	++fix_stock;
	return (temp);
}

Fixed &Fixed::operator--( void )
{
    --fix_stock;
    return (*this);
}

Fixed Fixed::operator--( int )
{
    Fixed temp = *this;
	--fix_stock;
	return (temp);

}
        
/*************** min max ***************/

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.fix_stock <= b.fix_stock)
        return (a);
    return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.fix_stock <= b.fix_stock)
        return (a);
    return (b);

}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.fix_stock >= b.fix_stock)
        return (a);
    return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.fix_stock >= b.fix_stock)
        return (a);
    return (b);
}

/*********** Member functions ***********/

int Fixed::getRawBits(void) const
{
    return(this->fix_stock);
}

void Fixed::setRawBits(int const raw)
{
    this->fix_stock = raw;   
}

float   Fixed::toFloat(void) const
{
    return((float)this->fix_stock / (1 << bits_stock));
}

int Fixed::toInt(void) const
{
    return(this->fix_stock >> bits_stock);
}

/*********** Other operator ***********/

std::ostream &operator<<(std::ostream &o, Fixed const &f)
{
	o << f.toFloat();
	return (o);
}
