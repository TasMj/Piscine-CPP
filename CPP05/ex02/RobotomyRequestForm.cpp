/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:45:42 by tas               #+#    #+#             */
/*   Updated: 2023/11/13 18:49:33 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"

/* constructors */
RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), _targetFile("Default")
{
    std::cout << "\x1b[38;5;43mRobotomy default constructor called\x1b[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &targetFile) : AForm("Robotomy", 72, 45), _targetFile(targetFile)
{
    std::cout << "\x1b[38;5;2mRobotomy constructor called\x1b[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : 
AForm(copy.getNameAForm(), copy.getGradeSign(), copy.getGradeExec()), _targetFile(copy._targetFile)
{
    std::cout << "\x1b[38;5;114mRobotomy copy constructor called\x1b[0m" << std::endl;
	*this = copy;
}

/* operator */
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
    std::cout << "\x1b[38;5;138mRobotomyRequestForm Copy assignement operation called\x1b[0m" << std::endl;
    (void)assign;
    return (*this);
}

/* destructor */
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "\x1b[38;5;124mRobotomyRequestForm destructor called\x1b[0m" << std::endl;	
}

/* member function */
void    RobotomyRequestForm::to_execute(Bureaucrat const &executor) const
{
	this->execute(executor);
	std::cout << "*Makes some drilling noises*" << std::endl;
	srand(time(NULL));
	int nb = rand();
	if (nb % 2 == 0)
		std::cout << _targetFile << " has been robotomized successfully " << std::endl;
	else
		std::cout << _targetFile << " has failed " << std::endl;
}