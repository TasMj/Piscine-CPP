/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:21:03 by tas               #+#    #+#             */
/*   Updated: 2023/12/26 00:52:27 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

#include <iostream>
#include <string>
#include <stack>
#include <list>
#include <cstdio>

/******************************************************************************/
/*                                  Class                                     */
/******************************************************************************/

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        /* constructors and destructor */
        MutantStack();
        MutantStack(const MutantStack &copy);
        ~MutantStack();

        /* operators */
        MutantStack & operator=(const MutantStack &assign);
        
        /* function member */
        // Alias pour l'itérateur
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator    begin();
        iterator    end();
};

/* constructors & desctructor */
template<typename T>
MutantStack<T>::MutantStack()
{
	std::cout << "\x1b[38;5;43mMutantStack default constructor called\x1b[0m" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &copy) : std::stack<T>(copy)
{
	std::cout << "\x1b[38;5;114mMutantStack Copy constructor called\x1b[0m" << std::endl;    
}

template<typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "\x1b[38;5;124mMutantStack destructor called\x1b[0m" << std::endl;
}

/* operaator*/
template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &assign)
{
    if (this != &assign)
        MutantStack<T>::stack::operator=(assign);
    return (*this);
}

/* fucntions */
template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (this->c.end());
}

#endif