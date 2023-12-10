/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:17:32 by tas               #+#    #+#             */
/*   Updated: 2023/11/13 16:51:39 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

#include <iostream>
#include <string.h>

/******************************************************************************/
/*                                   Classes                                  */
/******************************************************************************/

class AForm;

class Bureaucrat
{
    public:

		/* Canionical */
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &assign);
        ~Bureaucrat();
		
		/* gatters */
		std::string getName() const;
		int getGrade() const;		

		/* function member */
		void setGrade(int grade);
		void AddGrade();
		void decreaseGrade();
		void signAForm(AForm &f);
		void executeAForm(AForm const &f);
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade too low");
				}
		};
        
	private:
		
		const std::string	_name;
    	int					_grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &c);

#endif