/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:22:42 by tas               #+#    #+#             */
/*   Updated: 2023/10/06 12:06:36 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << "\x1b[32m"; 
    std::cout << "Animal constructor called" << std::endl;
    std::cout << "\x1b[0m";
}

Animal::~Animal()
{
    std::cout << "\x1b[32m";
    std::cout << "Animal destructor called" << std::endl;
    std::cout << "\x1b[0m";
}

Animal::Animal(std::string type)
{
    std::cout << "\x1b[32m";
    std::cout << "Animal type constructor called" << std::endl;
    std::cout << "\x1b[0m";
    _type = type;
}

Animal::Animal(const Animal &copy)
{
    std::cout << "\x1b[32m";
    std::cout << "Animal Copy constructor called" << std::endl;
    std::cout << "\x1b[0m";
    *this = copy;
}
 
Animal  &Animal::operator=(const Animal &assign)
{
    std::cout << "\x1b[32m";
    std::cout << "Animal Copy assignement operation called" << std::endl;
    std::cout << "\x1b[0m";
    this->_type = assign._type;
    return(*this);
}

const   std::string &Animal::GetType() const
{
    return (_type);
}

void Animal::makeSound() const
{
    std::cout << "\x1b[32m";
    std::cout << "*animal making a sound*" << std::endl;
    std::cout << "\x1b[0m";
}
