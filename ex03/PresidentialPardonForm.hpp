/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:41:05 by eperperi          #+#    #+#             */
/*   Updated: 2025/01/02 16:57:54 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#pragma once

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();
		
		PresidentialPardonForm& operator=(PresidentialPardonForm& copy);

		const std::string& getTarget() const;

		static const int signGrade = 25;
		static const int signExec = 5;
		
		void execute(const Bureaucrat& executor) const;
		
	private:
		std::string _target;
};