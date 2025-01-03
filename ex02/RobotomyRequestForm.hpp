/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:41:05 by eperperi          #+#    #+#             */
/*   Updated: 2025/01/03 15:42:22 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#pragma once

class RobotomyRequestForm : public AForm
{
	public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	~RobotomyRequestForm();
		
	RobotomyRequestForm& operator=(RobotomyRequestForm& copy);

		const std::string& getTarget() const;

		static const int signGrade = 72;
		static const int signExec = 45;
		
		void execute(const Bureaucrat& executor) const;
		
	private:
		std::string _target;
};