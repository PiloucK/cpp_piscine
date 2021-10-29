/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:50:26 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/27 17:00:39 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat {

public:
    Bureaucrat( const std::string & name );
    Bureaucrat( const std::string & name, const int grade );
    Bureaucrat( const Bureaucrat & model );

    virtual ~Bureaucrat( void );

    Bureaucrat & operator=( const Bureaucrat & model );

	const std::string & getName( void ) const;
	int getGrade( void ) const;
	void gradeUp( void );
	void gradeDown( void );

	class GradeTooHighException : public std::exception {

		public:
			GradeTooHighException( const char * msg, const char * file, const char * function );

			const char & m_ErrorMessage;
			const char & m_FileName;
			const char & m_FunctionName;

		protected:

		private:

	};

	class GradeTooLowException : public std::exception {

		public:
			GradeTooLowException( const char * msg, const char * file, const char * function );

			const char & m_ErrorMessage;
			const char & m_FileName;
			const char & m_FunctionName;

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
