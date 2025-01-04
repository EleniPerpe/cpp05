/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:03:11 by eperperi          #+#    #+#             */
/*   Updated: 2025/01/04 15:13:48 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


		
AForm::AForm() : _name("Unkown"), _signed(false), _gradeSignIn(150), _gradeExecute(1)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int gradeSignIn, const int gradeExecute) 
						:	_name(name), _signed(false), _gradeSignIn(gradeSignIn),
							_gradeExecute(gradeExecute)									
{
	std::cout << "AForm default constructor with parameters called" << std::endl;
	if (gradeSignIn < Bureaucrat::highestGrade || gradeExecute > Bureaucrat::lowestGrade)
		throw(AForm::GradeTooHighException());
	if (gradeSignIn > Bureaucrat::lowestGrade || gradeExecute < Bureaucrat::highestGrade)
		throw(AForm::GradeTooLowException());
}

AForm::AForm(const AForm& copy) : _name(copy._name), _signed(copy._signed),
								_gradeSignIn(copy._gradeSignIn), _gradeExecute(copy._gradeExecute)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& copy)
{
	std::cout << "AForm asignment operator called" << std::endl;
	if (this != &copy)
		this->_signed = copy._signed;
	return *this;	
}

const std::string& AForm::getName() const
{
	return this->_name;	
}

bool AForm::getSigned() const
{
	return this->_signed;
}

int AForm::getGradeSignIn() const
{
	return this->_gradeSignIn;
}

int AForm::getGradeExecute() const
{
	return this->_gradeExecute;
}

void AForm::execute(const Bureaucrat& executor) const
{

	// I can remove the try-catch from here and just open the extra case in main
	try
	{
		if (executor.getGrade() > AForm::_gradeExecute)
		{
			std::cout << executor.getName() << " doesn't exist!" << std::endl;
			throw (AForm::GradeTooLowException());	
		}
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
		return;
	}	

}


void AForm::beSigned(const Bureaucrat& obj)
{
	if (this->_signed == false)
	{
		throw AForm::NoSignException();
		return ;
	}
	if (obj.getGrade() > this->_gradeSignIn)
	{
		throw (AForm::GradeTooLowException());
		return ;
	}
	this->_signed = true;		
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high for Aform.");		
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low for Aform.");		
};

const char* AForm::NoSignException::what() const throw()
{
	return ("Form has not been signed");
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
os << "\"" << obj.getName() << "\"" << std::endl
<< "(Required grade to sign: " << obj.getGradeSignIn()
<< ", to execute: " << obj.getGradeExecute() << ")";
return (os);
}