/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:34:09 by tas               #+#    #+#             */
/*   Updated: 2023/10/06 12:18:08 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "\x1b[31m";
    std::cout << "WrongCat constructor called" << std::endl;
    std::cout << "\x1b[0m";
}

WrongCat::~WrongCat()
{
    std::cout << "\x1b[31m";
    std::cout << "WrongCat destructor called" << std::endl;
    std::cout << "\x1b[0m";
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
    std::cout << "\x1b[31m";
    std::cout << "WrongCat Copy constructor called" << std::endl;
    std::cout << "\x1b[0m";
    *this = copy;
}
        
WrongCat  &WrongCat::operator=(const WrongCat &assign)
{
    std::cout << "\x1b[31m";
    std::cout << "WrongCat Copy assignement operation called" << std::endl;
    std::cout << "\x1b[0m";
    this->_type = assign._type;
    return(*this);
}

void WrongCat::makeSound() const
{
    std::cout << "\x1b[31m";
    std::cout << "*Wrong miaouuuuuuuuuu*" << std::endl;
    std::cout << "\x1b[0m";
}
