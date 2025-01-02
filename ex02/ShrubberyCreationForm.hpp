/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:41:05 by eperperi          #+#    #+#             */
/*   Updated: 2025/01/02 16:57:54 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#pragma once

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		~ShrubberyCreationForm();
		
		ShrubberyCreationForm& operator=(ShrubberyCreationForm& copy);

		const std::string& getTarget() const;

		static const int signGrade = 145;
		static const int signExec = 137;
		
		void execute(const Bureaucrat& executor) const;
		
	private:
		std::string _target;
		static const std::string _tree1;
		static const std::string _tree2;
};