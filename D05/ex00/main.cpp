/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:52:08 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/07 15:50:23 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int
main(void)
{
	CLEAR_STDOUT
	START_INFO
	WAIT_INPUT
	
	{
		std::cout << "Too high grade constructor call\n";
		
		try {
			Bureaucrat toto("Caren", 0);

			std::cout << toto;
		} catch (std::exception & e) {
			std::cout << e.what();
			ASSERT(e.what() == GRADE_TOO_HIGH_ERROR_STR);
		}
	}

	NEXT_TEST
	{
		std::cout << "Too Low grade constructor call\n";
		
		try {
			Bureaucrat toto("Caren", 151);

			std::cout << toto;
		} catch (std::exception & e) {
			std::cout << e.what();
			ASSERT(e.what() == GRADE_TOO_LOW_ERROR_STR);
		}
	}

	NEXT_TEST
	{
		std::cout << "Normal best grade constructor call\n";
		
		try {
			Bureaucrat toto("Caren", 1);

			std::cout << toto;
			ASSERT(toto.getName() == "Caren");
			ASSERT(toto.getGrade() == 1);
		} catch (std::exception & e) {
			std::cout << e.what();
		}
	}

	NEXT_TEST
	{
		std::cout << "Normal worst grade constructor call\n";
		
		try {
			Bureaucrat toto("Caren", 150);

			std::cout << toto;
			ASSERT(toto.getName() == "Caren");
			ASSERT(toto.getGrade() == 150);
		} catch (std::exception & e) {
			std::cout << e.what();
		}
	}

	NEXT_TEST
	{
		std::cout << "normal random grade constructor call\n";
		
		try {
			Bureaucrat toto("Caren", 42);

			std::cout << toto;
			ASSERT(toto.getName() == "Caren");
			ASSERT(toto.getGrade() == 42);
		} catch (std::exception & e) {
			std::cout << e.what();
		}
	}

	NEXT_TEST
	{
		std::cout << "gradeDown call until failure\n";
		
		Bureaucrat toto("Caren", 42);

		std::cout << toto << '\n';
		try {
			ASSERT(toto.getName() == "Caren");
			ASSERT(toto.getGrade() == 42);

			for (int i = 0; i < 150; i++) {
				WAIT_INPUT
				ASSERT(toto.getGrade() == 42 + i);
				toto.gradeDown();
				std::cout << toto;
			}
			
		} catch (std::exception & e) {
			std::cout << e.what();
			ASSERT(toto.getGrade() == 150);
		}
	}

	NEXT_TEST
	{
		std::cout << "gradeUp call until failure\n";
		
		Bureaucrat toto("Caren", 42);

		std::cout << toto << '\n';
		try {
			ASSERT(toto.getName() == "Caren");
			ASSERT(toto.getGrade() == 42);

			for (int i = 0; i < 150; i++) {
				WAIT_INPUT
				ASSERT(toto.getGrade() == 42 - i);
				toto.gradeUp();
				std::cout << toto;
			}
			
		} catch (std::exception & e) {
			std::cout << e.what();
			ASSERT(toto.getGrade() == 1);
		}
	}

	return (EXIT_SUCCESS);
}
