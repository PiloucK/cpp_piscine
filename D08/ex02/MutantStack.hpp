/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:13:53 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/15 15:37:59 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template< class T >
class MutantStack : public std::stack<T> {
    
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;

        MutantStack( void ) : std::stack<T>() {};
        MutantStack( const MutantStack & model ) : std::stack<T>(model) {};

        virtual ~MutantStack( void ) {};

        MutantStack & operator = ( const MutantStack & model ) { std::stack<T>::c.operator=(model); return *this; };

        iterator begin() { return (std::stack<T>::c.begin()); };
        iterator end() { return (std::stack<T>::c.end()); };

    protected:

    private:

};

#endif
