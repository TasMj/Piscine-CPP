/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:09:09 by tas               #+#    #+#             */
/*   Updated: 2023/10/06 13:25:16 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
    std::cout << "\x1b[33m";
    std::cout << "Cat constructor called" << std::endl;
    std::cout << "\x1b[0m";
    this->brain = new Brain();
}

Cat::~Cat()
{
    std::cout << "\x1b[33m";
    std::cout << "Cat destructor called" << std::endl;
    std::cout << "\x1b[0m";
    delete this->brain;
}
Cat::Cat(const Cat &copy) : AAnimal(copy)
{
    std::cout << "\x1b[33m";
    std::cout << "Cat Copy constructor called" << std::endl;
    std::cout << "\x1b[0m";
    this->brain = new Brain();
    *this = copy;
}
        
Cat  &Cat::operator=(const Cat &assign)
{
    std::cout << "\x1b[33m";
    std::cout << "Cat Copy assignement operation called" << std::endl;
    std::cout << "\x1b[0m";
    if (this != &assign)
	{
		this->_type = assign._type;
		*this->brain = *assign.brain;
	}
    return(*this);
}

void Cat::makeSound() const
{
    std::cout << "\x1b[33m";
    std::cout << "*miaouuuuuuuuuu*" << std::endl;
    std::cout << "\x1b[0m";
}

Brain* Cat::GetBrain( void ) const
{
    return (this->brain);
}