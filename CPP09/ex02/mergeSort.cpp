/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:08:50 by tmejri            #+#    #+#             */
/*   Updated: 2023/12/11 18:58:40 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge.hpp"
#include <queue>

/*
1) diviser en 2 chaque bloc jusqu'a otenir des blocs de 1
2) compare n et n + 1 pour les remettre dans l'ordre dans le bloc de 2 precedent.
3) comparer le premier du bloc avec le 2 eme du bloc pour le placer dans le bloc du dessus
et ainsi de suite.
si

2 7  -  5 9
comparer 2 et 5
puis 7 et 5

2
7   -   5 9

2 5
7   -   9

2 5 7 9

et ainsi de suite
*/

void    PmergeMe::seperateContent(std::vector<int> args)
{
    for (int i = 0; i <= (sizeArg/2); i++)
    {
		// 1er container dequeue
		//creer container et push la moitier du vector args
    }
    for (int i = 0; i <= (sizeArg/2); i++)
    {
		// 2eme container dequeue
		//creer container et push la moitier du vector args
    }

	//tant que la taille des cont n'est pas = a 2 on divise en cont.size()/2
	// une fois arrive a des cont de taille 2 comparer avec
	
}

std::deque<int>	PmergeMe::leftCont(std::deque<int> cont)
{
	std::deque<int> halfCont;
	for (int i = 0; i <= (cont.size()/2); i++)
	{
		halfCont.push_back(cont.front());
	}
}

std::deque<int>	PmergeMe::rightCont(std::deque<int> cont)
{
	std::deque<int> halfCont;
	for (int i = cont.size()/2; i <= cont.size(); i++)
	{
		halfCont.push_back(cont.front());
	}
}


void	PmergeMe::mergeSort(std::deque<int> leftCont, std::deque<int> rightCont)
{
	
}