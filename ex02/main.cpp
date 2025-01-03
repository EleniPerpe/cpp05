/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:41:09 by eperperi          #+#    #+#             */
/*   Updated: 2025/01/03 13:46:10 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat maria("Maria", 140);
		Bureaucrat john("John", 70);
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm formBasic1("home");
		ShrubberyCreationForm formVip("VIP");
		ShrubberyCreationForm formBasic2(formVip);
		formBasic1.execute(maria);
		formBasic1.execute(john);
		maria.signForm(formBasic1);
		maria.signForm(formBasic2);
		maria.signForm(formVip);
		john.signForm(formBasic1);
		john.signForm(formBasic2);
		john.signForm(formVip);
		boss.signForm(formBasic1);
		boss.signForm(formBasic2);
		boss.signForm(formVip);
		
		// Bureaucrat eleni(john);
		
		// eleni.signForm(formBasic1);
		// eleni.signForm(formBasic2);
		// eleni.signForm(formVip);
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	// catch(AForm::GradeTooLowException& e)
	// {
	// 	std::cout << "Exception : " << e.what() << std::endl;
	// }
}