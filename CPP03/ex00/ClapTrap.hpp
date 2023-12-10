/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:14:58 by tas               #+#    #+#             */
/*   Updated: 2023/08/08 14:46:28 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

#include <iostream>
#include <string.h>

/******************************************************************************/
/*                                   Classes                                  */
/******************************************************************************/

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(std::string name);
	    ClapTrap(ClapTrap const &p);
        ClapTrap	&operator=(ClapTrap const &p);
        ~ClapTrap();
        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        
    private:
        std::string _name;
        int _hit;
        int _energy_point;
        int _attack_damage;
};

#endif