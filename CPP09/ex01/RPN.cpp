/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:54:50 by tas               #+#    #+#             */
/*   Updated: 2023/11/24 17:35:18 by tas              ###   ########.fr       */
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
	if (!isNumeric(str[0]))
	{
		std::cout << "\x1b[38;5;205mError: the first character has to be a number\x1b[0m" << std::endl;
		return (1);
	}
	while (str[i])
	{
		if (i % 2 == 0 && (!isNumeric(str[i]) && !isOperand(str[i])))
		{
			std::cout << "\x1b[38;5;205mError: must contain only numeric and operand characters\x1b[0m" << std::endl;
			return (1);
		}
		else if (i % 2 == 1 && str[i] != ' ')
		{
			std::cout << "\x1b[38;5;205mError: numbers and operands must be seperated by a space\x1b[0m" << std::endl;
			return (1);
		}
		i++;
	}
	if ((isNumeric(str[i - 1]) || str[i - 1] == ' ') && countNbr(str) != 1)
	{
		std::cout << "\x1b[38;5;205mError: input must end by an operand\x1b[0m" << std::endl;
		return (1);
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

void	RPN::doCalcul(std::string str)
{
	
	if (countNbr(str) == 1)
		std::cout << str << std::endl;
	else if (countNbr(str) == 2 && countOperand(str) == 0)
		std::cout << "\x1b[38;5;205mError: there is no operand\x1b[0m" << std::endl;
	else
	{
		fillStack(str);
		fillSaveStack();
		/* first calcul */
		int		nb1 = saveStack.top() - '0';
		saveStack.pop();
		int		nb2 = saveStack.top() - '0';
		saveStack.pop();
		char	operand = saveStack.top();
		saveStack.pop();
		saveStack.push(operationStack(nb1, nb2, operand));

		/* the rest */
		while (saveStack.size() != 1)
		{
			int		previousValue = saveStack.top();
			saveStack.pop();
			int		newValue = saveStack.top() - '0';
			saveStack.pop();
			char	newOperand = saveStack.top();
			saveStack.pop();
			saveStack.push(operationStack(previousValue, newValue, newOperand));
		}
		std::cout << saveStack.top() << std::endl;
	}
}
