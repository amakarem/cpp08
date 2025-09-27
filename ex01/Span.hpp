/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:26:53 by aelaaser          #+#    #+#             */
/*   Updated: 2025/09/27 17:19:14 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span
{
    private:
        unsigned int N;
        std::vector<int> numbers;
        
    public:
    	Span(void);
		Span(unsigned int _n);
		~Span();
		Span(Span const &cpy);
		Span &operator = (Span const &cpy);

        void addNumber(int num);
        unsigned int shortestSpan();
        unsigned int longSpan();

    class overflow_error : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class not_enough_elements_error : public std::exception
    {
    public:
        const char *what() const throw();
    };
};
