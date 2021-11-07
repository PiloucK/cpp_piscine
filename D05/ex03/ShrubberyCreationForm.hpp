/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:25:45 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/05 14:27:27 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include <fstream>

class ShrubberyCreationForm : public Form {

public:
	ShrubberyCreationForm( const std::string target );
    ShrubberyCreationForm( const ShrubberyCreationForm & model );

    virtual ~ShrubberyCreationForm();

    ShrubberyCreationForm & operator=( const ShrubberyCreationForm & model );

	static Form * formFactory( const std::string target );

protected:
	void doAction( void ) const;

private:
	ShrubberyCreationForm( void );

	std::string m_Target;

};

#endif
