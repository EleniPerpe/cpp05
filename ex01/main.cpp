/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:41:09 by eperperi          #+#    #+#             */
/*   Updated: 2025/01/02 14:40:55 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat maria("Maria", 140);
		Bureaucrat john("John", 70);
		Bureaucrat boss("Boss", 1);
		Form formBasic1("Basic1", 80, 20);
		Form formBasic2("Basic2", 150, 20);
		Form formVip("formVip", 1, 1);
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
}