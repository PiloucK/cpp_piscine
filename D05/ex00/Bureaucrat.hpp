/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:50:26 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/25 16:56:48 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat {

public:
    Bureaucrat( const std::string & name );
    Bureaucrat( const Bureaucrat & model );

    virtual ~Bureaucrat( void );

    Bureaucrat & operator=( const Bureaucrat & model );

	const std::string & getName( void ) const;
	const std::string & getGrade( void ) const;
	void gradeUp( void );
	void gradeDown( void );

protected:

private:
    Bureaucrat( void );

	const std::string m_Name;
	unsigned int m_Grade; // Max 1 (best note) min 150 (worst note)

};

std::ostream & operator<<( std::ostream & stream, const Bureaucrat & a_Bureaucrat );

#endif
