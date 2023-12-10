/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:25:58 by tas               #+#    #+#             */
/*   Updated: 2023/10/06 12:16:29 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << "\x1b[34m";
    std::cout << "WrongAnimal constructor called" << std::endl;
    std::cout << "\x1b[0m";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "\x1b[34m";
    std::cout << "WrongAnimal destructor called" << std::endl;
   	std::cout << "\x1b[0m";
}

WrongAnimal::WrongAnimal(std::string type)
{
    std::cout << "\x1b[34m";
    std::cout << "WrongAnimal type constructor called" << std::endl;
    std::cout << "\x1b[0m";
    _type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout << "\x1b[34m";
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
    std::cout << "\x1b[0m";
    *this = copy;
}
 
WrongAnimal  &WrongAnimal::operator=(const WrongAnimal &assign)
{
    std::cout << "\x1b[34m";
    std::cout << "WrongAnimal Copy assignement operation called" << std::endl;
    std::cout << "\x1b[0m";
    this->_type = assign._type;
    return(*this);
}

const   std::string &WrongAnimal::GetType() const
{
    return (_type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "\x1b[34m";
    std::cout << "*Wronganimal making a sound*" << std::endl;
   	std::cout << "\x1b[0m";
}

