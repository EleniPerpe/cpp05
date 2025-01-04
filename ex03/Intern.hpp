/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:33:17 by eperperi          #+#    #+#             */
/*   Updated: 2025/01/04 14:47:26 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"


class Intern
{
	public:
		Intern();
		Intern(Intern const & src);
		~Intern();

		Intern &	operator=(Intern const & src);

		AForm *	makeForm(std::string formName, std::string target);

		class InvalidFormName : public std::exception {
			public:
				virtual const char *	what() const throw();
		};

	private:
		typedef struct	sFormList
		{
			std::string const &	formName;
			AForm *	(*function)(std::string const &);
		}	formList;
};