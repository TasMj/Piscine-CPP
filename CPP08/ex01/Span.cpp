/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:11:14 by tas               #+#    #+#             */
/*   Updated: 2023/12/26 00:41:49 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* constructors & destructor */
Span::Span() : _size(0)
{
	std::cout << "\x1b[38;5;43mSpan default constructor called\x1b[0m" << std::endl;
}

Span::Span(unsigned int N) : _size(N)
{
	std::cout << "\x1b[38;5;43mSpan constructor called\x1b[0m" << std::endl;
}

Span::Span(const Span &copy) : _size(copy._size), _tab(copy._tab)
{
	std::cout << "\x1b[38;5;114mSpan Copy constructor called\x1b[0m" << std::endl;
}

Span::~Span()
{
	std::cout << "\x1b[38;5;124mSpan destructor called\x1b[0m" << std::endl;
}

/* operator */
Span &Span::operator=(const Span &assign)
{
	if (this != &assign)
	{
		this->_size = assign._size;
		this->_tab = assign._tab;
	}
	return (*this);
}

/* function member */
void	Span::addNumber(int nb)
{
	if (_tab.size() == _size)
		throw Span::TooMuchElemException();
	else
		_tab.push_back(nb);
}

unsigned int	Span::longestSpan()
{
	if (_tab.size() <= 1)
		throw Span::EmptySpanException();
	std::vector<int> copyTab;
	copyTab = _tab;
	std::sort(copyTab.begin(), copyTab.end());
	return (abs(copyTab.back() - copyTab.front()));
}

unsigned int	Span::shortestSpan()
{
	if (_tab.size() <= 1)
		throw Span::EmptySpanException();

	std::vector<int> copyTab;
	copyTab = _tab;
	std::sort(copyTab.begin(), copyTab.end());

	std::vector<int> distElm;
	for (unsigned int i = 0; i < copyTab.size() - 1; i++)
	{
		distElm.push_back(copyTab[i + 1] - copyTab[i]);
	}
	int min;
	for (unsigned int i = 0; i < distElm.size() - 1; i++)
	{
		if (distElm[i] <= distElm[i + 1])
			min = distElm[i];
	}
	return (min);
}

void	Span::printTab()
{
	for (unsigned int i = 0; i < _tab.size(); i++)
	{
		std::cout << _tab[i] << std::endl;
	}
}

int	Span::getSize()
{
	return (this->_size);
}

int	randomInRange(int min, int max)
{
    return min + (rand() % (max - min + 1));
}

void Span::RangeOfIterators(std::vector<int>::iterator	begin, std::vector<int>::iterator end)
{
	if ((end - begin) + _tab.size() > _size)
		throw Span::TooMuchElemException();
	this->_tab.insert(_tab.end(), begin, end);
}
