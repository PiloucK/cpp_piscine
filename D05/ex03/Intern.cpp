/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:08:21 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/05 14:39:07 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const std::string Intern::knownForms[3] = {
	"presidential pardon"
	, "robotomy request"
	, "shrubbery creation"
};

Form *(*Intern::formFactories[3])(const std::string) = {
	&PresidentialPardonForm::formFactory
	, &RobotomyRequestForm::formFactory
	, &ShrubberyCreationForm::formFactory
};

Intern::Intern(
	void )
{
}

Intern::Intern(
	const Intern & model )
{
}

Intern &
Intern::operator = (
	const Intern & model )
{
}

Form *
Intern::makeForm(
	const std::string formName
	, const std::string target ) const
{

	for (size_t i = 0; i < 3; i++) {

		if (knownForms[i] == formName) {
			Form * newForm = (*formFactories[i])(target);
			std::cout << "Intern creates " << newForm->getName() << "\n";
			
			return (newForm);
		}
	}
}
