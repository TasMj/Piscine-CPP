/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:32:42 by tas               #+#    #+#             */
/*   Updated: 2023/11/13 14:33:23 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "\x1b[38;5;221m********************INITIALISATION*********************\x1b[0m" << std::endl;
    Bureaucrat a("Theodore", 123);
    Bureaucrat d("Simon", 2);
    Form  b("F2", 70, 50);
    Form  c("F3", 70, 129);

    std::cout << "\x1b[38;5;221m********************GRADE THAT WORK********************\x1b[0m" << std::endl;
    try
    {
        std::cout << a.getName() << ": grade: " << a.getGrade() << std::endl;
        std::cout << "garde signed: " << b.getGradeSign() << " grade Exec: " << b.getGradeExec() << std::endl;
        a.signForm(b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\x1b[38;5;221m********************GRADE TOO LOW**********************\x1b[0m" << std::endl;
    try
    {
        std::cout << d.getName() << ": grade: " << d.getGrade() << std::endl;
        std::cout << "garde signed: " << c.getGradeSign() << " grade Exec: " << c.getGradeExec() << std::endl;
        d.signForm(c);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\x1b[38;5;221m*********************DESTRUCTION***********************\x1b[0m" << std::endl;
}