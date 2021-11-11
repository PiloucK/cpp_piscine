/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:53:20 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/11 15:46:42 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int
main(
	void )
{
	{
		int i = 0, j = 4;

		std::cout << i << " | " << j << '\n';
		swap<int>(i, j);
		std::cout << i << " | " << j << '\n';
		swap(i, j);
		std::cout << i << " | " << j << '\n';
		std::cout << min(i, j) << "\n";
		std::cout << min<int>(i, j) << "\n";
		std::cout << max(i, j) << "\n";
		std::cout << max<int>(i, j) << "\n";
	}
	NEXT_TEST
	{
		int i = 4, j = 4;

		std::cout << i << " | " << j << '\n';
		swap<int>(i, j);
		std::cout << i << " | " << j << '\n';
		swap(i, j);
		std::cout << i << " | " << j << '\n';
		std::cout << min<int>(i, j) << "\n";
		std::cout << max<int>(i, j) << "\n";
	}
	NEXT_TEST
	{
		float i = 12341.9, j = 4;

		std::cout << i << " | " << j << '\n';
		swap<float>(i, j);
		std::cout << i << " | " << j << '\n';
		swap(i, j);
		std::cout << i << " | " << j << '\n';
		std::cout << min<float>(i, j) << "\n";
		std::cout << max<float>(i, j) << "\n";
	}
	return 0;
}
