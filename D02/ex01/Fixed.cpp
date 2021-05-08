/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 16:02:26 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/08 17:39:27 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Constructor by default
Fixed::Fixed(
    void )
        : m_iValue(0)
{
    std::cout << "Default constructor called\n";
}

// Constructor from Fixed
Fixed::Fixed(
    const Fixed & model )
{
    std::cout << "Copy constructor called\n";

    *this = model;
}

// Constructor from int
Fixed::Fixed(
    const int iValue )
        : m_iValue(iValue << Fixed::iBitCount)
{
    std::cout << "Int constructor called\n";
}

// Constructor from Float
Fixed::Fixed(
    const float fValue )
        : m_iValue(roundf(fValue * (1 << Fixed::iBitCount)))
{
    std::cout << "Float constructor called\n";
}

Fixed::~Fixed(
    void )
{
    std::cout << "Destructor called\n";
}

Fixed &
Fixed::operator=(
    const Fixed & model )
{
    std::cout << "Assignation operator called\n";

    this->m_iValue = model.getRawBits();

    return *this;
}

int
Fixed::getRawBits(
    void ) const
{
    // std::cout << "getRawBits member function called\n";

    return this->m_iValue;
}

void
Fixed::setRawBits(
    int const raw )
{
    // std::cout << "setRawBits member function called\n";

    this->m_iValue = raw;
}

int
Fixed::toInt(
    void ) const
{
    return this->m_iValue >> Fixed::iBitCount;
}

float
Fixed::toFloat(
    void ) const
{
    return float(this->m_iValue) / (1 << Fixed::iBitCount);
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const Fixed & fixed )
{
	return (oStream << fixed.toFloat());
}

const int
Fixed::iBitCount = 8;
