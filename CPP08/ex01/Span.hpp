/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:02:35 by tas               #+#    #+#             */
/*   Updated: 2023/11/22 14:17:07 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

/******************************************************************************/
/*                                  Class                                     */
/******************************************************************************/

class Span
{
    public:
        /* constructors and destructor */
        Span();
        Span(unsigned int N);
        Span(const Span &copy);
        ~Span();

        /* operators */
        Span & operator=(const Span &assign);
        
        /* function member */
        void    addNumber(int nb);
        int     shortestSpan();
        int     longestSpan();

        void	printTab();
        int     getSize();
        void    RangeOfIterators(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end);
        
        /* exceptions */
        class TooMuchElemException : public std::exception
        {
        	public:
        		const char	*what(void) const throw()
        		{
        			return ("\x1b[38;5;125mSorry, there is already too much element. We can't add this element\x1b[0m");
        		}
        };
        class EmptySpanException : public std::exception
        {
        	public:
        		const char	*what(void) const throw()
        		{
        			return ("\x1b[38;5;125mSorry, the Span is empty or only has one number\x1b[0m");
        		}
        };
        
    private:
        unsigned int                 _size;
        std::vector<unsigned int>    _tab;
};

int	randomInRange(int min, int max);

#endif