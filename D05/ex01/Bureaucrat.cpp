/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:23:38 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/31 14:08:21 by Clkuznie         ###   ########.fr       */
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
	return ("Grade exceeding the highest (1)");
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
	return ("Grade subceeding the lowest (150)");
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const Bureaucrat & a_Bureaucrat )
{
    oStream << a_Bureaucrat.getName() << ", bureaucrat grade " << a_Bureaucrat.getGrade() << ".\n";

    return (oStream);
}


	//} catch (GradeTooHighException & e) {
	//	std::cout << e.m_ErrorMessage << '\n';
	//	std::cout << "Error in file: " << e.m_FileName << ", function: ";
	//	std::cout << e.m_ErrorMessage << '\n';
	//}