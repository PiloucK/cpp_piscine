/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 16:02:26 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/08 16:05:39 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(
    void )
        : m_iValue(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(
    const Fixed & model )
{
    std::cout << "Copy constructor called\n";

    *this = model;
}

Fixed::~Fixed(
    void )
{
    std::cout << "Destructor called\n";
}

Fixed &
Fixed::operator=(
    const Fixed &other )
{
    std::cout << "Assignation operator called\n";

    this->m_iValue = other.getRawBits();

    return *this;
}

int
Fixed::getRawBits(
    void ) const
{
    std::cout << "getRawBits member function called\n";

    return this->m_iValue;
}

void
Fixed::setRawBits(
    int const raw )
{
    std::cout << "setRawBits member function called\n";

    this->m_iValue = raw;
}

const int
Fixed::iBitCount = 8;
