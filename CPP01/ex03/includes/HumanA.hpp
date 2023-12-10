/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:33:15 by tas               #+#    #+#             */
/*   Updated: 2023/06/11 13:03:26 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

/******************************************************************************/
/*                            includes                                        */
/******************************************************************************/

#include <string>
#include <iostream>
#include "Weapon.hpp"

/******************************************************************************/
/*                             classes                                        */
/******************************************************************************/

class   HumanA
{
    public:

        HumanA(std::string name, Weapon &Weapon);
        ~HumanA(void);
        void    attack(void);
        
    private:
        
        std::string name;
        Weapon      &weapon;
};

#endif