/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:23:11 by tmejri            #+#    #+#             */
/*   Updated: 2023/12/12 00:31:52 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge.hpp"

/*
x seq d'entier positif comme arg
- trier entier avec l'algo de ford-Johnson
- msg d'erreur precis en fonction de l'erreur
- au moins 2 conteneurs
- etre capable de gerer au moins 3000 entiers differents
- - Il est fortement conseillé d'implémenter votre algorithme pour chaque conteneur
et donc d'éviter d'utiliser une fonction générique.

affichage:
- 1ere ligne: afficher un texte explicite suivi de la seq d'entiers positifs non tries
- 2eme ligne: same mais trie
- 3eme ligne: afficher texte indiquant tmps utilise par l'algo en précisant le premier conteneur utilisé pour trier la suite d'entiers positifs.
- 4eme ligne: afficher un texte explicite indiquant le temps utilisé par votre algorithme en spécifiant le deuxième conteneur utilisé pour trier la séquence d'entiers positifs.
votre algorithme en spécifiant le deuxième conteneur utilisé pour trier la suite d'entiers positifs.

- Le format d'affichage du temps utilisé pour effectuer votre tri
est libre mais la précision choisie doit permettre de bien voir la différence
entre les deux conteneurs utilisés.

- L'indication de l'heure est volontairement étrange dans cet exemple.
Vous devez bien sûr indiquer le temps utilisé pour effectuer toutes vos
opérations, aussi bien la partie tri que la partie gestion des données.
*/

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "\x1b[38;5;205mError: no argument\x1b[0m" << std::endl;
        return (0);
    }
    PmergeMe P;
    if (P.parseArgs(argc, argv) == false)
        return (0);
    P.displayRes();
}

/*
int main() 
{
    std::deque<int> arr;

    arr.push_back(7);
    arr.push_back(123);
    arr.push_back(99);
    arr.push_back(56);
    arr.push_back(0);
    arr.push_back(15);
    arr.push_back(14);
    arr.push_back(51);
    arr.push_back(751);
    arr.push_back(11);
    arr.push_back(178);
    arr.push_back(71);
    arr.push_back(221);
    arr.push_back(2151);
    arr.push_back(41);

    fordJohnsonSort(arr);

    for (int i = 0; i <= 15; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
*/