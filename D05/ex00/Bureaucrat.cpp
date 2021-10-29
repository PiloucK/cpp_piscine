/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:23:38 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/29 13:53:31 by Clkuznie         ###   ########.fr       */
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
		throw GradeTooHighException("Already at highest grade", __FILE__, __func__);
	} else if (m_Grade > 150) {
		throw GradeTooLowException("Already at lowest grade", __FILE__, __func__);
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
		throw GradeTooHighException("Already at highest grade", __FILE__, __func__);
	}
}

void
Bureaucrat::gradeDown(
	void )
{
	if (m_Grade < 150) {
		m_Grade++;
	} else {
		throw GradeTooLowException("Already at lowest grade", __FILE__, __func__);
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException(
	const char * msg
	, const char * file
	, const char * function )
		: m_ErrorMessage(*msg)
		, m_FileName(*file)
		, m_FunctionName(*function)
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(
	const char * msg
	, const char * file
	, const char * function )
		: m_ErrorMessage(*msg)
		, m_FileName(*file)
		, m_FunctionName(*function)
{
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