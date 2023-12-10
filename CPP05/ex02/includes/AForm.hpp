/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:50:39 by tas               #+#    #+#             */
/*   Updated: 2023/11/13 16:51:32 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

#include <iostream>
#include <string.h>

/******************************************************************************/
/*                                   Classes                                  */
/******************************************************************************/

class Bureaucrat;

class AForm
{
    public:

		/* Canionical */
        AForm();
        AForm(const std::string name, const int grade, const int gradeExec);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &assign);
        ~AForm();
        
        /* gatters */
        std::string getNameAForm() const;
		int getGradeSign() const;
		int getGradeExec() const;
        bool getSigned() const;

        /* member functions */
        void beSigned(Bureaucrat &b);
		void execute(Bureaucrat const &executor) const;
        virtual void to_execute(Bureaucrat const &executor) const = 0;

        /* exceptions */
        class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("AForm: Grade too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("AForm: Grade too low");
				}
		};
        
        class AlreadySigned : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("AForm: already signed");
				}
		};
		
		class FormNotSigned : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("AForm: form not signed");
				}
		};
		
		class FileNotOpen : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("AForm: file not open");
				}
		};
        
    private:
    
        const std::string   _AFormName;
        bool                _signed;
        const int           _gradeSign;
        const int           _gradeExec;

};

std::ostream &operator<<(std::ostream &out, const AForm &c);

#endif