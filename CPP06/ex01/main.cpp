/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:40:50 by tas               #+#    #+#             */
/*   Updated: 2023/11/17 13:38:37 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main()
{
    Data d;
    d.str = "Ceci est un test !";
    d.n = 23;
    
    // Convertit l'adresse de la structure Data en un entier non signé
    uintptr_t ptr = Serializer::serialize(&d);
    // Convertit l'entier non signé en un pointeur vers la structure Data
    Data *Deserialized = Serializer::deserialize(ptr);
    
    std::cout << "int: " << Deserialized->n << std::endl;
    std::cout << "string: " << Deserialized->str << std::endl;

    if (Deserialized == &d) 
        std::cout << "La désérialisation a réussi : le pointeur est le même que celui d'origine !" << std::endl;
    else
        std::cout << "Erreur : le pointeur obtenu après désérialisation est différent du pointeur d'origine." << std::endl;
}
