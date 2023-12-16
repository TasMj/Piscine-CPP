/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:17:16 by tas               #+#    #+#             */
/*   Updated: 2023/12/12 13:06:19 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Intern.hpp"

Intern::Intern()
{
    std::cout << "\x1b[38;5;43mIntern default constructor called\x1b[0m" << std::endl;
}

Intern::Intern(const Intern &copy)
{
    std::cout << "\x1b[38;5;114mIntern Copy constructor called\x1b[0m" << std::endl;
	*this = copy;
}
        
Intern &Intern::operator=(const Intern &assign)
{
    (void)assign;
    std::cout << "\x1b[38;5;138mIntern Copy assignement operation called\x1b[0m" << std::endl;
    return (*this);
}
        
Intern::~Intern()
{
    std::cout << "\x1b[38;5;124mIntern destructor called\x1b[0m" << std::endl;	
}

AForm *Intern::makeForm(std::string nameForm, std::string targetForm)
{
    int i = 0;
    AForm *NewForm = NULL;
    std::string listForm[3] = {"Presidential pardon", "Robotomy request", "Shrubbery creation"};
    
    for (i = 0; i < 3; i++)
	{
		if (nameForm == listForm[i])
			break;
	}
    switch (i)
    {
        case 0:
            NewForm = new PresidentialPardonForm(targetForm);
            break;
        case 1:
            NewForm = new RobotomyRequestForm(targetForm);
            break;
        case 2:
            NewForm = new ShrubberyCreationForm(targetForm);
            break;
        default:
        std::cout << "The form \x1b[38;5;138m" << nameForm << "\x1b[0m doesn't exist. Choose:\n  *Presidential pardon\n  *Robotomy reqest\n  *Shrubbery creation" << std::endl;
        return (NULL);
    }
    std::cout << "Intern creates \x1b[38;5;138m" << nameForm << "\x1b[0m" << std::endl;
    return (NewForm);
}
