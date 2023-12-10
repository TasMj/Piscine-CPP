/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:33:37 by tas               #+#    #+#             */
/*   Updated: 2023/06/11 13:09:20 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"
#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string Name, Weapon &Weapon) : name(Name), weapon(Weapon)
{
    std::cout << "Human A: " << this->name << " with weapon: " << &this->weapon << " created" << std::endl;

}

HumanA::~HumanA(void)
{
    std::cout << "Human A: " << this->name << " destructed" << std::endl;
}

void    HumanA::attack(void)
{
    std::cout << this->name << " attacks with their " << this->weapon.get_type() << std::endl;
}
