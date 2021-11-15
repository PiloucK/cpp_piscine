/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:01:37 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/15 15:18:00 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include <cstdlib>
# include "Span.hpp"
# include <algorithm>
# include <ctime>

# ifdef DEBUG
# 	define ASSERT(T) if (!(T)) { std::cerr << "\033[1;31mASSERT FAILED\033[0m " #T << std::endl; exit(1); } else { std::cerr << "\033[1;32mSUCCESS\033[0m " #T << '\n'; }
# else
# 	define ASSERT(T)
# endif

# define CLEAR_STDOUT std::cout << "\033[2J";
# define WAIT_INPUT std::cin.get();
# define START_INFO std::cout << "To start the tests or go to the next one, press ENTER\n";
# define NEXT_TEST std::cin.get(); std::cout << "\033[2J"; std::cout << "To start the tests or go to the next one, press ENTER\n\n\n";

# define MAX_VAL 750

#endif
