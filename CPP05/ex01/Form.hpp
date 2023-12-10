/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:50:39 by tas               #+#    #+#             */
/*   Updated: 2023/11/13 13:38:10 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

#include <iostream>
#include <string.h>
#include "Bureaucrat.hpp"

/******************************************************************************/
/*                                   Classes                                  */
/******************************************************************************/

class Form
{
    public:

		/* Canionical */
        Form();
        Form(const std::string name, const int grade, const int gradeExec);
        Form(const Form &copy);
        Form &operator=(const Form &assign);
        ~Form();
        
        /* gatters */
        std::string getNameForm() const;
		int getGradeSign() const;
		int getGradeExec() const;
        bool getSigned() const;

        /* member functions */
        void beSigned(Bureaucrat &b);
        
        /* exceptions */
        class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Form: Grade too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Form: Grade too low");
				}
		};
        
        class AlreadySigned : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Form: already signed");
				}
		};
        
    private:
    
        const std::string   _FormName;
        bool                _signed;
        const int           _gradeSign;
        const int           _gradeExec;

};

std::ostream &operator<<(std::ostream &out, const Form &c);

#endif