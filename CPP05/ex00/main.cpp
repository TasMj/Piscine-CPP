/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:41:52 by tas               #+#    #+#             */
/*   Updated: 2023/11/13 13:29:17 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\x1b[38;5;221m********************INITIALISATION*********************\x1b[0m" << std::endl;
    Bureaucrat  a;
    Bureaucrat  b("Alvin", 50);
    Bureaucrat  c(b);
    
    std::cout << "\x1b[38;5;221m********************GRADE THAT WORK********************\x1b[0m" << std::endl;
    /*Default cosntructor*/
    try
    {
        a.setGrade(20);
        a.decreaseGrade();
        a.decreaseGrade();
        a.AddGrade();
        std::cout << a.getName() << ": grade: " << a.getGrade() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    /*constructor with parameters*/
    try
    {
        b.AddGrade();
        b.decreaseGrade();
        b.decreaseGrade();
        b.decreaseGrade();
        std::cout << b.getName() << ": grade: " << b.getGrade() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    /*copy constructor*/
    try
    {
        c.decreaseGrade();
        std::cout << c.getName() << ": grade: " << c.getGrade() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\x1b[38;5;221m********************GRADE TOO HIGH*********************\x1b[0m" << std::endl;
    try
    {
        a.setGrade(-2345);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        b.setGrade(1);
        b.AddGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\x1b[38;5;221m********************GRADE TOO LOW**********************\x1b[0m" << std::endl;
    try
    {
        int i = 100;
        while(i > 0)
        {
            c.decreaseGrade();
            i--;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        a.setGrade(150);
        a.decreaseGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\x1b[38;5;221m*********************DESTRUCTION***********************\x1b[0m" << std::endl;
}