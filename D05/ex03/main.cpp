/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:53:20 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/08 19:01:56 by Clkuznie         ###   ########.fr       */
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
		std::cout << "Form creation and from's data verification through ASSERT\n";

		Form *	shrub = new ShrubberyCreationForm("toto");
		Form *	presi = new PresidentialPardonForm("toto");
		Form *	robot = new RobotomyRequestForm("toto");

		std::cout << *shrub << *presi << *robot;

		ASSERT(shrub->getName() == "shrubbery creation");
		ASSERT(shrub->getSignGrade() == 145);
		ASSERT(shrub->getExecGrade() == 137);

		ASSERT(presi->getName() == "presidential pardon");
		ASSERT(presi->getSignGrade() == 25);
		ASSERT(presi->getExecGrade() == 5);

		ASSERT(robot->getName() == "robotomy request");
		ASSERT(robot->getSignGrade() == 72);
		ASSERT(robot->getExecGrade() == 45);

		NEXT_TEST
		{
			std::cout << "Try to sign form with different Bureaucrats\n";

			Bureaucrat toto("Toto", 42);
			Bureaucrat caren("Caren", 150);
			Bureaucrat booba("Booba", 2);

			ASSERT(shrub->getIsSigned() == false);
			caren.signForm(*shrub);
			ASSERT(shrub->getIsSigned() == false);
			toto.signForm(*shrub);
			ASSERT(shrub->getIsSigned() == true);
			booba.signForm(*shrub);
			ASSERT(shrub->getIsSigned() == true);

			booba.signForm(*presi);
			toto.signForm(*robot);

			NEXT_TEST
			{
				std::cout << "Caren can't do shit\n";

				caren.executeForm(*shrub);
				caren.executeForm(*robot);
				caren.executeForm(*presi);
			}

			NEXT_TEST
			{
				std::cout << "Booba is the boss\n";

				booba.executeForm(*shrub);
				booba.executeForm(*robot);
				booba.executeForm(*presi);

			}

			NEXT_TEST
			{
				std::cout << "Toto finds out if robotomy is random\n";

				toto.executeForm(*robot);
				toto.executeForm(*robot);
				toto.executeForm(*robot);
				toto.executeForm(*robot);
				toto.executeForm(*robot);
				toto.executeForm(*robot);
				toto.executeForm(*robot);
				toto.executeForm(*robot);
				toto.executeForm(*robot);

			}
		}

		NEXT_TEST
		{
			std::cout << "Print all the forms after testing and verify that vaues are still correct\n";
			std::cout << *shrub << *robot << *presi;
			\
			ASSERT(shrub->getName() == "shrubbery creation");
			ASSERT(shrub->getSignGrade() == 145);
			ASSERT(shrub->getExecGrade() == 137);

			ASSERT(presi->getName() == "presidential pardon");
			ASSERT(presi->getSignGrade() == 25);
			ASSERT(presi->getExecGrade() == 5);

			ASSERT(robot->getName() == "robotomy request");
			ASSERT(robot->getSignGrade() == 72);
			ASSERT(robot->getExecGrade() == 45);

		}
		delete shrub;
		delete presi;
		delete robot;
	}

	NEXT_TEST
	{
		std::cout << "Create an Intern and make it create Forms\n";
		
		Intern	Spiderman;

		Form *	shrub = Spiderman.makeForm("shrubbery creation", "My garden");
		Form *	presi = Spiderman.makeForm("presidential pardon", "Me");
		Form *	robot = Spiderman.makeForm("robotomy request", "Spouse");

		Form *	error = Spiderman.makeForm("Bread multiplication", "India");

		ASSERT(shrub->getName() == "shrubbery creation");
		ASSERT(shrub->getSignGrade() == 145);
		ASSERT(shrub->getExecGrade() == 137);

		ASSERT(presi->getName() == "presidential pardon");
		ASSERT(presi->getSignGrade() == 25);
		ASSERT(presi->getExecGrade() == 5);

		ASSERT(robot->getName() == "robotomy request");
		ASSERT(robot->getSignGrade() == 72);
		ASSERT(robot->getExecGrade() == 45);

		ASSERT(error == NULL);

		delete shrub;
		delete presi;
		delete robot;
	}

	return (EXIT_SUCCESS);
}
