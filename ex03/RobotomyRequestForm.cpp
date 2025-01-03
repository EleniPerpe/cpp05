/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:34:37 by eperperi          #+#    #+#             */
/*   Updated: 2025/01/03 15:10:06 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <random>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 
								RobotomyRequestForm::signGrade, RobotomyRequestForm::signExec),
								_target("Unknown")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 
								RobotomyRequestForm::signGrade, RobotomyRequestForm::signExec),
								_target(target)
{
	std::cout << "RobotomyRequestForm constructor with target parameter called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy),
									_target(copy._target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& copy)
{
	this->_target = copy._target;
	return *this;
}

const std::string& RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	// I can remove the try-catch from here and just open the extra case in main
	try
	{
		if (executor.getGrade() > RobotomyRequestForm::signExec)
			throw (AForm::GradeTooLowException());	
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
		return;
	}	
	
	std::cout << "Bzzzzzz... Bbbzzzzzzz... Bbbbbzzzzzzz..." << std::endl;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 1);
	

	if (dis(gen))
		std::cout << this->_target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << this->_target << " couldn't be robotomized!" << std::endl;

}