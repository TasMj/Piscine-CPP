/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:22:42 by tas               #+#    #+#             */
/*   Updated: 2023/10/06 13:24:46 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
    std::cout << "\x1b[32m";
    std::cout << "AAnimal constructor called" << std::endl;
    std::cout << "\x1b[0m";
}

AAnimal::~AAnimal()
{
    std::cout << "\x1b[32m";
    std::cout << "AAnimal destructor called" << std::endl;
    std::cout << "\x1b[0m";
}

AAnimal::AAnimal(std::string type)
{
    std::cout << "\x1b[32m";
    std::cout << "AAnimal type constructor called" << std::endl;
    std::cout << "\x1b[0m";
    _type = type;
}

AAnimal::AAnimal(const AAnimal &copy)
{
    std::cout << "\x1b[32m";
    std::cout << "AAnimal Copy constructor called" << std::endl;
    std::cout << "\x1b[0m";
    *this = copy;
}
 
AAnimal  &AAnimal::operator=(const AAnimal &assign)
{
    std::cout << "\x1b[32m";
    std::cout << "AAnimal Copy assignement operation called" << std::endl;
    std::cout << "\x1b[0m";
    this->_type = assign._type;
    return(*this);
}

const   std::string &AAnimal::GetType() const
{
    return (_type);
}

void AAnimal::makeSound() const
{
    std::cout << "\x1b[32m";
    std::cout << "*aanimal making a sound*" << std::endl;
    std::cout << "\x1b[0m";
}
