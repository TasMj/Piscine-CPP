/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:15:01 by tas               #+#    #+#             */
/*   Updated: 2023/10/05 19:34:04 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>


ClapTrap::ClapTrap() : _hit(10), _energy_point(10), _attack_damage(0)
{
    std::cout << "Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _energy_point(10), _attack_damage(0)
{
    std::cout << "***********************************************\n";
    std::cout << "ClapTrap initialisation constructor called" << std::endl;
    std::cout << "Initialization..." << name << " was created.\n";
    std::cout << "hit: " << _hit << std::endl;
    std::cout << "energy point: " << _energy_point << std::endl;
    std::cout << "attack damage: " << _attack_damage << std::endl;
    std::cout << "***********************************************\n";
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &p)
{
    std::cout << "Copy assignement operation called" << std::endl;
    this->_name = p._name;
    this->_hit = p._hit;
    this->_energy_point = p._energy_point;
    this->_attack_damage = p._attack_damage;
    return(*this);
}

ClapTrap::ClapTrap(ClapTrap const &p)
{
    std::cout << "Copy constructor called" << std::endl;
    this->operator=(p);
}
   
void ClapTrap::attack(const std::string& target)
{
    if (this->_hit <= 0)
        std::cout << "ClapTrap " << this->_name << " can't attack because he is dead." << std::endl;
    else if (this->_energy_point == 0)
        std::cout << "ClapTrap " << this->_name << " doesn't have enough energy point to attack" << std::endl;
    else
    {
        if (_energy_point != 0)
        {
            this->_energy_point -= 1;
            std::cout << "ClapTrap " << this->_name << " attacks " << target;
            std::cout << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
        }
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (amount <= 0)
        std::cout << "ClapTrap : not a correct amount" << std::endl;
    else if (this->_hit <= 0)
        std::cout << "ClapTrap " << this->_name << " is already dead." << std::endl;
    else if (this->_energy_point == 0)
        std::cout << "ClapTrap " << this->_name << " can't be repaired " << this->_energy_point;
    else
    {
        this->_hit += amount;
        this->_energy_point -= 1;
        std::cout << "ClapTrap " << this->_name << " repaired and has now " << this->_energy_point;
        std::cout << " energy point." << std::endl;

    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount <= 0)
        std::cout << "ClapTrap : not a correct amount" << std::endl;
    else if (this->_hit <= 0)
        std::cout << "ClapTrap " << this->_name << " is already dead." << std::endl;
    else
    {
        std::cout << "ClapTrap " << this->_name << " took " << amount << " damage" << std::endl;
        this->_hit -= amount;
        if (this->_hit <= 0)
            std::cout << "ClapTrap " << this->_name << " just died." << std::endl;
    }
}
