/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:57:33 by tas               #+#    #+#             */
/*   Updated: 2023/11/16 14:02:39 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serializer::Serializer()
{
    std::cout << "\x1b[38;5;43mSerializer default constructor called\x1b[0m" << std::endl;
}

Serializer::Serializer(const Serializer &copy)
{
    std::cout << "\x1b[38;5;114mSerializer Copy constructor called\x1b[0m" << std::endl;
	*this = copy;
}

Serializer &Serializer::operator=(const Serializer &assign)
{
    std::cout << "\x1b[38;5;138mSerializer Copy assignement operation called\x1b[0m" << std::endl;
    (void)assign;
	return (*this);
}

Serializer::~Serializer()
{
    std::cout << "\x1b[38;5;124mSerializer destructor called\x1b[0m" << std::endl;	
}

/* prend un pointeur et le convertit en un entier non signé de type uintptr_t */
uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr)); //reinterpret_cast = operateur de conversion
}

/* prend un paramètre entier non signé et le convertit en un pointeur sur Data.*/
Data*   Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}
