/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:56:47 by eperperi          #+#    #+#             */
/*   Updated: 2025/01/04 15:05:14 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
		
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& copy);

		const std::string& getName() const;
		int getGrade() const;

		void incrementGrade(int i);
		void decrementGrade(int i);

		void signForm(AForm& form) const;
		void executeForm(AForm const & form) const;
		
		static const int lowestGrade = 150;
		static const int highestGrade = 1;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw(); 
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);