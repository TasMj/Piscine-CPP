/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:17:35 by tas               #+#    #+#             */
/*   Updated: 2023/10/06 12:11:04 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "\x1b[35m";
    std::cout << "Dog constructor called" << std::endl;
    std::cout << "\x1b[0m";
}

Dog::~Dog()
{
    std::cout << "\x1b[35m";
    std::cout << "Dog destructor called" << std::endl;
    std::cout << "\x1b[0m";
}
Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "\x1b[35m";
    std::cout << "Dog Copy constructor called" << std::endl;
    std::cout << "\x1b[0m";
    *this = copy;
}
        
Dog  &Dog::operator=(const Dog &assign)
{
    std::cout << "\x1b[35m";
    std::cout << "Dog Copy assignement operation called" << std::endl;
    std::cout << "\x1b[0m";
    this->_type = assign._type;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "\x1b[35m";
    std::cout << "*wouuuuuuuuuf*" << std::endl;
    std::cout << "\x1b[0m";
}