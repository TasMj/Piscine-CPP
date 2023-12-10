/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 08:04:56 by tas               #+#    #+#             */
/*   Updated: 2023/10/05 12:08:15 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    fix_stock = 0;
    std::cout << "Default constructor called" << std::endl;
}

/* converti l'entier a en une valeur en virgule fixe. 
prend la valeur de a, la décale vers la gauche de bits_stock
positions ce qui équivaut à la multiplication de a par 2^8.*/
Fixed::Fixed(const int a)
{
    std::cout << "Int constructor called" << std::endl;
    this->fix_stock = a << bits_stock;
}

/* effectue la conversion du nombre à virgule flottante a en une
valeur en virgule fixe.le nombre à virgule flottante a est multiplié par
1 décalé vers la gauche de bits_stock. Ensuite, le résultat de la multiplication
est arrondi à l'entier le plus proche en utilisant la fonction roundf*/
Fixed::Fixed(const float a)
{
    std::cout << "Float constructor called" << std::endl;
    this->fix_stock = roundf(a * (1 << bits_stock));
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

std::ostream &operator<<(std::ostream &o, Fixed const &f)
{
	o << f.toFloat();
	return (o);
}

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

/*  Ce décalage binaire vers la droite équivaut à une division
par 2^bits_stock */
int Fixed::toInt(void) const
{
    return(this->fix_stock >> bits_stock);
}