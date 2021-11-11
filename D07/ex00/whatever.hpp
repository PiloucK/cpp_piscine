/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:16:43 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/11 15:44:13 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template< typename T >
void swap( T & first, T & second ) {
    T tmp = first;

    first = second;
    second = tmp;
};

template< typename T >
T min( T & first, T & second ) {
    if (first < second) {
        return (first);
    } else {
        return (second);
    }
};

template< typename T >
T max( T & first, T & second ) {
    if (first > second) {
        return (first);
    } else {
        return (second);
    }
};

#endif
