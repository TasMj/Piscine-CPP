/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:09:41 by tas               #+#    #+#             */
/*   Updated: 2023/11/13 17:18:48 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ShrubberyCreationForm.hpp"
#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"

/* constructors */
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shubbery", 145, 137), _targetFile("Default")
{
    std::cout << "\x1b[38;5;43mShubbery default constructor called\x1b[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &targetFile) : AForm("Shubbery", 145, 137), _targetFile(targetFile)
{
    std::cout << "\x1b[38;5;2mShubbery constructor called\x1b[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : 
AForm(copy.getNameAForm(), copy.getGradeSign(), copy.getGradeExec()), _targetFile(copy._targetFile)
{
    std::cout << "\x1b[38;5;114mShubbery copy constructor called\x1b[0m" << std::endl;
	*this = copy;
}

/* operator */
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
    std::cout << "\x1b[38;5;138mShrubberyCreationForm Copy assignement operation called\x1b[0m" << std::endl;
    (void)assign;
    return (*this);
}

/* destructor */
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "\x1b[38;5;124mShrubberyCreationForm destructor called\x1b[0m" << std::endl;	
}

/* member function */
void    ShrubberyCreationForm::to_execute(Bureaucrat const &executor) const
{
    this->execute(executor);
    std::string fileName = this->_targetFile;
    fileName.append("_shrubbery");
    std::ofstream outfile(fileName.data());
    try
    {
        if (outfile.is_open() == false)
            throw AForm::FileNotOpen();
    }
    catch(const std::exception &e)
    {
        throw AForm::FileNotOpen();
    }
    outfile << "                              ./(    .      ,.                              " << std::endl;
    outfile << "                  ,/.   ,/     /*(.  *,   #(*                               " << std::endl;
    outfile << "                    #((#***(   .(/(*##/ .%(/                                " << std::endl;
    outfile << "               *,(/   *#/#(/(* .*/((%#/,##(.       (  *(                    " << std::endl;
    outfile << "                    /#(./((((/(.*/(##%*#%(. ,.  #.,%,                       " << std::endl;
    outfile << "                     ,**#(/(%((/,*/%&%##(.,. *//#/.,/.                      " << std::endl;
    outfile << "        .**((#%%#((#,.*   ,#(%#%(*/#%%(/ **/*//%(*. ..*/*.                  " << std::endl;
    outfile << "                  (#/#%#%#((//(%#///##(/(%#(&(./#.         . ..             " << std::endl;
    outfile << "            .((*//*,*/(#%%###*(/#%%#(((%#(((( ..,##(####(***///,/*          " << std::endl;
    outfile << "     ./*/((*..     ,/(((((/*/####(#####(#(/(##((..,*,,/*.                   " << std::endl;
    outfile << "          *((//(((/((*#/(%*,(###%#((%%(##((((*/&%%%%%%*,*/(*.               " << std::endl;
    outfile << "        ,(,%#/*(*(#**(((((#&&%%(((%%%#%##(&(*/(#((/**/#*.   .((///*.        " << std::endl;
    outfile << "      //#%(((. /###(/(((%&%%&#(//((&%%/((//%%&%/(((%%%%#/,*/(.              " << std::endl;
    outfile << "      *.#,  /#(/(%#(//%&#%((%//(/*#&&&%**/(&(*###*/(%##&%#/(/(              " << std::endl;
    outfile << "          /(#(##&@(#/(#,/*(#&*//(&@&##/(/(%&%#*/(*#%%%&/*(#%,(**(           " << std::endl;
    outfile << "        //*(#%%%((##%%*/##%&&*(/&&&&%#*#/#%#%##*,/,&#(#(%%. ((#.*           " << std::endl;
    outfile << "       ./(##%#(((#(#&#((#((&%//%%&%%(#//*/%%(#((/,,/&&/((/%(#./*(/          " << std::endl;
    outfile << "      ,/(%(*%*(####&%#*#%*%%%/###%%%/#(,/(##%((%%/%##&&//(*## /#..,         " << std::endl;
    outfile << "      /#.*(/%//#%(#%#(/&%(##%(#%####/(//((((##((&&/(/%#/%//*/(, *#          " << std::endl;
    outfile << "         //,/#%/((%//(%&(%/((/&%/##((*/*/((,/((/#&%((*(%#/(/( /.            " << std::endl;
    outfile << "            ( (//#///#%,##,/(#/ *((((/(#*// ****%%%%(( (((.%/#              " << std::endl;
    outfile << "           , (/*//#*(/ .#/ *#,   /(/(&&# /   /( .#%#&   */* *..             " << std::endl;
    outfile << "             ,., ./    *#        ,(*%%%*         *#.%(   .   (              " << std::endl;
    outfile << "              .                  .*/%#%.            *(                      " << std::endl;
    outfile << "                                 ./#(%%,                                    " << std::endl;
    outfile << "                                 .(((##*                                    " << std::endl;
    outfile << "                                 .//((#*                                    " << std::endl;
    outfile << "                                 .((((%*                                    " << std::endl;
    outfile << "                                 ,(*(##/                                    " << std::endl;
    outfile << "                                 ,(//((#                                    " << std::endl;
    outfile << "                                 /((/(##                                    " << std::endl;
    outfile << "                               (####%%&%&#.                                 " << std::endl;
    outfile << "                       ,/*//////((/((((((((////((,                          " << std::endl;
    outfile << "                                                                            " << std::endl;
    outfile.close();
}