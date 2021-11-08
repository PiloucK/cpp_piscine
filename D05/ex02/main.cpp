/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:53:20 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/08 17:46:12 by Clkuznie         ###   ########.fr       */
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

		Form *	shrub = new ShrubberyCreationForm("toto");
		Form *	presi = new PresidentialPardonForm("toto");
		Form *	robot = new RobotomyRequestForm("toto");

		std::cout << shrub << presi << robot;

		ASSERT(shrub->getName() == "shrubbery creation");
		ASSERT(shrub->getSignGrade() == 145);
		ASSERT(shrub->getExecGrade() == 137);

		ASSERT(presi->getName() == "presidential pardon");
		ASSERT(presi->getSignGrade() == 25);
		ASSERT(presi->getExecGrade() == 5);

		ASSERT(robot->getName() == "robotomy request");
		ASSERT(robot->getSignGrade() == 72);
		ASSERT(robot->getExecGrade() == 45);

		delete shrub;
		delete presi;
		delete robot;
	}
	// 	NEXT_TEST
	// 	{
	// 		std::cout << "Try to sign form with different Bureaucrats\n";

	// 		Bureaucrat toto("Toto", 42);
	// 		Bureaucrat caren("Caren", 150);
	// 		Bureaucrat booba("Booba", 2);

	// 		ASSERT(breathe.getIsSigned() == false);
			
	// 		try {
	// 			breathe.beSigned(toto);
	// 			breathe.beSigned(caren);
	// 			breathe.beSigned(booba);
	// 		} catch (const std::exception & e) {
	// 			std::cerr << e.what();
	// 		}

	// 		ASSERT(breathe.getIsSigned() == true);

	// 		NEXT_TEST
	// 		{
	// 			std::cout << "All try to signForm (caren should not be able to)\n";
	
	// 			ASSERT(sleep.getIsSigned() == false);

	// 			try {
	// 				caren.signForm(sleep);
	// 			}
	// 			catch(const std::exception& e) {
	// 				std::cerr << e.what();
	// 				ASSERT(e.what() == GRADE_TOO_LOW_ERROR_STR);
	// 			}

	// 			ASSERT(sleep.getIsSigned() == false);

	// 			toto.signForm(sleep);
	// 			booba.signForm(sleep);

	// 			ASSERT(sleep.getIsSigned() == true);
	// 		}

	// 		NEXT_TEST
	// 		{
	// 			std::cout << "cry form try beSigned by all (caren should not be able to)\n";

	// 			cry.beSigned(toto);
	// 			cry.beSigned(booba);

	// 			try {
	// 				cry.beSigned(caren);
	// 			}
	// 			catch(const std::exception& e) {
	// 				std::cerr << e.what();
	// 				ASSERT(e.what() == GRADE_TOO_LOW_ERROR_STR);
	// 			}
	// 		}
	// 	}

	// 	NEXT_TEST
	// 	{
	// 		std::cout << "Print all the forms after testing\n";
	// 		std::cout << breathe << eat << sleep << cry << beSad;
	// 	}
	// }

	return (EXIT_SUCCESS);
}
