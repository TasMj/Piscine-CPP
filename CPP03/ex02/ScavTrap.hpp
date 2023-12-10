/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:41:18 by tas               #+#    #+#             */
/*   Updated: 2023/08/19 15:17:57 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

#include <iostream>
#include <string.h>
#include "ClapTrap.hpp"

/******************************************************************************/
/*                                   Classes                                  */
/******************************************************************************/

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const &p);
    ScavTrap &operator=(ScavTrap const &p);
    ~ScavTrap();
    
    void attack(const std::string &target);
    void guardGate();
};

#endif