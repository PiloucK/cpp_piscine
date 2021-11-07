/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:01:37 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/04 16:16:35 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include "Character.hpp"
# include "Cure.hpp"
# include "Ice.hpp"
# include "MateriaSource.hpp"

# ifdef DEBUG
# 	define ASSERT(T) if (!(T)) { std::cerr << "ASSERT FAILED " #T << std::endl; exit(1); }
# else
# 	define ASSERT(T)
# endif


# define CLEAR_STDOUT std::cout << "\033[2J";
# define WAIT_INPUT std::cin.get();
# define START_INFO std::cout << "To start the tests or go to the next one, press ENTER\n";
# define NEXT_TEST std::cin.get(); std::cout << "\033[2J"; std::cout << "To start the tests or go to the next one, press ENTER\n\n\n";
#endif
