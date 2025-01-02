/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:34:37 by eperperi          #+#    #+#             */
/*   Updated: 2025/01/02 17:23:42 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 
								ShrubberyCreationForm::signGrade, ShrubberyCreationForm::signExec),
								_target("Unknown")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 
								ShrubberyCreationForm::signGrade, ShrubberyCreationForm::signExec),
								_target(target)
{
	std::cout << "ShrubberyCreationForm constructor with target parameter called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy),
									_target(copy._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& copy)
{
	this->_target = copy._target;
	return *this;
}

const std::string& ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

const std::string ShrubberyCreationForm::_tree1 =
   		"      ^\n"
        "     ^^^\n"
        "    ^^^^^\n"
        "   ^^^^^^^\n"
        "  ^^^^^^^^^\n"
        " ^^^^^^^^^^^\n"
        "      ||\n"
        "      ||\n";


const std::string ShrubberyCreationForm::_tree2 =
        "      *\n"
        "     ***\n"
        "    *****\n"
        "   *******\n"
        "  *********\n"
        " ***********\n"
        "*************\n"
        "      ||\n"
        "      ||\n";


void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (executor.getGrade() > ShrubberyCreationForm::signExec)
        throw (AForm::GradeTooLowException());

	std::ofstream ofs;

	ofs.open((this->_target + "_shrubbery").c_str(), std::ofstream::out | std::ofstream::app);

	if (ofs.is_open())
	{
		if (std::rand() % 2)
			ofs << ShrubberyCreationForm::_tree1;
		else
			ofs << ShrubberyCreationForm::_tree2;
	}
}