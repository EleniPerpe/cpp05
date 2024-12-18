/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:03:11 by eperperi          #+#    #+#             */
/*   Updated: 2024/12/18 18:23:15 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


		const std::string _name;
		bool _signed;
		const int _gradeSignIn;	
		const int _gradeExecute;

		
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
										_gradeSignIn(copy._gradeExecute), _gradeExecute(copy._gradeExecute)
		{
			std::cout << "Form copy constructor called" << std::endl;
		}

		Form::~Form()
		{
			std::cout << "Form destructor called" << std::endl;
		}

		Form& operator=(const Form& copy);
		
		const std::string& getName() const;
		bool getSigned() const;
		const int getGradeSignIn() const;
		const int getGradeExecute() const;

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

std::ostream& operator<<(std::ostream os, const Form& odj);