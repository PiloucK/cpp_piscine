/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:52:05 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/05 14:31:46 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {

public:
	Intern( void );
    Intern( const Intern & model );

    virtual ~Intern();

    Intern & operator=( const Intern & model );

	Form * makeForm( const std::string formName, const std::string target ) const;

protected:

private:
	static const std::string knownForms[3];
	static Form * (* formFactories[3])(const std::string);

};

#endif
