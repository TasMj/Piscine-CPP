/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:23:11 by tmejri            #+#    #+#             */
/*   Updated: 2023/12/16 02:36:16 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
x seq d'entier positif comme arg
x trier entier avec l'algo de ford-Johnson
x msg d'erreur precis en fonction de l'erreur
x au moins 2 conteneurs
- etre capable de gerer au moins 3000 entiers differents
x Il est fortement conseillé d'implémenter votre algorithme pour chaque conteneur
et donc d'éviter d'utiliser une fonction générique.

affichage:
x 1ere ligne: afficher un texte explicite suivi de la seq d'entiers positifs non tries
x 2eme ligne: same mais trie
x 3eme ligne: afficher texte indiquant tmps utilise par l'algo en précisant le premier conteneur utilisé pour trier la suite d'entiers positifs.
x 4eme ligne: afficher un texte explicite indiquant le temps utilisé par votre algorithme en spécifiant le deuxième conteneur utilisé pour trier la séquence d'entiers positifs.
votre algorithme en spécifiant le deuxième conteneur utilisé pour trier la suite d'entiers positifs.

x Le format d'affichage du temps utilisé pour effectuer votre tri
est libre mais la précision choisie doit permettre de bien voir la différence
entre les deux conteneurs utilisés.

x L'indication de l'heure est volontairement étrange dans cet exemple.
Vous devez bien sûr indiquer le temps utilisé pour effectuer toutes vos
opérations, aussi bien la partie tri que la partie gestion des données.
*/

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << PINK << "Error: no argument" << EOC << std::endl;
        return (0);
    }
    PmergeMe P;
    if (P.parseArgs(argc, argv) == false)
        return (0);
    P.displayRes();
}
