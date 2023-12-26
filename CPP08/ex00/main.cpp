/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:33:21 by tas               #+#    #+#             */
/*   Updated: 2023/12/25 23:09:43 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::cout << "\x1b[38;5;13m**********TEST REUSSIE**********\x1b[0m" << std::endl;
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try
    {
        easyfind(vec, 1);
        easyfind(vec, 2);
        easyfind(vec, 3);
        easyfind(vec, 4);
        easyfind(vec, 5);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n\x1b[38;5;13m***********TEST ECHEC***********\x1b[0m" << std::endl;
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    
    try
    {
        easyfind(lst, 6);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}