/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:53:52 by aelaaser          #+#    #+#             */
/*   Updated: 2025/09/27 16:55:32 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
    try {
        // Create a Span object with a maximum size of 5
        Span sp(5);
        
        // Add some numbers to the span
        sp.addNumber(10);
        sp.addNumber(20);
        sp.addNumber(30);
        sp.addNumber(40);
        sp.addNumber(50);
        
        // Test for adding another number (will throw an exception)
        try {
            sp.addNumber(60);
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;  // Should print "Cannot add more numbers, the span is full."
        }
        
        // Test the shortest span
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // Should print 10 (difference between 10 and 20)
        
        // Test the longest span
        std::cout << "Longest span: " << sp.longSpan() << std::endl;  // Should print 40 (difference between 10 and 50)
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        // Create a Span with 1 element (should throw an exception for shortest/longest span)
        Span sp2(1);
        sp2.addNumber(100);
        
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;  // Should print error for insufficient numbers
    }

    return 0;
}
