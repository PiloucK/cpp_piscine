/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:25:45 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/08 17:40:51 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class PresidentialPardonForm : public Form {

public:
	PresidentialPardonForm( const std::string target );
    PresidentialPardonForm( const PresidentialPardonForm & model );

    virtual ~PresidentialPardonForm();

    PresidentialPardonForm & operator=( const PresidentialPardonForm & model );

	static Form * formFactory( const std::string target );

protected:
	void doAction( void ) const;

private:
	PresidentialPardonForm( void );

	std::string m_Target;

};

#endif
