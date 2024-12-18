/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:16:25 by eperperi          #+#    #+#             */
/*   Updated: 2024/12/18 15:53:47 by eperperi         ###   ########.fr       */
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
		Bureaucrat Eleni("Eleni", 170);
		
	}
	catch(Bureaucrat::LowGradeException& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	catch(Bureaucrat::HighGradeException& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
}