/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:51:59 by tas               #+#    #+#             */
/*   Updated: 2023/11/13 14:23:40 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* Constructors and Destructor */

Form::Form() : _FormName("F1"),  _signed(false), _gradeSign(25), _gradeExec(50)
{
    std::cout << "\x1b[38;5;43mForm default constructor called\x1b[0m" << std::endl;
}

Form::Form(const std::string name, const int gradeSign, const int gradeExec) :
_FormName(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    std::cout << "\x1b[38;5;2mForm constructor called" << std::endl;  
    if (_gradeSign < 1 || _gradeExec < 1)
        throw Form::GradeTooHighException();
    if (_gradeSign > 150 || _gradeExec > 150)
        throw Form::GradeTooLowException();  
}

Form::Form(const Form &copy) : _FormName(copy._FormName), _signed(copy._signed), _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec)
{
    std::cout << "\x1b[38;5;114mForm Copy constructor called\x1b[0m" << std::endl;
}

Form::~Form()
{
    std::cout << "\x1b[38;5;124mForm default destructor called\x1b[0m" << std::endl;
}

/* Operators */

Form &Form::operator=(const Form &assign)
{
    std::cout << "\x1b[38;5;138mForm Copy assignement operation called\x1b[0m" << std::endl;
    this->_signed= assign._signed;
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const Form &c)
{
    out << "Form: " << c.getNameForm() << "grade: " << c.getGradeSign() << " status: " << c.getSigned() << "\ntrue if signed, false if not." << std::endl;
	return (out);
}

/* getters */

std::string Form::getNameForm() const
{
    return (this->_FormName);    
}

int Form::getGradeSign() const
{
    return (this->_gradeSign);
}

int Form::getGradeExec() const
{
    return (this->_gradeExec);
}

bool Form::getSigned() const
{
    return (this->_signed);
}

/* member functions */

void Form::beSigned(Bureaucrat &b)
{
    if (this->_signed == false)
    {
        if (b.getGrade() >= _gradeSign)
            throw Form::GradeTooLowException();
        else
            _signed = true;
    }
    else
        throw Form::AlreadySigned();
}
