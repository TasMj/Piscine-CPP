/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:17:37 by tas               #+#    #+#             */
/*   Updated: 2023/11/14 13:07:05 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

#include <iostream>
#include <string.h>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


/******************************************************************************/
/*                                   Classes                                  */
/******************************************************************************/

class Intern
{
    public:
        /* constructors */    
        Intern();
        Intern(const Intern &copy);
        
        /* operator */
        Intern &operator=(const Intern &assign);
        
        /* destructor */
        ~Intern();
        
        /* function member */
        AForm *makeForm(std::string nameForm, std::string targetForm);
};

#endif