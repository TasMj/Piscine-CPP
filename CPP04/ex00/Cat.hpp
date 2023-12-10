/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:28:20 by tas               #+#    #+#             */
/*   Updated: 2023/10/06 11:33:41 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

#include <iostream>
#include <string.h>
#include "Animal.hpp"

/******************************************************************************/
/*                                   Classes                                  */
/******************************************************************************/

class Cat : public Animal
{
    public:

        Cat();
        Cat(const Cat &copy);
        Cat &operator=(const Cat &assign);
        ~Cat();

        void makeSound() const;
};

#endif