/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:08:21 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/08 19:04:46 by Clkuznie         ###   ########.fr       */
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
	(void)model;
}

Intern::~Intern(
	void )
{
}

Intern &
Intern::operator = (
	const Intern & model )
{
	(void)model;

	return (*this);
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

	return (NULL);
}
