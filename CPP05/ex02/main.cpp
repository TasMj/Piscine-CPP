/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:30:33 by tas               #+#    #+#             */
/*   Updated: 2023/12/12 12:59:10 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/AForm.hpp"
#include "./includes/Bureaucrat.hpp"
#include "./includes/ShrubberyCreationForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"

int main()
{
    std::cout << "\x1b[38;5;221m******************TEST SHRUBBERY******************" << std::endl;
		std::cout << "To creat a Shrubbery Form, it required grades: sign:145, exec:137\x1b[0m" << std::endl;
    std::cout << "\x1b[38;5;221m--------------THAT WORKS--------------\x1b[0m" << std::endl;
    try
	{
		Bureaucrat Alvin("Alvin", 130);
		ShrubberyCreationForm shrubbery("F1");
		std::cout << Alvin;
		std::cout << "F1's grade: sign:" << shrubbery.getGradeSign() << ", exec: " << shrubbery.getGradeExec() << std::endl;
		Alvin.signAForm(shrubbery);
		Alvin.executeAForm(shrubbery);
		shrubbery.to_execute(Alvin);
	}	
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}	
    std::cout << "\x1b[38;5;221m-----------THAT DOESN'T WORKS-----------\x1b[0m" << std::endl;
	try
	{
		Bureaucrat Theodor("Theodor", 150);
		ShrubberyCreationForm shrubbery("F2");
		std::cout << Theodor;
		std::cout << "F2's grade: sign:" << shrubbery.getGradeSign() << ", exec: " << shrubbery.getGradeExec() << std::endl;
		Theodor.signAForm(shrubbery);
		Theodor.executeAForm(shrubbery);
		shrubbery.to_execute(Theodor);
	}	
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
    std::cout << "\n\x1b[38;5;221m******************TEST ROBOTOMY******************" << std::endl;
	std::cout << "To creat a Robotomy Form, it required grades: sign:72, exec:45\x1b[0m" << std::endl;
    std::cout << "\x1b[38;5;221m--------------THAT WORKS--------------\x1b[0m" << std::endl;
	try
	{
		Bureaucrat Alvin("Alvin", 10);
		RobotomyRequestForm robot("R1");
		std::cout << Alvin;
		std::cout << "R1's grade: sign: " << robot.getGradeSign() << ", exec: " << robot.getGradeExec() << std::endl;
		Alvin.signAForm(robot);
		Alvin.executeAForm(robot);
		robot.to_execute(Alvin);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    std::cout << "\x1b[38;5;221m-----------THAT DOESN'T WORKS-----------\x1b[0m" << std::endl;
	try
	{
		Bureaucrat Theodor("Theodor", 100);
		RobotomyRequestForm robot("R2");
		std::cout << Theodor;
		std::cout << "R2's grade: sign: " << robot.getGradeSign() << ", exec: " << robot.getGradeExec() << std::endl;
		Theodor.signAForm(robot);
		Theodor.executeAForm(robot);
		robot.to_execute(Theodor);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n\x1b[38;5;221m*****************TEST PRESIDENTIAL*****************" << std::endl;
	std::cout << "To creat a Presidential Form, it required grades: sign:25, exec:5\x1b[0m" << std::endl;
    std::cout << "\x1b[38;5;221m--------------THAT WORKS--------------\x1b[0m" << std::endl;
    try
	{
		Bureaucrat Simon("Simon", 4);
		PresidentialPardonForm president("P1");
		std::cout << Simon;
		std::cout << "P1's grade: sign: " << president.getGradeSign() << ", exec: " << president.getGradeExec() << std::endl;
		Simon.signAForm(president);
		Simon.executeAForm(president);
		president.to_execute(Simon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    std::cout << "\x1b[38;5;221m-----------THAT DOESN'T WORKS-----------\x1b[0m" << std::endl;
	try
	{
		Bureaucrat Theodor("Theodor", 40);
		PresidentialPardonForm president("P2");
		std::cout << Theodor;
		std::cout << "P2's grade: sign: " << president.getGradeSign() << ", exec: " << president.getGradeExec() << std::endl;
		Theodor.signAForm(president);
		Theodor.executeAForm(president);
		president.to_execute(Theodor);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\x1b[38;5;221m***************************************************\x1b[0m" << std::endl;
	return (0);
}