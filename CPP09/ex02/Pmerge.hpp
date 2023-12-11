/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:25:29 by tmejri            #+#    #+#             */
/*   Updated: 2023/12/11 19:50:38 by tmejri           ###   ########.fr       */
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
		void	fordJohnsonSortDeq(std::deque<int>& arr);
		void	fordJohnsonSortVec(std::vector<int>& arr);
		void	displayRes();
		void	printBefore();

    private:
		int	sizeArg;
		std::vector<int> args;
		std::deque<int> dequeArr;
		std::vector<int> vectArr;
};

/******************************************************************************/
/*                                  Fonctions                                 */
/******************************************************************************/

bool parseArgs(int argc, char **argv);
void fordJohnsonSort(std::deque<int>& arr);


/******************************************************************************/
/*                                  Container                                 */
/******************************************************************************/





#endif