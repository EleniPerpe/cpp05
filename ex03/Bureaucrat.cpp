/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:12:41 by eperperi          #+#    #+#             */
/*   Updated: 2025/01/04 15:12:28 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(0)
{
	std::cout << "Bureaucrat default constructor with parameters called" << std::endl;
	if (grade < Bureaucrat::highestGrade)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > Bureaucrat::lowestGrade)
		throw(Bureaucrat::GradeTooLowException());
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this != &copy)
		this->_grade = copy._grade;
	return *this;
}

const std::string& Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade(int i)
{
	if (this->_grade - i < Bureaucrat::highestGrade)
		return throw(Bureaucrat::GradeTooHighException());
	else
	{
		this->_grade -= i;
		std::cout << this->_name << " was promoted to grade " << this->_grade << " !" << std::endl;
	}
}

void Bureaucrat::decrementGrade(int i)
{
	if (this->_grade + i > Bureaucrat::lowestGrade)
		return throw(Bureaucrat::GradeTooLowException());
	else
	{
		this->_grade += i;
		std::cout << this->_name << " was demoted to grade " << this->_grade << " !" << std::endl;
	}
}

void Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << *this << " couldn't sign " << form << " because : " << e.what() << std::endl << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		if (this->getGrade() <= form.getGradeExecute())
		{
			form.execute(*this);
			std::cout << *this << " executed " << form.getName() << std::endl;
		}
		else
			throw Bureaucrat::GradeTooLowException();
	}
	catch (const std::exception& e)
	{
		std::cout << *this << " couldn't execute " << form.getName() << " because : " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high !");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << " bureaucrat grade " << obj.getGrade();
	return (os);
}