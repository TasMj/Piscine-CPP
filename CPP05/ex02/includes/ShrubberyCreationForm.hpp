/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:03:34 by tas               #+#    #+#             */
/*   Updated: 2023/11/13 17:18:58 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

#include <iostream>
#include <string.h>
#include "AForm.hpp"
#include <fstream>

/******************************************************************************/
/*                                   Classes                                  */
/******************************************************************************/

class ShrubberyCreationForm : public AForm
{
    public:
        /* constructors */
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &targetFile);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        
        /* operator */
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &assign);
        
        /* destructor */
        ~ShrubberyCreationForm();

        /* member function */
        void to_execute(Bureaucrat const &executor) const;

    private:
        std::string _targetFile;

};

#endif
