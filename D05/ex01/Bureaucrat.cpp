/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:23:38 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/07 15:54:01 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(
    const std::string & name )
		: m_Name(name)
		, m_Grade(WORST_GRADE)
{
}

Bureaucrat::Bureaucrat(
	const std::string & name
	, const int grade )
		: m_Name(name)
		, m_Grade(grade)
{
	if (IS_HIGHER_GRADE(BEST_GRADE, grade)) {
		throw GradeTooHighException();
	} else if (IS_LOWER_GRADE(WORST_GRADE, grade)) {
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(
    const Bureaucrat & model )
		: m_Name(model.m_Name)
		, m_Grade(model.m_Grade)
{
}

Bureaucrat::~Bureaucrat(
    void )
{
}

Bureaucrat &
Bureaucrat::operator = (
    const Bureaucrat & model )
{
	m_Grade = model.m_Grade;

	return (*this);
}

void
Bureaucrat::signForm(
	Form & a_Form ) const
{
	try {
		a_Form.beSigned(*this);

		std::cout << m_Name << " signs " << a_Form.getName() << '\n';
	} catch (std::exception & e) {
		std::cout << m_Name << " cannot sign because:\n" << e.what();
	}
}

const std::string &
Bureaucrat::getName(
	void ) const
{
	return (m_Name);
}

int
Bureaucrat::getGrade(
	void ) const
{
	return (m_Grade);
}

void
Bureaucrat::gradeUp(
	void )
{
	if (!IS_HIGHER_GRADE(BEST_GRADE, ONE_HIGHER(m_Grade))) {
		m_Grade = ONE_HIGHER(m_Grade);
	} else {
		throw GradeTooHighException();
	}
}

void
Bureaucrat::gradeDown(
	void )
{
	if (!IS_LOWER_GRADE(WORST_GRADE, ONE_LOWER(m_Grade))) {
		m_Grade = ONE_LOWER(m_Grade);
	} else {
		throw GradeTooLowException();
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException(
	void )
{
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() _NOEXCEPT
{
}

const char *
Bureaucrat::GradeTooHighException::what() const throw ()
{
	return (GRADE_TOO_HIGH_ERROR_STR);
}

Bureaucrat::GradeTooLowException::GradeTooLowException(
	void )
{
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() _NOEXCEPT
{
}

const char *
Bureaucrat::GradeTooLowException::what() const throw ()
{
	return (GRADE_TOO_LOW_ERROR_STR);
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const Bureaucrat & a_Bureaucrat )
{
    oStream << a_Bureaucrat.getName() << ", bureaucrat grade " << a_Bureaucrat.getGrade() << ".\n";

    return (oStream);
}
