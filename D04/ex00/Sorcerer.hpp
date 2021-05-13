/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 10:35:08 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/13 11:24:29 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <string>

class Sorcerer {

private:
    Sorcerer( void );

    std::string m_name;
    std::string m_title;

public:
    Sorcerer( const Sorcerer & model );
    Sorcerer( const std::string name
        , const std::string title );

    Sorcerer & operator=( const Sorcerer & model );

    virtual ~Sorcerer( void );

    const std::string & getName( void ) const ;
    const std::string & getTitle( void ) const ;

};

std::ostream & operator<<( std::ostream & oStream, const Sorcerer & sorcerer );

#endif
