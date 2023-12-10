/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:17:35 by tas               #+#    #+#             */
/*   Updated: 2023/10/06 13:25:48 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
    std::cout << "\x1b[35m";
    std::cout << "Dog constructor called" << std::endl;
    std::cout << "\x1b[0m";
    this->brain = new Brain();
}

Dog::~Dog()
{
    std::cout << "\x1b[35m";
    std::cout << "Dog destructor called" << std::endl;
    std::cout << "\x1b[0m";
    delete this->brain;
}
Dog::Dog(const Dog &copy) : AAnimal(copy)
{
    std::cout << "\x1b[35m";
    std::cout << "Dog Copy constructor called" << std::endl;
    std::cout << "\x1b[0m";
    this->brain = new Brain();
    *this = copy;
}
        
Dog  &Dog::operator=(const Dog &assign)
{
    std::cout << "\x1b[35m";
    std::cout << "Dog Copy assignement operation called" << std::endl;
    std::cout << "\x1b[0m";
    if (this != &assign)
	{
		this->_type = assign._type;
		*this->brain = *assign.brain;
	}
    return(*this);
}

void Dog::makeSound() const
{
    std::cout << "\x1b[35m";
    std::cout << "*wouuuuuuuuuf*" << std::endl;
    std::cout << "\x1b[0m";
}

Brain* Dog::GetBrain( void ) const
{
    return (this->brain);
}
