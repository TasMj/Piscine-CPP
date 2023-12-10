/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:23:12 by tas               #+#    #+#             */
/*   Updated: 2023/10/05 14:05:28 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	ScavTrap perso1("Lala");
	ClapTrap perso2("Po");
	ScavTrap a = perso1;
	ScavTrap b(perso1);
	b.attack("Dipsie");
	b.takeDamage(8);
	b.guardGate();
	perso2.attack("Tinkiwinkie");
	return (0);
}
