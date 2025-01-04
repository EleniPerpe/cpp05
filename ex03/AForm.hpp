/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:42:24 by eperperi          #+#    #+#             */
/*   Updated: 2025/01/04 15:12:18 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeSignIn;	
		const int _gradeExecute;
		
	public:
		AForm();
		AForm(const std::string name, const int gradeSignIn, const int gradeExecute);
		AForm(const AForm& copy);
		virtual ~AForm();

		AForm& operator=(const AForm& copy);
		
		const std::string& getName() const;
		bool getSigned() const;
		int getGradeSignIn() const;
		int getGradeExecute() const;

		void beSigned(const Bureaucrat& obj);

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

		class NoSignException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		void execute(const Bureaucrat& executor) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

