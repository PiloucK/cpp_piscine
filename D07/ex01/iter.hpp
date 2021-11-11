/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <cluznie@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:29:25 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/11 21:08:57 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template< typename T >
void
iter(
	T * array
	, size_t array_size
	, void (*function)(T &) )
{
	if (!function || !array || array_size == 0 || array_size < 0) {
		return ;
	}

	for (size_t i = 0; i < array_size; i++) {
		(*function)(array[i]);
	}

	return ;
}

#endif
