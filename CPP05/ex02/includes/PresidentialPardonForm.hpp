/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:47:05 by tas               #+#    #+#             */
/*   Updated: 2023/11/13 18:47:07 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

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

class PresidentialPardonForm : public AForm
{
    public:
        /* constructors */
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &targetFile);
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        
        /* operator */
        PresidentialPardonForm &operator=(const PresidentialPardonForm &assign);
        
        /* destructor */
        ~PresidentialPardonForm();

        /* member function */
        void to_execute(Bureaucrat const &executor) const;

    private:
        std::string _targetFile;

};

#endif
