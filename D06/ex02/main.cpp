/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:53:20 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/12 18:12:25 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Base *
generate(
	void )
{
	int randomNumber = rand();

	if (randomNumber > (RAND_MAX / 3 * 2)) {
		return (new A());
	} else if (randomNumber > (RAND_MAX / 3)) {
		return (new B());
	} else {
		return (new C());
	}
}

void
identify(
	Base * p )
{
	Base * castReturn;

	castReturn = dynamic_cast<A *>(p);
	if (castReturn) {
		std::cout << "A";
	} else if ((castReturn = dynamic_cast<B *>(p))) {
		std::cout << "B";
	} else if ((castReturn = dynamic_cast<C *>(p))) {
		std::cout << "C";
	} else {
		std::cout << "Something's wrong\n";
	}

	return ;
}

void
identify(
	Base & p )
{
	try {
		
		Base & castReturn = dynamic_cast<A &>(p); (void)castReturn;
		std::cout << "A";

	} catch (const std::exception & e) {


		try {
			Base & castReturn = dynamic_cast<B &>(p); (void)castReturn;
			std::cout << "B";
			
		} catch (const std::exception & e) {

			try {
				
				Base & castReturn = dynamic_cast<C &>(p); (void)castReturn;
				std::cout << "C";
				
			} catch (const std::exception & e) {
				std::cout << "Something's wrong\n";
			}
		}
	}

	return ;
}

int
main(
	void )
{
	CLEAR_STDOUT
	START_INFO
	WAIT_INPUT

	std::srand(std::time(NULL));
	Base * testArray[10];

	for (size_t i = 0; i < 10; i++) {
		testArray[i] = generate();
	}

	std::cout << "From pointer | From reference\n";
	for (size_t i = 0; i < 10; i++) {
		std::cout << "           ";
		identify(testArray[i]);
		std::cout << " | ";
		identify(*testArray[i]);
		std::cout << '\n';
	}
	
	return 0;
}
