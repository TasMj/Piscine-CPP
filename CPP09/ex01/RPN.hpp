/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:53:46 by tas               #+#    #+#             */
/*   Updated: 2023/12/26 15:15:38 by tas              ###   ########.fr       */
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
#include <sstream>
#include <stdlib.h>

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

	private:
		std::stack<int> numbers;
};

int parseArgv(std::string str);

#endif