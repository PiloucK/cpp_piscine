/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:50:26 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/07 19:58:27 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include "gradesMacro.hpp"


class Form;

class Bureaucrat {

public:
    Bureaucrat( const std::string & name );
    Bureaucrat( const std::string & name, const int grade );
    Bureaucrat( const Bureaucrat & model );

    virtual ~Bureaucrat();

    Bureaucrat & operator=( const Bureaucrat & model );

	const std::string & getName( void ) const;
	int getGrade( void ) const;
	void gradeUp( void );
	void gradeDown( void );

	void signForm( Form & a_Form ) const;
	void executeForm( const Form & form ) const;

	class GradeTooHighException : public std::exception {

		public:
			GradeTooHighException( void );

			virtual ~GradeTooHighException() _NOEXCEPT;

			const char * what() const throw ();

		protected:

		private:
	};

	class GradeTooLowException : public std::exception {

		public:
			GradeTooLowException( void );

			virtual ~GradeTooLowException() _NOEXCEPT;

			const char * what() const throw ();

		protected:

		private:
	};

protected:

private:
    Bureaucrat( void );

	const std::string m_Name;
	unsigned int m_Grade; // Max 1 (best note) min 150 (worst note)

};

std::ostream & operator<<( std::ostream & stream, const Bureaucrat & a_Bureaucrat );

#endif
