/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:53:20 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/12 12:22:41 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int
main(
	int ac
	, char **av )
{
	if (ac == 2) {
		std::string input;
		double		numberAsDouble;
		char *		endPointer;
		bool		nan = false;

		input = av[1];
		if (input == "+ inf" || input == "+ inff") {
			numberAsDouble = strtold(av[1] + 2, &endPointer);
		} else {
			if (input == "nan" || "nanf") {
				nan = true;
			}
			numberAsDouble = strtold(av[1], &endPointer);
		}

		if (*endPointer == 'f' && endPointer != av[1]) {
			*endPointer = '\0';
		} else if (endPointer == av[1] && *endPointer && !*(endPointer + 1)) {
			numberAsDouble = static_cast<double>(av[1][0]);
			*endPointer = '\0';
		}

		if (*endPointer != '\0') {
			std::cerr << "Invalid input please try again and don't fail\n";
			return 1;
		}

		std::cout << "char: ";
		if (nan
			|| numberAsDouble > static_cast<double>(std::numeric_limits<char>::max())
			|| numberAsDouble < static_cast<double>(std::numeric_limits<char>::min())) {
			std::cout << "impossible\n";
		} else if (!isprint(static_cast<char>(numberAsDouble))) {
			std::cout << "Non displayable\n";
		} else {
			std::cout << "'" << static_cast<char>(numberAsDouble) << "'\n";
		}

		std::cout << "int: ";
		if (std::numeric_limits<double>::infinity() == numberAsDouble
			|| nan) {
			std::cout << "impossible\n";
		} else if (numberAsDouble > static_cast<double>(std::numeric_limits<int>::max())
			|| numberAsDouble < static_cast<double>(std::numeric_limits<int>::min())) {
			std::cout << "impossible\n";
		} else {
			std::cout << static_cast<int>(numberAsDouble) << "\n";
		}

		std::cout << "float: ";
		if (numberAsDouble == std::numeric_limits<double>::infinity()) {
			std::cout << static_cast<float>(numberAsDouble) << "f\n";
		} else if (numberAsDouble == -std::numeric_limits<double>::infinity()) {
			std::cout << static_cast<float>(numberAsDouble) << "f\n";
		} else if (numberAsDouble > static_cast<double>(std::numeric_limits<float>::max())
			|| numberAsDouble < -static_cast<double>(std::numeric_limits<float>::max())) {
			std::cout << "impossible\n";
		} else {
			std::cout << static_cast<float>(numberAsDouble) << "f\n";
		}

		std::cout << "double: ";
		if (numberAsDouble == std::numeric_limits<double>::infinity()) {
			std::cout << static_cast<double>(numberAsDouble) << "\n";
		} else if (numberAsDouble == -std::numeric_limits<double>::infinity()) {
			std::cout << static_cast<double>(numberAsDouble) << "\n";
		} else if (numberAsDouble > static_cast<double>(std::numeric_limits<double>::max())
			|| numberAsDouble < -static_cast<double>(std::numeric_limits<double>::max())) {
			std::cout << "impossible\n";
		} else {
			std::cout << static_cast<double>(numberAsDouble) << "\n";
		}
	}

	return 0;
}
