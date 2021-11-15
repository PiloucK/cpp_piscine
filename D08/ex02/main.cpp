/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:09:32 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/15 17:22:31 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main()
{
    MutantStack<int> mstack;
    std::vector<int> witness;

    mstack.push(5);
    mstack.push(17);
    witness.push_back(5);
    witness.push_back(17);

    std::cout << mstack.top() << '\n';
    std::cout << witness.back() << '\n';

    mstack.pop();
    witness.erase(witness.end() - 1);

    std::cout << mstack.size() << '\n';
    std::cout << witness.size() << '\n';
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    
    witness.push_back(3);
    witness.push_back(5);
    witness.push_back(737);
    //[...]
    witness.push_back(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::vector<int>::iterator w_it = witness.begin();
    
    ++it;
    --it;
    ++w_it;
    --w_it;
    while (it != ite)
    {
        std::cout << *it << " | " << *w_it << '\n';
        ++it;
        ++w_it;
    }
    std::stack<int> s(mstack);
    return 0;
}
