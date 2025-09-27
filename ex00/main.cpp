/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:42:23 by aelaaser          #+#    #+#             */
/*   Updated: 2025/09/27 15:12:08 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

void test_vector_found() {
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> v(arr, arr + 5);
    try {
        std::vector<int>::iterator it = easyfind(v, 3);
        std::cout << "[Vector Found] Found: " << *it << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << "[Vector Found] " << e.what() << std::endl;
    }
}

void test_vector_not_found() {
    int arr[] = {10, 20, 30};
    std::vector<int> v(arr, arr + 3);
    try {
        std::vector<int>::iterator it = easyfind(v, 5);
        std::cout << "[Vector Not Found] Found: " << *it << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << "[Vector Not Found] " << e.what() << std::endl;
    }
}

void test_list_found() {
    int arr[] = {100, 200, 300};
    std::list<int> l(arr, arr + 3);
    try {
        std::list<int>::iterator it = easyfind(l, 200);
        std::cout << "[List Found] Found: " << *it << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << "[List Found] " << e.what() << std::endl;
    }
}

void test_list_not_found() {
    int arr[] = {7, 8, 9};
    std::list<int> l(arr, arr + 3);
    try {
        std::list<int>::iterator it = easyfind(l, 6);
        std::cout << "[List Not Found] Found: " << *it << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << "[List Not Found] " << e.what() << std::endl;
    }
}

void test_deque_found() {
    int arr[] = {0, 1, 2, 3};
    std::deque<int> d(arr, arr + 4);
    try {
        std::deque<int>::iterator it = easyfind(d, 0);
        std::cout << "[Deque Found] Found: " << *it << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << "[Deque Found] " << e.what() << std::endl;
    }
}

void test_deque_not_found() {
    int arr[] = {11, 12, 13};
    std::deque<int> d(arr, arr + 3);
    try {
        std::deque<int>::iterator it = easyfind(d, 14);
        std::cout << "[Deque Not Found] Found: " << *it << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << "[Deque Not Found] " << e.what() << std::endl;
    }
}

void test_single_element_found() {
    int arr[] = {42};
    std::vector<int> v(arr, arr + 1);
    try {
        std::vector<int>::iterator it = easyfind(v, 42);
        std::cout << "[Single Element Found] Found: " << *it << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << "[Single Element Found] " << e.what() << std::endl;
    }
}

void test_single_element_not_found() {
    int arr[] = {99};
    std::vector<int> v(arr, arr + 1);
    try {
        std::vector<int>::iterator it = easyfind(v, 100);
        std::cout << "[Single Element Not Found] Found: " << *it << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << "[Single Element Not Found] " << e.what() << std::endl;
    }
}

void test_empty_container() {
    std::vector<int> v;
    try {
        std::vector<int>::iterator it = easyfind(v, 1);
        std::cout << "[Empty Container] Found: " << *it << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << "[Empty Container] " << e.what() << std::endl;
    }
}

void test_multiple_occurrences() {
    int arr[] = {1, 2, 3, 2, 4, 2};
    std::vector<int> v(arr, arr + 6);
    try {
        std::vector<int>::iterator it = easyfind(v, 2);
        std::cout << "[Multiple Occurrences] Found first: " << *it << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << "[Multiple Occurrences] " << e.what() << std::endl;
    }
}

int main() {
    test_vector_found();
    test_vector_not_found();
    test_list_found();
    test_list_not_found();
    test_deque_found();
    test_deque_not_found();
    test_single_element_found();
    test_single_element_not_found();
    test_empty_container();
    test_multiple_occurrences();
    return 0;
}
