/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:25:29 by tmejri            #+#    #+#             */
/*   Updated: 2023/12/11 18:53:10 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <deque>

/******************************************************************************/
/*                                   Classes                                  */
/******************************************************************************/

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe& operator=(const PmergeMe &cpy);

		/* function member */
		// void	seperateContent(std::vector<int> args);
		void	divCont(std::deque<int> halfCont);
		void	mergeSort(std::deque<int> leftCont, std::deque<int> rightCont);

    private:
		int	sizeArg;
		std::deque<int> sortedCont;
};

/******************************************************************************/
/*                                  Fonctions                                 */
/******************************************************************************/

bool parseArgs(int argc, char **argv);


/******************************************************************************/
/*                                  Container                                 */
/******************************************************************************/





#endif