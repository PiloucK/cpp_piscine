/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:25:45 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/05 14:27:20 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class RobotomyRequestForm : public Form {

public:
	RobotomyRequestForm( const std::string target );
    RobotomyRequestForm( const RobotomyRequestForm & model );

    virtual ~RobotomyRequestForm();

    RobotomyRequestForm & operator=( const RobotomyRequestForm & model );

	static Form * formFactory( const std::string target );

protected:
	void doAction( void ) const;

private:
	RobotomyRequestForm( void );

	std::string m_Target;

};

#endif
