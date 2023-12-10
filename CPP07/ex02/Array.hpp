/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:01:08 by tas               #+#    #+#             */
/*   Updated: 2023/11/21 14:19:22 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

#include <iostream>
#include <string.h>

/******************************************************************************/
/*                                  Class                                     */
/******************************************************************************/

template<typename T>

class Array
{
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &copy);
        ~Array();

        Array& operator=(const Array &assign);
        T & operator[]( size_t index) const;

        unsigned int size() const;

        class InvalidIndex : public std::exception
	    {
	    	virtual const char *what() const throw()
	    	{
	    		return "Invalid index";
	    	}
	    };
        
    private:
        T               *_elmTab;
        unsigned int    _size;
};

template<typename T>
Array<T>::Array() : _elmTab(new T[0]), _size(0)
{
    std::cout << "\x1b[38;5;43mArray default constructor called\x1b[0m" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n) : _elmTab(new T[n]), _size(n)
{
    std::cout << "\x1b[38;5;43mArray constructor called\x1b[0m" << std::endl;
}

template<typename T>
Array<T>::Array(const Array &copy) : _elmTab(new T[copy._size]), _size(copy._size)
{
    std::cout << "\x1b[38;5;114mArray Copy constructor called\x1b[0m" << std::endl;
    if (this != &copy)
    {
        for (unsigned int i = 0; i < copy._size; i++)
            _elmTab[i] = copy._elmTab[i];
    }
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &assign)
{
    std::cout << "\x1b[38;5;138mArray Copy assignement operation called\x1b[0m" << std::endl;
    if (this != &assign)
    {
        delete[](_elmTab);
        
        _elmTab = new T[assign._size];
        _size = assign._size;
        for (size_t i = 0; i < _size; i++)
            _elmTab[i] = assign[i];
    }
    return (*this);
}

template<typename T>
unsigned int    Array<T>::size() const
{
    return (this->_size);
}

template<typename T>
T &Array<T>::operator[](size_t index) const
{
    if (index >= _size)
        throw Array::InvalidIndex();
    return (this->_elmTab[index]);
}


template<typename T>
Array<T>::~Array()
{
    std::cout << "\x1b[38;5;124mArray destructor called\x1b[0m" << std::endl;
    delete[] _elmTab;
}

#endif