/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:54:50 by tas               #+#    #+#             */
/*   Updated: 2023/12/26 15:54:45 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

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
			std::cout << "\x1b[38;5;205mError: can only contain numerics and operand seperated by space\x1b[0m" << std::endl;
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
			std::cout << "\x1b[38;5;205mError: Invalid expression format\x1b[0m" << std::endl;
			return (1);	
		}
	}
	return (0);
}

/* function member */
void RPN::doCalcul(std::string str)
{
    std::istringstream ss(str);
    std::string token;

    while (ss >> token) 
	{
        if (isNumeric(token[0]) || (token.size() > 1 && isOperand(token[0]) && isNumeric(token[1])))
		{
            long int number = atoi(token.c_str());
			if ((token.size() > 11) || (number > 0 && token[0] == '-') || (number < -2147483648 && token.size() >= 11))
			{
	            std::cout << "\x1b[38;5;205mError: Overflow\x1b[0m" << std::endl;
					return;
			}
			if (number >= 10)
			{
                std::cout << "\x1b[38;5;205mError: The numbers used in this operation and passed as arguments has to be less than 10.\x1b[0m" << std::endl;
				return;
			}
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

            switch (token[0])
			{
                case '+': numbers.push(a + b);
					break;
                case '-': numbers.push(a - b);
					break;
                case '*': numbers.push(a * b);
					break;
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
