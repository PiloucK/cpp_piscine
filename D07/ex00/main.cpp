/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:53:20 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/13 12:11:24 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int
main(
	void )
{
	{
		int a = 2;
		int b = 3;
		
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		
		std::string c = "chaine1";
		std::string d = "chaine2";
		
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	NEXT_TEST
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
	NEXT_TEST
	{
		std::string i = "toto", j = "riri";

		std::cout << i << " | " << j << '\n';
		::swap<std::string>(i, j);
		std::cout << i << " | " << j << '\n';
		swap(i, j);
		std::cout << i << " | " << j << '\n';
		std::cout << min<std::string>(i, j) << "\n";
		std::cout << max<std::string>(i, j) << "\n";
	}
	NEXT_TEST
	{
		time_t i, j;

		time(&i);
		time(&j);

		std::cout << i << " | " << j << '\n';
		swap<time_t>(i, j);
		std::cout << i << " | " << j << '\n';
		swap(i, j);
		std::cout << i << " | " << j << '\n';
		std::cout << min<time_t>(i, j) << "\n";
		std::cout << max<time_t>(i, j) << "\n";
	}
	return 0;
}
