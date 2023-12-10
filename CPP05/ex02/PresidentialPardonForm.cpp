/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:45:14 by tas               #+#    #+#             */
/*   Updated: 2023/11/13 19:01:28 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/PresidentialPardonForm.hpp"

/* constructors */
PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5), _targetFile("Default")
{
    std::cout << "\x1b[38;5;43mPresidential default constructor called\x1b[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &targetFile) : AForm("Presidential", 25, 5), _targetFile(targetFile)
{
    std::cout << "\x1b[38;5;2mPresidential constructor called\x1b[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : 
AForm(copy.getNameAForm(), copy.getGradeSign(), copy.getGradeExec()), _targetFile(copy._targetFile)
{
    std::cout << "\x1b[38;5;114mPresidential copy constructor called\x1b[0m" << std::endl;
}

/* operator */
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
    std::cout << "\x1b[38;5;138mPresidential Copy assignement operation called\x1b[0m" << std::endl;
    (void)assign;
    return (*this);

}

/* destructor */
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "\x1b[38;5;124mPresidential destructor called\x1b[0m" << std::endl;
}
/* member function */
void PresidentialPardonForm::to_execute(Bureaucrat const &executor) const
{
    this->execute(executor);
    std::cout << this->_targetFile << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
