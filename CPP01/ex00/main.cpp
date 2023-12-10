/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:46:44 by tas               #+#    #+#             */
/*   Updated: 2023/06/10 22:03:58 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie  a = Zombie("Anne_cha");
    Zombie  b = Zombie("Ambre");
    a.announce();
    b.announce();

    Zombie  *c = newZombie("Cao");
    c->announce();
    delete (c);

    randomChump("Jules");
        
    return (0);
}