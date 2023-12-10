/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:58:14 by tas               #+#    #+#             */
/*   Updated: 2023/11/22 12:15:59 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    std::cout << "\x1b[38;5;221m-----------------TEST 1-----------------" << std::endl;
    std::cout << "            Span 5 numbrers" << std::endl;
    std::cout << "----------------------------------------\x1b[0m" << std::endl;
    
    Span sp = Span(5);
    
    sp.addNumber(7);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << "\n\x1b[38;5;224mSpan values: \x1b[0m" << std::endl;
    sp.printTab();
    
    std::cout << "\n\x1b[38;5;126mShortest Span: \x1b[0m" << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << "\n\x1b[38;5;13mLongest Span: \x1b[0m" << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << std::endl;
    
    std::cout << "\x1b[38;5;221m-------------------TEST 2-------------------" << std::endl;
    std::cout << "Span with numbrers that goes from 0 to 9999" << std::endl;
    std::cout << "--------------------------------------------\x1b[0m" << std::endl;
    
    Span sp2 = Span(10000);
    
    for (unsigned int i = 0; i < 10000; i++)
    {
        sp2.addNumber(i);
    }
    std::cout << "\n\x1b[38;5;224mThere is too many numbers to display them all.\nSo let's just display the size of the Span.\x1b[0m" << std::endl;
    std::cout << sp2.getSize() << std::endl;
    std::cout << "\n\x1b[38;5;126mShortest Span: \x1b[0m" << std::endl;
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << "\n\x1b[38;5;13mLongest Span: \x1b[0m" << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
    std::cout << std::endl;

    std::cout << "\x1b[38;5;221m-------------------TEST 3-------------------" << std::endl;
    std::cout << "      Span with 10 000 random numbrers" << std::endl;
    std::cout << "--------------------------------------------\x1b[0m" << std::endl;

    Span sp3 = Span(10000);
    std::vector<unsigned int> v3;
    srand(static_cast<unsigned int>(time(0)));
    
    for (unsigned int i = 0; i < 10000; i++)
    {
        v3.push_back(randomInRange(0, 1000000));
    }
    sp3.RangeOfIterators(v3.begin(), v3.end());

    std::cout << "\n\x1b[38;5;224mThere is too many numbers to display them all.\nSo let's just display the size of the Span.\x1b[0m" << std::endl;
    std::cout << sp3.getSize() << std::endl;
    std::cout << "\n\x1b[38;5;126mShortest Span: \x1b[0m" << std::endl;
    std::cout << sp3.shortestSpan() << std::endl;
    std::cout << "\n\x1b[38;5;13mLongest Span: \x1b[0m" << std::endl;
    std::cout << sp3.longestSpan() << std::endl;
    std::cout << std::endl;
    
    std::cout << "\x1b[38;5;221m--------------------TEST 4-------------------" << std::endl;
    std::cout << "                   Span full" << std::endl;
    std::cout << "---------------------------------------------\x1b[0m" << std::endl;

    Span sp4(3);
    try
    {
        sp4.addNumber(765);
        sp4.addNumber(7);
        sp4.addNumber(87);
        sp4.addNumber(47);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "\n\x1b[38;5;221m--------------------TEST 5-------------------" << std::endl;
    std::cout << "            Span has only 1 number" << std::endl;
    std::cout << "---------------------------------------------\x1b[0m" << std::endl;

    Span sp5(3);
    try
    {
        sp5.addNumber(765);
        std::cout << sp5.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "\n\x1b[38;5;221m--------------------TEST 6-------------------" << std::endl;
    std::cout << "                Span is empty" << std::endl;
    std::cout << "---------------------------------------------\x1b[0m" << std::endl;

    Span sp6(3);
    try
    {
        sp6.addNumber(765);
        std::cout << sp6.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl;
    return (0);
}
