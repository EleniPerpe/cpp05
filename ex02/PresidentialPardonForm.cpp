/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:34:37 by eperperi          #+#    #+#             */
/*   Updated: 2025/01/03 15:43:29 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <fstream>
#include <random>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 
								PresidentialPardonForm::signGrade, PresidentialPardonForm::signExec),
								_target("Unknown")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 
								PresidentialPardonForm::signGrade, PresidentialPardonForm::signExec),
								_target(target)
{
	std::cout << "PresidentialPardonForm constructor with target parameter called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy),
									_target(copy._target)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& copy)
{
	this->_target = copy._target;
	return *this;
}

const std::string& PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	// I can remove the try-catch from here and just open the extra case in main
	try
	{
		if (executor.getGrade() > PresidentialPardonForm::signExec)
		{
			// std::cout << executor.getName() << " couldn't be pardoned by Zaphod Beeblebrox!" << std::endl;
			throw (AForm::GradeTooLowException());	
		}
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
		return;
	}	
	
	// std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
	

}