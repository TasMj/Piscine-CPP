/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 23:55:45 by tas               #+#    #+#             */
/*   Updated: 2023/10/06 13:31:17 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = copy;
}

Brain   &Brain::operator=(Brain const &copy)
{
    if (this != &copy)
    {
        for (int i = 0; i < 100; i++)
                this->ideas[i] = copy.ideas[i];
    }
    return (*this);
}

void	Brain::add_idea(std::string idea)
{
	int	i;

	i = 0;
	while (!ideas[i].empty())
		i++;
	if (i < 99)
		ideas[i] = idea;
}

void	Brain::print_ideas(void) const
{
	int	i;
	
	i = 0;
	std::cout << "idea : ";
	while (!ideas[i].empty())
	{
		std::cout << ideas[i] << std::endl;
		i++;
	}
}