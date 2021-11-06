/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:50:26 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/06 16:45:59 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

# define GRADE_TOO_HIGH_ERROR_STR "Grade too high\n"
# define GRADE_TOO_LOW_ERROR_STR "Grade too low\n"
# define WORST_GRADE 150
# define BEST_GRADE 1
# define IS_TOO_LOW(x) (x > 150)
# define IS_TOO_HIGH(x) (x < 1)

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
