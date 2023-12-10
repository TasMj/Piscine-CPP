/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:30:13 by tas               #+#    #+#             */
/*   Updated: 2023/08/19 17:03:42 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap Constructor called" << std::endl;
    this->_hit = 100;
    this->_energy_point = 100;
    this->_attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap initialisation constructor called" << std::endl;
    this->_hit = 100;
    this->_energy_point = 100;
    this->_attack_damage = 30;
}

FragTrap::FragTrap(FragTrap const &p) : ClapTrap(p)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
    this->operator=(p);
}

FragTrap    &FragTrap::operator=(FragTrap const &p)
{
    std::cout << "FragTrap Copy assignement operation called" << std::endl;
    ClapTrap::operator=(p);
    return(*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    this->ClapTrap::attack(target);
    return ;
}

void    FragTrap::highFivesGuys()
{
    std::cout << "FragTrap is asking for a high fives" << std::endl;
}