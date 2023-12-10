/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:00:08 by tas               #+#    #+#             */
/*   Updated: 2023/11/17 18:58:30 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename F>
F power(F a)
{
    return (a * a);
}

template<typename T>
void    printTab(T *array, int len)
{
    int i = 0;
    
    while(i < len)
    {
        std::cout << "                " << array[i] << std::endl;
        i++;
    }
}

std::string	addMonth(std::string s)
{
	s.append(" Novembre 2023");
	return s;
}

int main()
{
    printf("\x1b[38;5;140m**********Test Int Array**********\x1b[0m\n");
    
    int tab[10];
    int i = 0;
    
    while (i < 10)
    {
        tab[i] = i;
        i++;
    }
    printf("\x1b[38;5;36m----avant fonction puissance²----\x1b[0m\n");
    printTab(tab, 10);
    iter(tab, 10, power<int>);
    printf("\x1b[38;5;205m----après fonction puissance²----\x1b[0m\n");
    printTab(tab, 10);
    
    
    printf("\n\x1b[38;5;140m**********Test strig Array**********\x1b[0m\n");
    
    std::string tabString[3];

    tabString[0] = "lundi";
    tabString[1] = "mardi";
    tabString[2] = "mercredi";

    printf("\x1b[38;5;36m----avant fonction add month----\x1b[0m\n");
    printTab(tabString, 3);
    iter(tabString, 3, addMonth);
    printf("\x1b[38;5;205m----après fonction add month----\x1b[0m\n"); 
    printTab(tabString, 3);

    return (0);
}