/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:42:46 by tas               #+#    #+#             */
/*   Updated: 2023/11/13 17:43:51 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

#include <iostream>
#include <string.h>
#include "AForm.hpp"
#include <fstream>
#include <time.h>
#include <cstdlib>

/******************************************************************************/
/*                                   Classes                                  */
/******************************************************************************/

class RobotomyRequestForm : public AForm
{
    public:
        /* constructors */
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &targetFile);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        
        /* operator */
        RobotomyRequestForm &operator=(const RobotomyRequestForm &assign);
        
        /* destructor */
        ~RobotomyRequestForm();

        /* member function */
        void to_execute(Bureaucrat const &executor) const;

    private:
        std::string _targetFile;

};

#endif