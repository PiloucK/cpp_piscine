
#include <iostream>
#include <sstream>
#include <cstdlib>

#include "Bureaucrat.hpp"

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

			std::cout << toto;
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

	return (EXIT_SUCCESS);
}
