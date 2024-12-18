/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:12:41 by eperperi          #+#    #+#             */
/*   Updated: 2024/12/18 15:50:54 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, size_t grade) : _name(name), _grade(0)
{
	std::cout << "Bureaucrat default constructor with parameters called" << std::endl;
	if (grade < Bureaucrat::highestGrade)
		throw(Bureaucrat::HighGradeException());
	else if (grade > Bureaucrat::lowestGrade)
		throw(Bureaucrat::LowGradeException());
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

size_t Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade(int i)
{
	if (this->_grade - i < Bureaucrat::highestGrade)
		return throw(Bureaucrat::HighGradeException());
	else
	{
		this->_grade -= i;
		std::cout << this->_name << " was promoted to grade " << this->_grade << " !" << std::endl;
	}
}

void Bureaucrat::decrementGrade(int i)
{
	if (this->_grade + i > Bureaucrat::lowestGrade)
		return throw(Bureaucrat::LowGradeException());
	else
	{
		this->_grade += i;
		std::cout << this->_name << " was demoted to grade " << this->_grade << " !" << std::endl;
	}
}

const char* Bureaucrat::HighGradeException::what() const throw()
{
	return ("Grade is too high !");
}

const char* Bureaucrat::LowGradeException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << "Bureaucrat \"" << obj.getName() << "\" (grade: " << obj.getGrade() << ")" << std::endl;
	return (os);
}