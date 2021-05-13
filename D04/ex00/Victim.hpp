/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 11:23:39 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/13 11:24:53 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <string>

class Victim {

private:
    Victim( void );

    std::string m_name;

public:
    Victim( const Victim & model );
    Victim( const std::string name );

    Victim & operator=( const Victim & model );

    virtual ~Victim( void );

    const std::string & getName( void ) const ;

};

std::ostream & operator<<( std::ostream & oStream, const Victim & victim );

#endif
