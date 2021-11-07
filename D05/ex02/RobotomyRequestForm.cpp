/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:27:56 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/01 14:40:50 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(
	const std::string target )
		: Form("robotomy request", 72, 45)
		, m_Target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(
	const RobotomyRequestForm & model )
		: Form(model.getName(), model.getSignGrade(), model.getExecGrade(), model.getIsSigned())
		, m_Target(model.m_Target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(
	const RobotomyRequestForm & model )
{
	Form::operator=(model);
	m_Target = model.m_Target;
	
	return *this;
}

void
RobotomyRequestForm::doAction(
	void ) const
{
	std::cout << "rizzzzzz rizz rizz rizz rizzzzzzzzzzz riz. ";

	if (rand() > (RAND_MAX / 2)) {
		std::cout << m_Target << " robotomized.\n";
	} else {
		std::cout << " Robotomize failure.\n";
	}
}
