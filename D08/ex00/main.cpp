/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:09:32 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/13 17:03:10 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int
myRandom(
    void )
{
    return (std::rand() % 1000000);
}

int
myRandomLittle(
    void )
{
    return (std::rand() % 25);
}

void
intPrint(
    int i )
{
    std::cout << i << ' ';
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
        std::cout << "Vector with only default values find 0 then find 1\n\n";
    
        std::vector<int> vec(10);
    
        std::for_each(vec.begin(), vec.end(), intPrint);

        std::cout << "\n0:\n";
        easyfind< std::vector<int> >(vec, 0);
        std::cout << "1:\n";
        easyfind< std::vector<int> >(vec, 1);
    }
    
    NEXT_TEST
    {
        std::cout << "Vector with 100 random values find random one in the set\n\n";
    
        std::vector<int> vec(100);
    
        std::cout << "Default:\n";
        std::for_each(vec.begin(), vec.end(), intPrint);
        std::cout << "\n\n";

        std::cout << "Randomly filled\n";
        std::generate(vec.begin(), vec.end(), myRandom);
        std::for_each(vec.begin(), vec.end(), intPrint);
        std::cout << "\n\n";

        int i = std::rand() % 100;
        std::cout << "Find the number at index = " << i << "\n";
        easyfind< std::vector<int> >(vec, *(vec.begin() + i));

        i = std::rand() % 1000000;
        std::cout << "\nFind a random number maybe not in the set\n";
        std::cout << "Number -  " << i << "\n";
        easyfind< std::vector<int> >(vec, i);

        i = std::rand() % 1000000;
        std::cout << "\nFind a random number maybe not in the set\n";
        std::cout << "Number -  " << i << "\n";
        easyfind< std::vector<int> >(vec, i);

        i = std::rand() % 1000000;
        std::cout << "\nFind a random number maybe not in the set\n";
        std::cout << "Number -  " << i << "\n";
        easyfind< std::vector<int> >(vec, i);

    }
     
    NEXT_TEST
    {
        std::cout << "Vector with 20 random values find random one in the set but values are smaller\n\n";
    
        std::vector<int> vec(20);
    
        std::cout << "Default:\n";
        std::for_each(vec.begin(), vec.end(), intPrint);
        std::cout << "\n\n";

        std::cout << "Randomly filled\n";
        std::generate(vec.begin(), vec.end(), myRandomLittle);
        std::for_each(vec.begin(), vec.end(), intPrint);
        std::cout << "\n\n";

        int i = std::rand() % 20;
        std::cout << "Find the number at index = " << i << "\n";
        easyfind< std::vector<int> >(vec, *(vec.begin() + i));

        i = std::rand() % 20;
        std::cout << "Find the number at index = " << i << "\n";
        easyfind< std::vector<int> >(vec, *(vec.begin() + i));

        i = std::rand() % 20;
        std::cout << "Find the number at index = " << i << "\n";
        easyfind< std::vector<int> >(vec, *(vec.begin() + i));

        std::cout << "---------------\n";
    
        i = std::rand() % 25;
        std::cout << "\nFind a random number maybe not in the set\n";
        std::cout << "Number -  " << i << "\n";
        easyfind< std::vector<int> >(vec, i);

        i = std::rand() % 25;
        std::cout << "\nFind a random number maybe not in the set\n";
        std::cout << "Number -  " << i << "\n";
        easyfind< std::vector<int> >(vec, i);

        i = std::rand() % 25;
        std::cout << "\nFind a random number maybe not in the set\n";
        std::cout << "Number -  " << i << "\n";
        easyfind< std::vector<int> >(vec, i);

        i = std::rand() % 25;
        std::cout << "\nFind a random number maybe not in the set\n";
        std::cout << "Number -  " << i << "\n";
        easyfind< std::vector<int> >(vec, i);

        i = std::rand() % 25;
        std::cout << "\nFind a random number maybe not in the set\n";
        std::cout << "Number -  " << i << "\n";
        easyfind< std::vector<int> >(vec, i);

        i = std::rand() % 25;
        std::cout << "\nFind a random number maybe not in the set\n";
        std::cout << "Number -  " << i << "\n";
        easyfind< std::vector<int> >(vec, i);

        i = std::rand() % 25;
        std::cout << "\nFind a random number maybe not in the set\n";
        std::cout << "Number -  " << i << "\n";
        easyfind< std::vector<int> >(vec, i);

        i = std::rand() % 25;
        std::cout << "\nFind a random number maybe not in the set\n";
        std::cout << "Number -  " << i << "\n";
        easyfind< std::vector<int> >(vec, i);

        i = std::rand() % 25;
        std::cout << "\nFind a random number maybe not in the set\n";
        std::cout << "Number -  " << i << "\n";
        easyfind< std::vector<int> >(vec, i);

        i = std::rand() % 25;
        std::cout << "\nFind a random number maybe not in the set\n";
        std::cout << "Number -  " << i << "\n";
        easyfind< std::vector<int> >(vec, i);

        i = std::rand() % 25;
        std::cout << "\nFind a random number maybe not in the set\n";
        std::cout << "Number -  " << i << "\n";
        easyfind< std::vector<int> >(vec, i);

    }
    
    return 0;
}