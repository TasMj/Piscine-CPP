/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:30:59 by tas               #+#    #+#             */
/*   Updated: 2023/06/11 12:55:03 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

/******************************************************************************/
/*                            includes                                        */
/******************************************************************************/

#include <string>
#include <iostream>

/******************************************************************************/
/*                             classes                                        */
/******************************************************************************/

class Weapon
{
    public:
    
        Weapon(std::string type);
        ~Weapon(void);
        std::string const   &get_type(void);
        void                set_type(std::string new_value);
        
    private:
    
        std::string type;
};

#endif