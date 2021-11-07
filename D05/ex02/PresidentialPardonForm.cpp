/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:27:56 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/01 14:49:10 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(
	const std::string target )
		: Form("presidential pardon", 25, 5)
		, m_Target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm & model )
		: Form(model.getName(), model.getSignGrade(), model.getExecGrade(), model.getIsSigned())
		, m_Target(model.m_Target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(
	const PresidentialPardonForm & model )
{
	Form::operator=(model);
	m_Target = model.m_Target;
	
	return *this;
}

void
PresidentialPardonForm::doAction(
	void ) const
{
	std::cout << m_Target << " got the Beeblebrox's clemency.\n";
}
