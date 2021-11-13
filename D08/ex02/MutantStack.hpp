/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:13:53 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/13 17:56:20 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template< class T >
class MutantStack : public std::stack<T> {
    
    public:
        MutantStack( void ) {};
        MutantStack( const MutantStack & model ) : std::stack<T>(model) {};

        ~MutantStack( void );

        MutantStack & operator = ( const MutantStack & model ) { std::stack<T>operator = (model); };

        std::stack<T>::container_type::iterator begin() { c.begin() };
        std::stack<T>::container_type::iterator end() { c.end() };

    protected:

    private:
        MutantStack( void );

        std::vector<int> m_vector;
        unsigned int m_maxSize;

};

#endif
