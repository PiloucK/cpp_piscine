/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:33:57 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/15 15:15:30 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(
    unsigned int maxSize )
        : m_vector()
        , m_maxSize(maxSize)
{
}

Span::Span(
    const Span & model )
        : m_vector(model.m_vector)
        , m_maxSize(model.m_maxSize)
{
}

Span::~Span(
    void )
{
}

Span &
Span::operator = (
    const Span & model )
{
    m_vector = model.m_vector;
    m_maxSize = model.m_maxSize;

    return (*this);
}

void
Span::addNumber(
    const int newNumber )
{
    if (m_vector.size() < m_maxSize) {
        m_vector.push_back(newNumber);
    } else {
        throw std::length_error("Max capacity");
    }
}

void
Span::addNumber(
    std::vector<int>::iterator start
    , const std::vector<int>::iterator end )
{
    if (m_vector.size() + (end - start) <= m_maxSize) {
        
        while (start != end) {
            m_vector.push_back(*start);
            start++;
        }
    } else {
        throw std::length_error("Not enough space left");
    }
}

int
Span::shortestSpan(
    void )
{
    if (m_vector.size() < 2) {
        throw std::logic_error("No span without multiple values");
    }

    std::sort(m_vector.begin(), m_vector.end());
    std::vector<int> spans(m_vector);
    std::rotate(spans.begin(), spans.begin() + 1, spans.end());
    std::transform(spans.begin(), spans.end(), m_vector.begin(), spans.begin(), std::minus<int>());
    return (*std::min_element(spans.begin(), spans.end() - 1));
}

int
Span::longestSpan(
    void )
{
    if (m_vector.size() < 2) {
        throw std::logic_error("No span without multiple values");
    }

    std::sort(m_vector.begin(), m_vector.end());
    return(m_vector.back() - m_vector.front());
}
