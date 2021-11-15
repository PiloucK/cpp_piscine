/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:09:32 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/15 15:21:56 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int
randomNumber(
	void )
{
	return (std::rand());
}

int
main(
    void )
{
    CLEAR_STDOUT
    START_INFO
    WAIT_INPUT

    std::srand(unsigned (std::time(0)));

    {
        Span sp = Span(5);
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << '\n';
        std::cout << sp.longestSpan() << '\n';
    }

    NEXT_TEST
    {
        std::cout << "Test 2: span capacity of 0, try every thing\n";
        Span sp = Span(0);
        
        try {
            sp.addNumber(5);
        } catch (std::exception & e) {
            std::cerr << e.what() << '\n';
        }

        try {
            sp.shortestSpan();
        } catch (std::exception & e) {
            std::cerr << e.what() << '\n';
        }

        try {
            sp.longestSpan();
        } catch (std::exception & e) {
            std::cerr << e.what() << '\n';
        }
    }

    NEXT_TEST
    {
        std::cout << "Test 3: Randomly filled span of 10 000\n";
        Span sp = Span(10000);
        std::vector<int> toto(10000);

        std::generate (toto.begin(), toto.end(), randomNumber);
        
        try {
            sp.addNumber(toto.begin(), toto.end());
        } catch (std::exception & e) {
            std::cerr << e.what() << '\n';
        }

        std::cout << sp.shortestSpan() << '\n';
        std::cout << sp.longestSpan() << '\n';
    }

    NEXT_TEST
    {
        std::cout << "Test 3: What happens with 1 000 000\n";
        Span sp = Span(1000000);
        std::vector<int> toto(1000000);

        std::generate (toto.begin(), toto.end(), randomNumber);
        
        try {
            sp.addNumber(toto.begin(), toto.end());
        } catch (std::exception & e) {
            std::cerr << e.what() << '\n';
        }

        std::cout << sp.shortestSpan() << '\n';
        std::cout << sp.longestSpan() << '\n';

        std::cout <<"Test 4: copy constructor and assignation\n";
        Span spp = Span(sp);

        std::cout << spp.shortestSpan() << '\n';
        std::cout << spp.longestSpan() << '\n';

        Span sppp = Span(0);
        sppp = spp;

        std::cout << sppp.shortestSpan() << '\n';
        std::cout << sppp.longestSpan() << '\n';
        
    }

    return 0;
}