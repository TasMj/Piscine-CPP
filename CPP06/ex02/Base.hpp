/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:38:58 by tas               #+#    #+#             */
/*   Updated: 2023/11/17 14:23:02 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

#include <iostream>
#include <string.h>
#include <cstdlib>

/******************************************************************************/
/*                                   Classes                                  */
/******************************************************************************/


class Base
{
    public:

        virtual ~Base();
};

class A : public Base
{
    
};

class B : public Base
{
    
};

class C : public Base
{
    
};

Base * generate(void); //instancie aléatoirement A B ou C et renvoie l'instance sous la forme d'un pointeur Base
void identify(Base* p); //Il affiche le type réel de l'objet pointé par p : "A", "B" ou "C".
void identify(Base& p); //Il affiche le type réel de l'objet pointé par p : "A", "B" ou "C". L'utilisation d'un pointeur à l'intérieur de cette fonction est interdite.

#endif