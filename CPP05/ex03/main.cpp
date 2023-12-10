/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:30:33 by tas               #+#    #+#             */
/*   Updated: 2023/11/14 13:50:25 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/AForm.hpp"
#include "./includes/Intern.hpp"
#include "./includes/Bureaucrat.hpp"
#include "./includes/ShrubberyCreationForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"

int main()
{
    std::cout << "\x1b[38;5;221m******************TEST INTERN******************" << std::endl;
    std::cout << "\x1b[38;5;221m--------------THAT WORKS--------------\x1b[0m" << std::endl;
    try
	{
		Intern	jade;
		Bureaucrat	ria("ria", 8);
		AForm	*f;
		AForm	*g;
		AForm	*h;
		(void)f;
		(void)g;
		(void)h;
		
		f = jade.makeForm("Presidential pardon", "a");
		g = jade.makeForm("Robotomy request", "b");
		h = jade.makeForm("Shrubbery creation", "c");
		
		delete f;
		delete g;
		delete h;
	}	
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
    std::cout << "\x1b[38;5;221m-----------THAT DOESN'T WORKS-----------\x1b[0m" << std::endl;
	try
	{
		Intern	kyle;
		Bureaucrat	rio("rio", 4);
		AForm	*i;
		AForm	*j;
		(void)i;
		(void)j;
		
		i = kyle.makeForm("random form", "d");
		j = kyle.makeForm("Prsidential pardon", "e");
	}	
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\x1b[38;5;221m***************************************************\x1b[0m" << std::endl;
	return (0);
}