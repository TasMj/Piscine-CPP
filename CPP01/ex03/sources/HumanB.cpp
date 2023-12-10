/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:35:35 by tas               #+#    #+#             */
/*   Updated: 2023/06/11 13:10:11 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"
#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string Name)
{
    this->name = Name;
    std::cout << "Human B: " << this->name << " created" << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << "Human B: " << this->name << " destructed" << std::endl;
}

void    HumanB::set_weapon(Weapon &Weapon)
{
    this->weapon = &Weapon;
}

void    HumanB::attack(void)
{
    std::cout << this->name << " attacks with their " << this->weapon->get_type() << std::endl;
}

