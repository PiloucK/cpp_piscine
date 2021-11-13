/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:23:38 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/12 18:06:40 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(
    const std::string & name )
		: m_Name(name)
		, m_MinSignGrade(WORST_GRADE)
		, m_MinExecGrade(WORST_GRADE)
		, m_IsSigned(false)
{
}

Form::Form(
    const std::string & name
	, const bool isSigned )
		: m_Name(name)
		, m_MinSignGrade(WORST_GRADE)
		, m_MinExecGrade(WORST_GRADE)
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

	if (IS_HIGHER_GRADE(BEST_GRADE, m_MinSignGrade) || IS_HIGHER_GRADE(BEST_GRADE, m_MinExecGrade)) {
		throw GradeTooHighException();
	} else if (IS_LOWER_GRADE(WORST_GRADE, m_MinSignGrade) || IS_LOWER_GRADE(WORST_GRADE, m_MinExecGrade)) {
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

	if (IS_HIGHER_GRADE(BEST_GRADE, m_MinSignGrade) || IS_HIGHER_GRADE(BEST_GRADE, m_MinExecGrade)) {
		throw GradeTooHighException();
	} else if (IS_LOWER_GRADE(WORST_GRADE, m_MinSignGrade) || IS_LOWER_GRADE(WORST_GRADE, m_MinExecGrade)) {
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

Form &
Form::beSigned(
	const Bureaucrat & a_Bureaucrat )
{

	if (!IS_LOWER_GRADE(m_MinSignGrade, a_Bureaucrat.getGrade())) {
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
	if (m_IsSigned == false) {
		throw FormNotSigned();
	} else if (IS_LOWER_GRADE(m_MinExecGrade, executor.getGrade())) {
		throw GradeTooLowException();
	}

	doAction();
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

Form::GradeTooHighException::GradeTooHighException(
	void )
{
}

Form::GradeTooHighException::~GradeTooHighException() throw ()
{
}

const char *
Form::GradeTooHighException::what() const throw ()
{
	return (GRADE_TOO_HIGH_ERROR_STR);
}

Form::GradeTooLowException::GradeTooLowException(
	void )
{
}

Form::GradeTooLowException::~GradeTooLowException() throw ()
{
}

const char *
Form::GradeTooLowException::what() const throw ()
{
	return (GRADE_TOO_LOW_ERROR_STR);
}

Form::FormNotSigned::FormNotSigned(
	void )
{
}

Form::FormNotSigned::~FormNotSigned() throw ()
{
}

const char *
Form::FormNotSigned::what() const throw ()
{
	return (FORM_NOT_SIGNED_ERROR_STR);
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
