/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:50:35 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/15 15:01:18 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <algorithm>
# include <functional>

class Span {
    
    public:
        Span( unsigned int maxSize );
        Span( const Span & model );

        ~Span( void );

        Span & operator = ( const Span & model );

        void addNumber( const int newNumber );
        void addNumber( std::vector<int>::iterator start, const std::vector<int>::iterator end );

        int shortestSpan( void );
        int longestSpan( void );

    protected:

    private:
        Span( void );

        std::vector<int> m_vector;
        unsigned int m_maxSize;

};

#endif
