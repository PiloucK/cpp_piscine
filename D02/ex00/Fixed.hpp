/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:37:44 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/08 17:00:01 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {

private:
    int m_iValue;

    static const int iBitCount;

public:
    Fixed( void );
    Fixed( const Fixed & model );
    ~Fixed( void );

    Fixed & operator=( const Fixed & model );
    int getRawBits( void ) const;
    void setRawBits( int const raw );

};

#endif
