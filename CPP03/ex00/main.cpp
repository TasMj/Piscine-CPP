/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:15:04 by tas               #+#    #+#             */
/*   Updated: 2023/10/05 13:50:45 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap    Perso("Tic");
    ClapTrap    PersoCpy(Perso);
    
    Perso.attack("Tac");
    Perso.takeDamage(3);
    Perso.takeDamage(1);
    Perso.beRepaired(2);
    Perso.takeDamage(10);
    return (0);
}