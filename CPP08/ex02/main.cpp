/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:24:17 by tas               #+#    #+#             */
/*   Updated: 2023/11/22 16:55:19 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <cstdio>

int main()
{
    
    std::cout << "\x1b[38;5;221m-----------------TEST 1-----------------" << std::endl;
    std::cout << "                  stack" << std::endl;
    std::cout << "----------------------------------------\x1b[0m" << std::endl;

    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    mstack.push(32);
    mstack.push(49);
    
    MutantStack<int>::iterator iit = mstack.begin();
    MutantStack<int>::iterator iite = mstack.end();
    
    std::cout << "\n\x1b[38;5;224mStack values: \x1b[0m" << std::endl;
    while (iit != iite)
    {
        std::cout << *iit << std::endl;
        ++iit;
    }
    
    std::cout << "\n\x1b[38;5;81mtop: " << mstack.top() << std::endl;
    std::cout << "\nsize avant pop(): " << mstack.size() << std::endl;
    mstack.pop();
    std::cout << "***pop***\nsize après pop(): " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(10);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    std::cout << "\x1b[0m\n\x1b[38;5;224mStack values: \x1b[0m" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::cout << "\n\x1b[38;5;81mtop: " << mstack.top() << std::endl;
    std::cout << "\nsize avant pop(): " << mstack.size() << std::endl;
    mstack.pop();
    std::cout << "***pop***\nsize après pop(): " << mstack.size() << std::endl;

    
    std::cout << "\x1b[38;5;221m-----------------TEST 2-----------------" << std::endl;
    std::cout << "              stack copy" << std::endl;
    std::cout << "----------------------------------------\x1b[0m" << std::endl;

    MutantStack<int> s(mstack);
    
    s.push(5);
    s.push(17);
    s.push(32);
    s.push(49);
    
    MutantStack<int>::iterator itS =  s.begin();
    MutantStack<int>::iterator iteS = s.end();
    
    std::cout << "\n\x1b[38;5;224s values: \x1b[0m" << std::endl;
    while (itS != iteS)
    {
        std::cout << *itS << std::endl;
        ++itS;
    }
    
    std::cout << "\n\x1b[38;5;81mtop: " << s.top() << std::endl;
    std::cout << "\nsize avant pop(): " << s.size() << std::endl;
    s.pop();
    std::cout << "***pop***\nsize après pop(): " << s.size() << std::endl;
    
    s.push(3);
    s.push(5);
    s.push(737);
    s.push(10);
    
    MutantStack<int>::iterator iitS = s.begin();
    MutantStack<int>::iterator iiteS = s.end();
    
    std::cout << "\x1b[0m\n\x1b[38;5;224s values: \x1b[0m" << std::endl;
    while (iitS != iiteS)
    {
        std::cout << *iitS << std::endl;
        ++iitS;
    }
    
    std::cout << "\n\x1b[38;5;81mtop: " << s.top() << std::endl;
    std::cout << "\nsize avant pop(): " << s.size() << std::endl;
    s.pop();
    std::cout << "***pop***\nsize après pop(): " << s.size() << std::endl;


    /*
    std::cout << "\x1b[38;5;221m-----------------TEST 2-----------------" << std::endl;
    std::cout << "                  list" << std::endl;
    std::cout << "----------------------------------------\x1b[0m" << std::endl;

    MutantStack<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    mlist.push_back(32);
    mlist.push_back(49);
    
    MutantStack<int>::iterator iit = mlist.begin();
    MutantStack<int>::iterator iite = mlist.end();
    
    std::cout << "\n\x1b[38;5;224mlist values: \x1b[0m" << std::endl;
    while (iit != iite)
    {
        std::cout << *iit << std::endl;
        ++iit;
    }
    
    std::cout << "\n\x1b[38;5;81mtop: " << mlist.back() << std::endl;
    std::cout << "\nsize avant pop(): " << mlist.size() << std::endl;
    mlist.pop_back();
    std::cout << "***pop***\nsize après pop(): " << mlist.size() << std::endl;
    
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(10);
    
    MutantStack<int>::iterator it = mlist.begin();
    MutantStack<int>::iterator ite = mlist.end();
    
    std::cout << "\x1b[0m\n\x1b[38;5;224mlist values: \x1b[0m" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::cout << "\n\x1b[38;5;81mtop: " << mlist.back() << std::endl;
    std::cout << "\nsize avant pop(): " << mlist.size() << std::endl;
    mlist.pop_back();
    std::cout << "***pop***\nsize après pop(): " << mlist.size() << std::endl;
    
    std::cout << "\x1b[38;5;221m-----------------TEST 2-----------------" << std::endl;
    std::cout << "             copy list" << std::endl;
    std::cout << "----------------------------------------\x1b[0m" << std::endl;

    MutantStack<int> s(mlist);
    
    s.push_back(5);
    s.push_back(17);
    s.push_back(32);
    s.push_back(49);
    
    MutantStack<int>::iterator iits = s.begin();
    MutantStack<int>::iterator iites = s.end();
    
    std::cout << "\n\x1b[38;5;224ms values: \x1b[0m" << std::endl;
    while (iits != iites)
    {
        std::cout << *iits << std::endl;
        ++iits;
    }
    
    std::cout << "\n\x1b[38;5;81mtop: " << s.back() << std::endl;
    std::cout << "\nsize avant pop(): " << s.size() << std::endl;
    s.pop_back();
    std::cout << "***pop***\nsize après pop(): " << s.size() << std::endl;
    
    s.push_back(3);
    s.push_back(5);
    s.push_back(737);
    s.push_back(10);
    
    MutantStack<int>::iterator its = s.begin();
    MutantStack<int>::iterator ites = s.end();
    
    std::cout << "\x1b[0m\n\x1b[38;5;224ms values: \x1b[0m" << std::endl;
    while (its != ites)
    {
        std::cout << *its << std::endl;
        ++its;
    }
    
    std::cout << "\n\x1b[38;5;81mtop: " << s.back() << std::endl;
    std::cout << "\nsize avant pop(): " << s.size() << std::endl;
    s.pop_back();
    std::cout << "***pop***\nsize après pop(): " << s.size() << std::endl;
    */

    return (0);
}