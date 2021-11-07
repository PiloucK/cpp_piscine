/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:25:45 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/01 15:06:02 by Clkuznie         ###   ########.fr       */
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


protected:
	void doAction( void ) const;

private:
	RobotomyRequestForm( void );

	std::string m_Target;

};

#endif
