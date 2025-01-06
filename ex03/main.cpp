/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:41:09 by eperperi          #+#    #+#             */
/*   Updated: 2025/01/06 15:37:12 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void testIntern(std::string formName, std::string target)
{
	Bureaucrat maria("Maria", 138);
	Bureaucrat john("John", 138);
	Bureaucrat george("George", 38);
	Bureaucrat fabian("Fabian", 5);
	Bureaucrat boss("Boss", 1);

	Intern a = Intern();
	AForm* form;

	try
	{
		form = a.makeForm(formName, target);
		boss.signForm(*form);
		maria.executeForm(*form);
		george.executeForm(*form);
		boss.executeForm(*form);
		delete(form);
	}
	catch(Intern::InvalidFormName& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
}

int main()
{

	Bureaucrat maria("Maria", 145);
	Bureaucrat john("John", 138);
	Bureaucrat george("George", 38);
	Bureaucrat fabian("Fabian", 5);
	Bureaucrat boss("Boss", 1);


	testIntern("presidentials pardon", "White House");
	testIntern("shrubbery creation", "Home");
	testIntern("robotomy request", "Garden");
	testIntern("presidential pardon", "White House");
}