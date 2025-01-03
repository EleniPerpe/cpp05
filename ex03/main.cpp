/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:41:09 by eperperi          #+#    #+#             */
/*   Updated: 2025/01/03 17:10:43 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat maria("Maria", 145);
		Bureaucrat john("John", 138);
		Bureaucrat george("George", 38);
		Bureaucrat fabian("Fabian", 5);
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm formBasic1("Home");
		ShrubberyCreationForm formVip("Garden");
		ShrubberyCreationForm formBasic2(formVip);
		formBasic1.execute(maria);
		formBasic2.execute(fabian);
		formBasic2.execute(john);
		formBasic1.execute(boss);
		formVip.execute(boss);

		// std::cout << formBasic1 << std::endl;
		
		RobotomyRequestForm formBasic3("Aris");
		RobotomyRequestForm formVip1("Mars");
		RobotomyRequestForm formBasic4(formVip1);
		formBasic3.execute(maria);
		formBasic3.execute(fabian);
		formBasic3.execute(boss);
		formVip1.execute(boss);

		// std::cout << formBasic3 << std::endl;

		PresidentialPardonForm formBasic5("Office");
		PresidentialPardonForm formVip2("White House");
		PresidentialPardonForm formBasic6(formVip2);
		formBasic5.execute(fabian);
		formBasic5.execute(george);
		formBasic5.execute(boss);
		formVip2.execute(boss);


		fabian.executeForm(formBasic3);
		george.executeForm(formBasic5);
		boss.executeForm(formVip);
		
		// std::cout << formBasic5 << std::endl;
		
		
		// maria.signForm(formBasic1);
		// maria.signForm(formBasic2);
		// maria.signForm(formVip);
		
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
	// I put it the execute function
	// catch(AForm::GradeTooLowException& e)
	// {
	// 	std::cout << "Exception : " << e.what() << std::endl;
	// }
}