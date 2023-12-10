/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:46:19 by tas               #+#    #+#             */
/*   Updated: 2023/08/19 15:46:48 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap Constructor called" << std::endl;
    this->_hit = 100;
    this->_energy_point = 50;
    this->_attack_damage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap initialisation constructor called" << std::endl;
    this->_hit = 100;
    this->_energy_point = 50;
    this->_attack_damage = 20;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &p)
{
    std::cout << "ScavTrap Copy assignement operation called" << std::endl;
    ClapTrap::operator=(p);
    return(*this);
}

ScavTrap::ScavTrap(ScavTrap const &p) : ClapTrap(p)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    this->operator=(p);
}

void ScavTrap::attack(const std::string &target)
{
    this->ClapTrap::attack(target);
    return ;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap entered in Gate Keeper mode" << std::endl;
    return ;
}

