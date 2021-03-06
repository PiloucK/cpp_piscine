/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:50:26 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/12 18:06:40 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"
# include "gradesMacro.hpp"

class Bureaucrat;

class Form {

public:
	Form( const std::string & name );
	Form( const std::string & name, const bool isSigned);
    Form( const std::string & name, const int minSignGrade, const int minExecGrade );
    Form( const std::string & name, const int minSignGrade, const int minExecGrade, const bool isSigned );
    Form( const Form & model );

    virtual ~Form();

    Form & operator=( const Form & model );

	const std::string & getName( void ) const;
	int getSignGrade( void ) const;
	int getExecGrade( void ) const; 
	bool getIsSigned( void ) const;

	Form & beSigned( const Bureaucrat & a_Bureaucrat );

	class GradeTooHighException : public std::exception {

		public:
			GradeTooHighException( void );

			virtual ~GradeTooHighException() throw ();

			const char * what() const throw ();

		protected:

		private:
	};

	class GradeTooLowException : public std::exception {

		public:
			GradeTooLowException( void );

			virtual ~GradeTooLowException() throw ();

			const char * what() const throw ();

		protected:

		private:
	};

protected:

private:
    Form( void );

	const std::string m_Name;
	const int m_MinSignGrade;
	const int m_MinExecGrade;
	bool m_IsSigned;

};

std::ostream & operator<<( std::ostream & stream, const Form & a_Form );

#endif
