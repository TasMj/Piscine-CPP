/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 07:54:34 by tas               #+#    #+#             */
/*   Updated: 2023/10/05 13:16:20 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    fix_stock = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Default Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &p)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = p;
}

Fixed   &Fixed::operator=(Fixed const &p)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &p)
        this->fix_stock = p.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->fix_stock);
}


void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fix_stock = raw;   
}
