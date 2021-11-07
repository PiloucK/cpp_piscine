/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:23:38 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/01 14:54:41 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(
    const std::string & name )
		: m_Name(name)
		, m_Grade(150)
{
}

Bureaucrat::Bureaucrat(
	const std::string & name
	, const int grade )
		: m_Name(name)
		, m_Grade(grade)
{
	if (m_Grade < 1) {
		throw GradeTooHighException();
	} else if (m_Grade > 150) {
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
Bureaucrat::operator=(
    const Bureaucrat & model )
{
	m_Grade = model.m_Grade;

	return (*this);
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
	if (m_Grade > 1) {
		m_Grade--;
	} else {
		throw GradeTooHighException();
	}
}

void
Bureaucrat::gradeDown(
	void )
{
	if (m_Grade < 150) {
		m_Grade++;
	} else {
		throw GradeTooLowException();
	}
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

void
Bureaucrat::executeForm(
	const Form & Form ) const
{

	try {
		Form.execute(*this);
	} catch(const std::exception& e) {
		std::cout << *this;
		std::cout << Form;
		std::cout << "Execution failed because:\n";
		std::cout << e.what();
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
	return ("Grade exceeding the highest (1)\n");
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
	return ("Grade subceeding the lowest (150)\n");
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const Bureaucrat & a_Bureaucrat )
{
    oStream << a_Bureaucrat.getName() << ", bureaucrat grade " << a_Bureaucrat.getGrade() << ".\n";

    return (oStream);
}
