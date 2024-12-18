/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:42:24 by eperperi          #+#    #+#             */
/*   Updated: 2024/12/18 19:02:57 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeSignIn;	
		const int _gradeExecute;
		
	public:
		Form();
		Form(const std::string name, const int gradeSignIn, const int gradeExecute);
		Form(const Form& copy);
		~Form();

		Form& operator=(const Form& copy);
		
		const std::string& getName() const;
		bool getSigned() const;
		const int getGradeSignIn() const;
		const int getGradeExecute() const;

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
			
		class 
};

std::ostream& operator<<(std::ostream os, const Form& obj);

