/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <cluznie@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:12:14 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/11 22:15:56 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <stdexcept>

template< typename T >
class Array {

    public:
        Array( void ) : m_content(new T[0]), m_size(0) {};

        Array( unsigned int size ) : m_content(new T[size]), m_size(size)
        {
            for (unsigned int i = 0; i < m_size; i++){
                m_content[i] = 0;
            }
        };

        Array( const Array & model ) : m_content(new T[model.m_size]), m_size(model.m_size)
        {
            for (unsigned int i = 0; i < m_size; i++){
                m_content[i] = model.m_content[i];
            }
        };

        ~Array( void ) { delete [] m_content; };

        Array & operator = ( const Array & model )
        {
            delete [] m_content;
            m_content = new T(model.m_size);
            m_size = model.m_size;

            for (unsigned int i = 0; i < m_size; i++){
                m_content[i] = model.m_content[i];
            }
        };

        T & operator [] ( const int i )
        {
            if (i < 0 || static_cast<unsigned int>(i) >= m_size) {
                throw std::out_of_range("Out of Array");
            } else {
                return m_content[i];
            }
        };

        T & operator [] ( const unsigned int i )
        {
            if (i >= m_size) {
                throw std::out_of_range("Out of Array");
            } else {
                return m_content[i];
            }
        };

        unsigned int size( void ) const { return m_size; };

    protected:

    private:
        T * m_content;
        unsigned int m_size;

};

#endif
