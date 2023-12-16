/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:40:50 by tas               #+#    #+#             */
/*   Updated: 2023/12/15 19:38:16 by tmejri           ###   ########.fr       */
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
    
    // std::cout << "int: " << Deserialized->n << std::endl;
    // std::cout << "string: " << Deserialized->str << std::endl;
    // std::cout << std::endl;

    if (Deserialized == &d)
        std::cout << "Réussi : le pointeur est le même que celui d'origine !" << std::endl;
    else
        std::cout << "Erreur : le pointeur obtenu après désérialisation est différent du pointeur d'origine." << std::endl;
}
