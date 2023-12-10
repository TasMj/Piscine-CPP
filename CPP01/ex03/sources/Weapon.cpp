/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:32:51 by tas               #+#    #+#             */
/*   Updated: 2023/06/11 13:02:18 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->type = type;
    std::cout << "Weapon: " << this->type << " constructor called" << std::endl;
}

Weapon::~Weapon(void)
{
    std::cout << "Weapon: " << this->type << " destructor called" << std::endl;
}

std::string const   &Weapon::get_type(void)
{
    return (this->type);
}

void    Weapon::set_type(std::string new_value)
{
    this->type = new_value;
}
