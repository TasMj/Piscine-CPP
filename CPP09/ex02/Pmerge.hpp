/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:25:29 by tmejri            #+#    #+#             */
/*   Updated: 2023/12/12 01:03:33 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
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
		bool	parseArgs(int argc, char **argv);
		void	fillVec(std::vector<std::string> args);
		void	fillDeq(std::vector<std::string> args);
		void	addNbr(const std::string &s);
		
		void	addNbrDeq(const std::string &s);
		
		
		void	printList(std::vector<int> cont);
		void	fordJohnsonSortDeq(std::deque<int> &arr);
		void	printDeq();
		void	displayRes();


		// void	fordJohnsonSortDeq(std::deque<int>& arr);
		// void	fordJohnsonSortVec(std::vector<int>& arr);
		// void	displayRes();
		// void	printBefore();

    private:
		// int	sizeArg;
		// std::vector<int> args;
		std::deque<int> dequeArr;
		std::vector<int> vectArr;
		timeval v_time;
		timeval v_time_end;
		timeval d_time;
		timeval d_time_end;
		double v_time_print;
		double d_time_print;
};

/******************************************************************************/
/*                                  Fonctions                                 */
/******************************************************************************/

bool	is_number(const std::string &s);
bool	isMax(const std::string &s);


/******************************************************************************/
/*                                  Container                                 */
/******************************************************************************/





#endif