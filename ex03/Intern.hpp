/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:33:17 by eperperi          #+#    #+#             */
/*   Updated: 2025/01/03 17:43:51 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"


class Intern
{
	public:
		Intern();
		Intern(const Intern& copy);
		~Intern();

		Intern& operator=(const Intern& copy);

		AForm* makeForm(std::string formName, std::string formTarget);
	
	class InvalidFormName : public std::exception
	{
		public:
			virtual const char* what() const throw();	
	};

	
};