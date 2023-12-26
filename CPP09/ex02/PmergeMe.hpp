/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:25:29 by tmejri            #+#    #+#             */
/*   Updated: 2023/12/26 16:39:11 by tas              ###   ########.fr       */
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
#include <sys/time.h>

/******************************************************************************/
/*                                 Defines                                    */
/******************************************************************************/
#define EOC "\x1b[0m"
#define PINK "\x1b[38;5;200m"
#define PURPLE "\x1b[38;5;133m"
#define GREEN "\x1b[38;5;79m"

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
		void	fordJohnsonSortDeq(std::deque<int> &arr);
		void	fordJohnsonSortVec(std::vector<int> &arr);
		void	printDeq();
		void	displayRes();
		
    private:
		std::deque<int> dequeArr;
		std::vector<int> vectArr;
		timeval v_time_start;
		timeval v_time_end;
		timeval d_time_start;
		timeval d_time_end;
		double v_time;
		double d_time;
};

/******************************************************************************/
/*                                  Fonctions                                 */
/******************************************************************************/

bool	is_number(const std::string &s);
bool	isMax(const std::string &s);

#endif