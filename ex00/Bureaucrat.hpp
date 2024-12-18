/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:56:47 by eperperi          #+#    #+#             */
/*   Updated: 2024/12/18 15:19:42 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat
{
	private:
		const std::string _name;
		size_t _grade;
		
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, size_t grade);
		Bureaucrat(const Bureaucrat& copy);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& copy);

		const std::string& getName() const;
		size_t getGrade() const;

		void incrementGrade(int i);
		void decrementGrade(int i);

		const size_t lowestGrade = 150;
		const size_t highestGrade = 1;

		class HighGradeException : public std::exception
		{
			public:
				virtual const char* what() const throw(); 
		};

		class LowGradeException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);