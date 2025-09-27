/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:27:10 by aelaaser          #+#    #+#             */
/*   Updated: 2025/09/27 17:17:14 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : N(0) {}

Span::Span(unsigned int _n) : N(_n) {}

Span::~Span()
{
}

Span::Span(Span const &cpy)
{
    this->N = cpy.N;
    this->numbers = cpy.numbers;
}

Span &Span::operator=(Span const &cpy)
{
    if (this == &cpy)
        return (*this);
    this->N = cpy.N;
    this->numbers = cpy.numbers;
    return (*this);
}

// Method to add a number to the span
void Span::addNumber(int num)
{
    if (numbers.size() >= N)
    {
        throw overflow_error();
    }
    numbers.push_back(num);
}

// Method to find the shortest span
unsigned int Span::shortestSpan()
{
    if (numbers.size() < 2)
    {
        throw not_enough_elements_error();
    }

    // Sort the numbers to easily find the shortest span
    std::sort(numbers.begin(), numbers.end());

    unsigned int minSpan = static_cast<unsigned int>(-1); // Start with a large number (max unsigned int)

    // Calculate the difference between consecutive numbers
    for (size_t i = 1; i < numbers.size(); ++i)
    {
        unsigned int span = static_cast<unsigned int>(numbers[i] - numbers[i - 1]);
        if (span < minSpan)
        {
            minSpan = span;
        }
    }

    return minSpan;
}

// Method to find the longest span
unsigned int Span::longSpan()
{
    if (numbers.size() < 2)
    {
        throw not_enough_elements_error();
    }

    // Get the min and max elements
    int minElem = *std::min_element(numbers.begin(), numbers.end());
    int maxElem = *std::max_element(numbers.begin(), numbers.end());

    return static_cast<unsigned int>(maxElem - minElem);
}

const char *Span::overflow_error::what() const throw()
{
    return "Cannot add more numbers, the span is full.";
}

const char *Span::not_enough_elements_error::what() const throw()
{
    return "At least two numbers are required to calculate a span.";
}
