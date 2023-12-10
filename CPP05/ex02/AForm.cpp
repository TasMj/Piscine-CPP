/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:51:59 by tas               #+#    #+#             */
/*   Updated: 2023/11/09 18:14:01 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/AForm.hpp"
#include "./includes/Bureaucrat.hpp"

/* Constructors and Destructor */

AForm::AForm() : _AFormName("F1"),  _signed(false), _gradeSign(25), _gradeExec(50)
{
    std::cout << "\x1b[38;5;43mAForm default constructor called\x1b[0m" << std::endl;
}

AForm::AForm(const std::string name, const int gradeSign, const int gradeExec) :
_AFormName(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    std::cout << "\x1b[38;5;2mAForm constructor called" << std::endl;  
    if (_gradeSign < 1 || _gradeExec < 1)
        throw AForm::GradeTooHighException();
    if (_gradeSign > 150 || _gradeExec > 150)
        throw AForm::GradeTooLowException();  
}

AForm::AForm(const AForm &copy) : _AFormName(copy._AFormName), _signed(copy._signed), _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec)
{
    std::cout << "\x1b[38;5;114mAForm Copy constructor called\x1b[0m" << std::endl;
}

AForm::~AForm()
{
    std::cout << "\x1b[38;5;124mAForm default destructor called\x1b[0m" << std::endl;
}

/* Operators */

AForm &AForm::operator=(const AForm &assign)
{
    std::cout << "\x1b[38;5;138mAForm Copy assignement operation called\x1b[0m" << std::endl;
    this->_signed= assign._signed;
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const AForm &c)
{
    out << "AForm: " << c.getNameAForm() << "grade: " << c.getGradeSign() << " status: " << c.getSigned() << "\ntrue if signed, false if not." << std::endl;
	return (out);
}

/* getters */

std::string AForm::getNameAForm() const
{
    return (this->_AFormName);    
}

int AForm::getGradeSign() const
{
    return (this->_gradeSign);
}

int AForm::getGradeExec() const
{
    return (this->_gradeExec);
}

bool AForm::getSigned() const
{
    return (this->_signed);
}

/* member functions */

void AForm::beSigned(Bureaucrat &b)
{
    if (this->_signed == false)
    {
        if (b.getGrade() >= _gradeSign)
            throw AForm::GradeTooLowException();
        else
            _signed = true;
    }
    else
        throw AForm::AlreadySigned();
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	if (this->getSigned() == false)
		throw AForm::FormNotSigned();
}
