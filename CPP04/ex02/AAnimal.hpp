/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:15:31 by tas               #+#    #+#             */
/*   Updated: 2023/10/06 13:20:28 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

#include <iostream>
#include <string.h>
#include "Brain.hpp"

/******************************************************************************/
/*                                   Classes                                  */
/******************************************************************************/

class AAnimal
{
	public:
    
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal &copy);
		AAnimal & operator=(const AAnimal &assign);
		virtual ~AAnimal();
		
		const std::string& GetType( void ) const; 
		virtual void makeSound( void ) const = 0;
		virtual Brain* GetBrain( void ) const = 0;
    	
    protected:
	
        std::string _type;
};

#endif