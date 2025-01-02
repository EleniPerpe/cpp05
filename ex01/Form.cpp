/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:03:11 by eperperi          #+#    #+#             */
/*   Updated: 2025/01/02 14:37:03 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


		
Form::Form() : _name("Unkown"), _signed(false), _gradeSignIn(150), _gradeExecute(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, const int gradeSignIn, const int gradeExecute) 
						:	_name(name), _signed(false), _gradeSignIn(gradeSignIn),
							_gradeExecute(gradeExecute)									
{
	std::cout << "Form default constructor with parameters called" << std::endl;
	if (gradeSignIn < Bureaucrat::highestGrade || gradeExecute > Bureaucrat::lowestGrade)
		throw(Form::GradeTooHighException());
	if (gradeSignIn > Bureaucrat::lowestGrade || gradeExecute < Bureaucrat::highestGrade)
		throw(Form::GradeTooLowException());
}

Form::Form(const Form& copy) : _name(copy._name), _signed(copy._signed),
								_gradeSignIn(copy._gradeSignIn), _gradeExecute(copy._gradeExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form& Form::operator=(const Form& copy)
{
	std::cout << "Form asignment operator called" << std::endl;
	if (this != &copy)
		this->_signed = copy._signed;
	return *this;	
}

const std::string& Form::getName() const
{
	return this->_name;	
}

bool Form::getSigned() const
{
	return this->_signed;
}

int Form::getGradeSignIn() const
{
	return this->_gradeSignIn;
}

int Form::getGradeExecute() const
{
	return this->_gradeExecute;
}

void Form::beSigned(const Bureaucrat& obj)
{
	if (obj.getGrade() > this->_gradeSignIn)
		throw (Form::GradeTooLowException());
	this->_signed = true;		
}

const char * Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high for form.");		
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low for form.");		
};

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
os << "\"" << obj.getName() << "\"" << std::endl
<< "(Required grade to sign: " << obj.getGradeSignIn()
<< ", to execute: " << obj.getGradeExecute() << ")";
return (os);
}