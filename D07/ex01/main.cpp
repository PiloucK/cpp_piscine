/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:53:20 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/11 19:11:18 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void
bzero(
	int & i )
{
	i = 0;
}

template< typename T >
void
bnumber(
	T & i )
{
	i = rand();
}

template< typename T >
void
increase(
	T & i )
{
	i = i + 1;
}

int
main(
	void )
{
	std::srand(std::time(NULL));
	int		array[10];

	for (size_t i = 0; i < 10; i++) {
		array[i] = i;
	}

	for (size_t i = 0; i < 10; i++) {
		std::cout << array[i];
		std::cout << '\n';
	}

	iter<int>(array, 10, bzero);

	for (size_t i = 0; i < 10; i++) {
		std::cout << array[i];
		std::cout << '\n';
	}

	float	arrayf[10];
	iter(arrayf, 10, bnumber);

	for (size_t i = 0; i < 10; i++) {
		std::cout << arrayf[i];
		std::cout << '\n';
	}

	iter<int>(array, 10, increase);
	iter<int>(array, 7, increase);
	iter<int>(array, 7, increase);
	iter<int>(array, 1, increase);

	for (size_t i = 0; i < 10; i++) {
		std::cout << array[i];
		std::cout << '\n';
	}

	return 0;
}
