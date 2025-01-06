/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:16:25 by eperperi          #+#    #+#             */
/*   Updated: 2025/01/06 14:47:04 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat eleni;
		Bureaucrat Maria("Maria", 140);
		std::cout << Maria << std::endl;
		Maria.incrementGrade(10);
		std::cout << Maria << std::endl;
		Bureaucrat John("John", 70);
		std::cout << John << std::endl;
		John.decrementGrade(40);
		std::cout << John << std::endl;
		// John.decrementGrade(50);
		// std::cout << John << std::endl;
		// Bureaucrat Eleni("Eleni", -2);
		
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
}