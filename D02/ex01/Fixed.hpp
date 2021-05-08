/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:37:44 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/08 17:34:22 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

private:
    int m_iValue;

    static const int iBitCount;

public:
    Fixed( void );
    Fixed( const Fixed & model );
    Fixed( const int iValue );
    Fixed( const float fValue );

    ~Fixed( void );

    Fixed & operator=( const Fixed & model );

    int getRawBits( void ) const;
    void setRawBits( int const raw );

    int toInt( void ) const;
    float toFloat( void )const;
};

std::ostream & operator<<( std::ostream & stream, const Fixed & fixed );

#endif
