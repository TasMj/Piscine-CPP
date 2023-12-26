/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:54:50 by tas               #+#    #+#             */
/*   Updated: 2023/12/26 14:55:43 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <stdlib.h>

/* constructors & destructor */
RPN::RPN()
{
    std::cout << "\x1b[38;5;43mRPN default constructor called\x1b[0m" << std::endl;
}

RPN::RPN(const RPN &copy)
{
    std::cout << "\x1b[38;5;114mRPN Copy constructor called\x1b[0m" << std::endl;
	if (this != &copy)
		*this = copy;
}

RPN::~RPN()
{
    std::cout << "\x1b[38;5;124mRPN destructor called\x1b[0m" << std::endl;
}

/* operator */
RPN &RPN::operator=(const RPN &cpy)
{
	(void)cpy;
    std::cout << "\x1b[38;5;138mRPN Copy assignement operation called\x1b[0m" << std::endl;
	return (*this);
}

/*tools*/
bool	isNumeric(char c)
{
	if (!(c >= '0' && c <= '9'))
		return (false);
	return (true);
}

bool	isOperand(char c)
{
	if (c == '+' || c == '-' || c == '*' || c== '/')
		return (true);
	return (false);
}

int	onlyNumAndOperand(std::string str)
{
	int i = 0;
	
	while (str[i])
	{
		if ((!isNumeric(str[i]) && !isOperand(str[i]) && str[i] != ' '))
		{
			std::cout << "\x1b[38;5;205mError: can only contain numerics and operand seperated by a space\x1b[0m" << std::endl;
			return (0);
		}
		i++;
	}
	return (1);
}

int parseArgv(std::string str)
{
	int i = 1;
	
	if (str.size() == 0)
	{
		std::cout << "\x1b[38;5;205mError: empty input\x1b[0m" << std::endl;
		return (1);
	}
	if (!onlyNumAndOperand(str))
		return (1);
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if (isOperand(str[i]) && (!str[i + 1] || str[i + 1] == ' ' || isNumeric(str[i + 1])))
			i++;
		else if (isNumeric(str[i]) && (str[i + 1] && (str[i + 1] == ' ' || isNumeric(str[i + 1]))))
			i++;
		else
		{
			std::cout << "Error: Invalid expression format" << std::endl;
			return (1);	
		}
	}
	return (0);
}

int countNbr(std::string operation)
{
	int i = 0;
	int counter = 0;
	
	while (operation[i])
	{
		if (isNumeric(operation[i]))
			counter++;
		i++;
	}
	return (counter);
}

int countOperand(std::string operation)
{
	int i = 0;
	int counter = 0;
	
	while (operation[i])
	{
		if (isOperand(operation[i]))
			counter++;
		i++;
	}
	return (counter);
}

int	operationStack(int a, int b, char o)
{
	if (o == '+')
		return (a + b);
	if (o == '-')
		return (a - b);
	if (o == '*')
		return (a * b);
	if (o == '/')
		return (a / b);
	return (0);
}

/* function memnber */
void	RPN::fillStack(std::string str)
{
	int i = 0;
	
	while (str[i])
	{
		if (isNumeric(str[i]) || isOperand(str[i]))
			stackNbr.push(str[i]);
		i++;
	}
}

void	RPN::fillSaveStack()
{
	while (stackNbr.size()!= 0)
	{
		saveStack.push(stackNbr.top());
		stackNbr.pop();
	}
		
}

void RPN::doCalcul(std::string str)
{
    std::istringstream ss(str);
    std::string token;
    std::stack<int> numbers;

    while (ss >> token) 
	{
		std::cout << token << std::endl;
        if (isNumeric(token[0]) || (token.size() > 1 && isOperand(token[0]) && isNumeric(token[1])))
		{
            int number = atoi(token.c_str());
            numbers.push(number);
        }
		else if (isOperand(token[0])) 
		{
            if (numbers.size() < 2) 
			{
                std::cout << "\x1b[38;5;205mError: Not enough numbers for the operation\x1b[0m" << std::endl;
                return;
            }

            int b = numbers.top(); numbers.pop();
            int a = numbers.top(); numbers.pop();

            switch (token[0]) {
                case '+': numbers.push(a + b); break;
                case '-': numbers.push(a - b); break;
                case '*': numbers.push(a * b); break;
                case '/':
                    if (b == 0) {
                        std::cout << "\x1b[38;5;205mError: Division by zero\x1b[0m" << std::endl;
                        return;
                    }
                    numbers.push(a / b);
                    break;
                default:
                    std::cout << "\x1b[38;5;205mError: Invalid operator\x1b[0m" << std::endl;
                    return;
            }
        }
    }

    if (numbers.size() == 1) {
        std::cout << "Result: \x1b[38;5;129m" << numbers.top() << "\x1b[0m" << std::endl;
    } else {
        std::cout << "\x1b[38;5;205mError: Invalid expression format\x1b[0m" << std::endl;
    }
}
