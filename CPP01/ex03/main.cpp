/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:36:23 by tas               #+#    #+#             */
/*   Updated: 2023/06/11 12:53:44 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Weapon.hpp"
#include "./includes/HumanA.hpp"
#include "./includes/HumanB.hpp"

int main(void)
{
    {
        Weapon  club = Weapon("crude spiked club");
    
        HumanA bob("Bob", club);
        bob.attack();
        club.set_type("some other type of club");
        bob.attack();
    }
    {
        Weapon  club = Weapon("crude spiked club");
    
        HumanB jim("Jim");
        jim.set_weapon(club);
        jim.attack();
        club.set_type("some other type of club");
        jim.attack();
    }
    return 0;
}