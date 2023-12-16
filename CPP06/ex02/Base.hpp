/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:38:58 by tas               #+#    #+#             */
/*   Updated: 2023/12/15 19:57:09 by tmejri           ###   ########.fr       */
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

Base *generate(void); //instancie aléatoirement A B ou C et renvoie l'instance sous la forme d'un pointeur Base
void identify(Base *p); //affiche le type réel de l'objet pointé par p : "A", "B" ou "C".
void identify(Base &p); //same mais dereference le pointeur p --> au lieu du pointeur, la fonction identify() sera appelée avec l'objet réel de type Base

#endif