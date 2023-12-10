/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:30:27 by tas               #+#    #+#             */
/*   Updated: 2023/10/05 19:34:59 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

#include <iostream>
#include <string.h>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

/******************************************************************************/
/*                                   Classes                                  */
/******************************************************************************/

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
	    FragTrap(FragTrap const &p);
        FragTrap &operator=(FragTrap const &p);
        ~FragTrap();

        void attack(const std::string &target);
        void highFivesGuys();

};


#endif