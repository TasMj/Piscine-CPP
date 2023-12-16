/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:45:17 by tas               #+#    #+#             */
/*   Updated: 2023/12/15 19:49:19 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{
    std::cout << "\x1b[38;5;124mBase destructor called\x1b[0m" << std::endl;	
}

Base *generate(void)
{
    srand((unsigned int)time(NULL));
    int randomNb = rand() % 3;
    switch (randomNb)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p)) //opérateur de conversion entre classes liées par héritage
        std::cout << "p est de type A" << std::endl;
    if (dynamic_cast<B*>(p))
        std::cout << "p est de type B" << std::endl;
    if (dynamic_cast<C*>(p))
        std::cout << "p est de type C" << std::endl;
}

void identify(Base &p)
{
    identify(&p);
}
