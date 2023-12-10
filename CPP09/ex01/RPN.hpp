/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:53:46 by tas               #+#    #+#             */
/*   Updated: 2023/11/24 16:24:25 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

#include <iostream>
#include <string>
#include <stack>


/******************************************************************************/
/*                                   Classes                                  */
/******************************************************************************/

class RPN
{
    public:
        /* constructors and destructor */
		RPN();
		~RPN();
		RPN(const RPN &copy);

		/* operator */
		RPN &operator=(const RPN &cpy);
		
		/* function member */
		void	doCalcul(std::string str);
		void	fillStack(std::string str);
		void	fillSaveStack();

	private:
		std::stack<int> stackNbr;
		std::stack<int> saveStack;
};

int parseArgv(std::string str);
int countNbr(std::string operation);

#endif