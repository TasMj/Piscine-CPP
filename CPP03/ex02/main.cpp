/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:23:12 by tas               #+#    #+#             */
/*   Updated: 2023/10/05 14:11:16 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	ClapTrap b("AnneCha");
	FragTrap a("Ambre");
	a.attack("Jules");
	b.attack("Jules");
	a.highFivesGuys();
	return (0);
}