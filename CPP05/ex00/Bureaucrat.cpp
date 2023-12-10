/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:20:01 by tas               #+#    #+#             */
/*   Updated: 2023/11/13 13:14:02 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("X"), _grade(0)
{
    std::cout << "\x1b[38;5;43mBureaucrat default constructor called\x1b[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    std::cout << "\x1b[38;5;2mBureaucrat constructor called\x1b[0m" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}


Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
    std::cout << "\x1b[38;5;114mBureaucrat Copy constructor called\x1b[0m" << std::endl;
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &assign)
{
    std::cout << "\x1b[38;5;138mBureaucrat Copy assignement operation called\x1b[0m" << std::endl;
    this->_grade = assign._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "\x1b[38;5;124mBureaucrat destructor called\x1b[0m" << std::endl;	
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

void	Bureaucrat::AddGrade()
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decreaseGrade()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &c)
{
	out << c.getName() << "\x1b[38;5;198m, bureaucrat grade\x1b[0m" << c.getGrade() << std::endl;
	return (out);
}