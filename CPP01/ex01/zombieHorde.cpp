/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 22:11:12 by tas               #+#    #+#             */
/*   Updated: 2023/06/11 11:04:31 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie  *zombieHorde(int N, std::string name)
{
    int i;
    Zombie  *z;
    
    i = 0;
    z = new Zombie[N];
    while (N > 0)
    {
        z[i].set_name(name);
        N--;
        i++;
    }
    return (z);
}