/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:57:54 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/08/12 17:39:12 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain {

public:
    Brain( void );
    Brain( const std::string model_ideas[100] );
    Brain( const Brain & model );

    virtual ~Brain( void );

    Brain & operator=( const Brain & model );

protected:
    std::string ideas[100];
    
private:

};

std::ostream & operator<<( std::ostream & stream, const Brain & a_Brain );

#endif
