/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:23:38 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/02 14:50:40 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(
    const std::string & name )
		: m_Name(name)
		, m_MinSignGrade(150)
		, m_MinExecGrade(150)
		, m_IsSigned(false)
{
}

Form::Form(
    const std::string & name
	, const bool isSigned )
		: m_Name(name)
		, m_MinSignGrade(150)
		, m_MinExecGrade(150)
		, m_IsSigned(isSigned)
{
}

Form::Form(
    const std::string & name
	, const int minSignGrade
	, const int minExecGrade )
		: m_Name(name)
		, m_MinSignGrade(minSignGrade)
		, m_MinExecGrade(minExecGrade)
		, m_IsSigned(false)
{

	if (m_MinSignGrade < 1 || m_MinExecGrade < 1) {
		throw GradeTooHighException();
	} else if (m_MinSignGrade > 150 || m_MinExecGrade > 150) {
		throw GradeTooLowException();
	}
}

Form::Form(
    const std::string & name
	, const int minSignGrade
	, const int minExecGrade
	, const bool isSigned )
		: m_Name(name)
		, m_MinSignGrade(minSignGrade)
		, m_MinExecGrade(minExecGrade)
		, m_IsSigned(isSigned)
{

	if (m_MinSignGrade < 1 || m_MinExecGrade < 1) {
		throw GradeTooHighException();
	} else if (m_MinSignGrade > 150 || m_MinExecGrade > 150) {
		throw GradeTooLowException();
	}
}

Form::Form(
    const Form & model )
		: m_Name(model.m_Name)
		, m_MinSignGrade(model.m_MinSignGrade)
		, m_MinExecGrade(model.m_MinExecGrade)
		, m_IsSigned(model.m_IsSigned)
{
}

Form::~Form(
    void )
{
}

Form &
Form::operator=(
    const Form & model )
{
	m_IsSigned = model.m_IsSigned;

	return (*this);
}

const std::string &
Form::getName(
	void ) const
{
	return (m_Name);
}

int
Form::getSignGrade(
	void ) const
{
	return (m_MinSignGrade);
}

int
Form::getExecGrade(
	void ) const
{
	return (m_MinExecGrade);
}

bool
Form::getIsSigned(
	void ) const
{
	return (m_IsSigned);
}

Form &
Form::beSigned(
	const Bureaucrat & a_Bureaucrat )
{

	if (a_Bureaucrat.getGrade() <= m_MinSignGrade) {
		m_IsSigned = true;
	} else {
		throw GradeTooLowException();
	}

	return *this;
}

void
Form::execute(
	Bureaucrat const & executor ) const
{

	if (executor.getGrade() > m_MinExecGrade) {
		throw GradeTooLowException();
	} else if (m_IsSigned == false) {
		throw FormNotSigned();
	}

	doAction();
}

Form::GradeTooHighException::GradeTooHighException(
	void )
{
}

Form::GradeTooHighException::~GradeTooHighException() _NOEXCEPT
{
}

const char *
Form::GradeTooHighException::what() const throw ()
{
	return ("Grade exceeding the maximal value for the action\n");
}

Form::GradeTooLowException::GradeTooLowException(
	void )
{
}

Form::GradeTooLowException::~GradeTooLowException() _NOEXCEPT
{
}

const char *
Form::GradeTooLowException::what() const throw ()
{
	return ("Grade subceeding the minimal value for the action\n");
}

Form::FormNotSigned::FormNotSigned(
	void )
{
}

Form::FormNotSigned::~FormNotSigned() _NOEXCEPT
{
}

const char *
Form::FormNotSigned::what() const throw ()
{
	return ("Form has to get signed before execution\n");
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const Form & a_Form )
{
    oStream << a_Form.getName();
	
	if (a_Form.getIsSigned() != true) {
		oStream << ", not signed";
	} else {
		oStream << ", signed";
	}
	
	oStream << " form (needs grade " << a_Form.getSignGrade()
		<< " to get signed and grade " << a_Form.getExecGrade()
		<< " to get executed).\n";

    return (oStream);
}
