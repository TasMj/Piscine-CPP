/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:26:08 by tmejri            #+#    #+#             */
/*   Updated: 2023/12/11 19:55:16 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge.hpp"

/* canonical functions */
PmergeMe::PmergeMe()
{
    std::cout << "\x1b[38;5;43mPmergeMe default constructor called\x1b[0m" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    std::cout << "\x1b[38;5;114mPmergeMe Copy constructor called\x1b[0m" << std::endl;
	if (this != &copy)
		*this = copy;
}
	
PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
    std::cout << "\x1b[38;5;138mPmergeMe Copy assignement operation called\x1b[0m" << std::endl;
	(void)copy;
    return (*this);
}

PmergeMe::~PmergeMe()
{
    std::cout << "\x1b[38;5;124mPmergeMe destructor called\x1b[0m" << std::endl;
}

/* functions */
bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

bool parseArgs(int argc, char **argv)
{
	std::vector<std::string> args;
	std::vector<std::string>::iterator it;

	for (int i = 1; i < argc; i++)
		args.push_back(argv[i]);

	for(it = args.begin(); it < args.end(); it++)
	{
		if (is_number(*it) == false)
		{
        	std::cout << "\x1b[38;5;205mError\x1b[0m" << *it << std::endl;
			return (false);
		}
	}
	// sizeArg = i;
	return (true);
}

void	PmergeMe::printBefore()
{
	if (args.size() < 4)
	{
		for (int i = 0; i < args.size(); i++)
			std::cout << args[i] << " ";
	}
	else
	{
		for (int i = 0; i <= 4; i++)
			std::cout << args[i] << " ";
		std::cout << " [...]" << std::endl;
	}
}

void	PmergeMe::displayRes()
{
/*affichage:
- 1ere ligne: afficher un texte explicite suivi de la seq d'entiers positifs non tries
*/

std::cout << "Before";
printBefore();

/*
- 2eme ligne: same mais trie
- 3eme ligne: afficher texte indiquant tmps utilise par l'algo en précisant le premier conteneur utilisé pour trier la suite d'entiers positifs.
- 4eme ligne: afficher un texte explicite indiquant le temps utilisé par votre algorithme en spécifiant le deuxième conteneur utilisé pour trier la séquence d'entiers positifs.
votre algorithme en spécifiant le deuxième conteneur utilisé pour trier la suite d'entiers positifs.
*/
}