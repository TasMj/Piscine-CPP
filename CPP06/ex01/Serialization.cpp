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

/* convert a pointer to an unsigned int sans effectuer de conversion réelles de données
--> Permet d'obtenir une représentation numérique du pointeur */
uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

/* convert from an unsigned int to a pointer */
Data*   Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}
