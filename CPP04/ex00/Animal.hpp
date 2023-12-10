/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:15:31 by tas               #+#    #+#             */
/*   Updated: 2023/10/06 11:24:41 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

#include <iostream>
#include <string.h>

/******************************************************************************/
/*                                   Classes                                  */
/******************************************************************************/

class Animal
{
	public:
    
		Animal();
		Animal(std::string type);
		Animal(const Animal &copy);
		Animal & operator=(const Animal &assign);
		virtual ~Animal();
		
		const std::string& GetType( void ) const; 
		virtual void makeSound( void ) const;
    	
    protected:
	
        std::string _type;
};

#endif