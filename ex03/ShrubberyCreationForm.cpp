/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:34:37 by eperperi          #+#    #+#             */
/*   Updated: 2025/01/03 15:43:29 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <random>

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
	// I can remove the try-catch from here and just open the extra case in main
	try
	{
		if (executor.getGrade() > ShrubberyCreationForm::signExec)
			throw (AForm::GradeTooLowException());	
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
		return;
	}	
	
	std::cout << "_shrubbery file with ASCII tree created" << std::endl;
	
	std::ofstream ofs;

	ofs.open((this->_target + "_shrubbery").c_str(), std::ofstream::out | std::ofstream::app);
	
	if (!ofs.is_open())
        throw std::runtime_error("Failed to open the file: " + this->_target + "_shrubbery");

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 1);
	
	if (ofs.is_open())
	{
		if (dis(gen))
			ofs << ShrubberyCreationForm::_tree1;
		else
			ofs << ShrubberyCreationForm::_tree2;
	}
	ofs.close();
}