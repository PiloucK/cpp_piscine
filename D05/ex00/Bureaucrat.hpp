/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:50:26 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/11 15:03:23 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "gradesMacro.hpp"

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

	class GradeTooHighException : public std::exception {

		public:
			GradeTooHighException( void );

			virtual ~GradeTooHighException();

			const char * what() const throw ();

		protected:

		private:
	};

	class GradeTooLowException : public std::exception {

		public:
			GradeTooLowException( void );

			virtual ~GradeTooLowException();

			const char * what() const throw ();

		protected:

		private:
	};

protected:

private:
    Bureaucrat( void );

	const std::string m_Name;
	unsigned int m_Grade;

};

std::ostream & operator<<( std::ostream & stream, const Bureaucrat & a_Bureaucrat );

#endif
