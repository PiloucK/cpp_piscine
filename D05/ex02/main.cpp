
#include <iostream>
#include <sstream>
#include <cstdlib>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int
main(void)
{
	std::cout << "\033[2J";
	std::cout << "To start the tests and go to the next one, press ENTER\n";

	std::cin.get();
	{
		std::cout << "\033[2J";
		std::cout << "Too high grade constructor call\n";
		
		try {
			Bureaucrat toto("Caren", 0);

			std::cout << toto;
		} catch (std::exception & e) {
			std::cout << e.what() << '\n';
		}
	}

	std::cin.get();
	{
		std::cout << "\033[2J";
		std::cout << "Too Low grade constructor call\n";
		
		try {
			Bureaucrat toto("Caren", 151);

			std::cout << toto;
		} catch (std::exception & e) {
			std::cout << e.what() << '\n';
		}
	}

	std::cin.get();
	{
		std::cout << "\033[2J";
		std::cout << "Normal best grade constructor call\n";
		
		try {
			Bureaucrat toto("Caren", 1);

			std::cout << toto;/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:52:08 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/07 17:32:56 by Clkuznie         ###   ########.fr       */
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

			WAIT_INPUT
			for (int i = 0; i < 150; i++) {
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

			WAIT_INPUT
			for (int i = 0; i < 150; i++) {
				ASSERT(toto.getGrade() == 42 - i);
				toto.gradeUp();
				std::cout << toto;
			}
			
		} catch (std::exception & e) {
			std::cout << e.what();
			ASSERT(toto.getGrade() == 1);
		}
	}

	NEXT_TEST
	{
		std::cout << "Form creation in and out of bounds\n";

		Form	breathe("breathe");
		Form	eat("eat", true);
		Form	sleep("sleep", 42, 42);
		Form	cry("cry", 42, 42, true);
		Form	beSad("be sad", 150, 1);

		std::cout << breathe << eat << sleep << cry << beSad;

		try {
			Form	beHappy("be happy", 0, 42, false);
		} catch(const std::exception& e) {
			std::cerr << e.what();
			ASSERT(e.what() == GRADE_TOO_HIGH_ERROR_STR);
		}
		
		try {
			Form	shout("shout", 1, 160, true);
		} catch(const std::exception & e) {
			std::cerr << e.what();
			ASSERT(e.what() == GRADE_TOO_LOW_ERROR_STR);
		}

		NEXT_TEST
		{
			std::cout << "Try to sign form with different Bureaucrats\n";

			Bureaucrat toto("Toto", 42);
			Bureaucrat caren("Caren", 150);
			Bureaucrat booba("Booba", 2);

			ASSERT(breathe.getIsSigned() == false);
			
			try {
				breathe.beSigned(toto);
				breathe.beSigned(caren);
				breathe.beSigned(booba);
			} catch (const std::exception & e) {
				std::cerr << e.what();
			}

			ASSERT(breathe.getIsSigned() == true);

			NEXT_TEST
			{
				std::cout << "All try to signForm (caren should not be able to)\n";
	
				ASSERT(sleep.getIsSigned() == false);

				try {
					caren.signForm(sleep);
				}
				catch(const std::exception& e) {
					std::cerr << e.what();
					ASSERT(e.what() == GRADE_TOO_LOW_ERROR_STR);
				}

				ASSERT(sleep.getIsSigned() == false);

				toto.signForm(sleep);
				booba.signForm(sleep);

				ASSERT(sleep.getIsSigned() == true);
			}

			NEXT_TEST
			{
				std::cout << "cry form try beSigned by all (caren should not be able to)\n";

				cry.beSigned(toto);
				cry.beSigned(booba);

				try {
					cry.beSigned(caren);
				}
				catch(const std::exception& e) {
					std::cerr << e.what();
					ASSERT(e.what() == GRADE_TOO_LOW_ERROR_STR);
				}
			}
		}

		NEXT_TEST
		{
			std::cout << "Print all the forms after testing\n";
			std::cout << breathe << eat << sleep << cry << beSad;
		}
	}

	return (EXIT_SUCCESS);
}

		} catch (std::exception & e) {
			std::cout << e.what() << '\n';
		}
	}

	std::cin.get();
	{
		std::cout << "\033[2J";
		std::cout << "Normal worst grade constructor call\n";
		
		try {
			Bureaucrat toto("Caren", 150);

			std::cout << toto;
		} catch (std::exception & e) {
			std::cout << e.what() << '\n';
		}
	}

	std::cin.get();
	{
		std::cout << "\033[2J";
		std::cout << "normal random grade constructor call\n";
		
		try {
			Bureaucrat toto("Caren", 42);

			std::cout << toto;
		} catch (std::exception & e) {
			std::cout << e.what() << '\n';
		}
	}

	std::cin.get();
	{
		std::cout << "\033[2J";
		std::cout << "gradeDown call until failure\n";
		
		try {
			Bureaucrat toto("Caren", 42);

			std::cout << toto << '\n';

			for (size_t i = 0; i < 150; i++) {
				toto.gradeDown();
				std::cout << toto;
			}
			
		} catch (std::exception & e) {
			std::cout << e.what() << '\n';
		}
	}

	std::cin.get();
	{
		std::cout << "\033[2J";
		std::cout << "gradeUp call until failure\n";
		
		try {
			Bureaucrat toto("Caren", 42);

			std::cout << toto << '\n';

			for (size_t i = 0; i < 150; i++) {
				toto.gradeUp();
				std::cout << toto;
			}
			
		} catch (std::exception & e) {
			std::cout << e.what() << '\n';
		}
	}

	std::cin.get();
	{
		std::cout << "\033[2J";
		std::cout << "gradeUp call until failure\n";
		
		try {
			Bureaucrat toto("Caren", 42);
			ShrubberyCreationForm form("Trump");
			ShrubberyCreationForm form2("Trump");

			std::cout << toto << '\n';

			std::cout << form;
			toto.signForm(form);
			std::cout << form;
			form2 = form;
			std::cout << form2;

			std::cout << '\n';
			form.execute(toto);
		} catch (std::exception & e) {
			std::cout << e.what() << '\n';
		}
	}

	return (EXIT_SUCCESS);
}
