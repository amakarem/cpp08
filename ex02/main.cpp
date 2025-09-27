/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:53:52 by aelaaser          #+#    #+#             */
/*   Updated: 2025/09/27 17:41:48 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}

// int main() {
//     MutantStack<int> mstack;

//     std::cout << "---- Push elements ----" << std::endl;
//     mstack.push(5);
//     mstack.push(17);
//     mstack.push(3);
//     mstack.push(42);

//     std::cout << "Top element: " << mstack.top() << std::endl; // 42
//     std::cout << "Size: " << mstack.size() << std::endl;       // 4

//     std::cout << "---- Pop element ----" << std::endl;
//     mstack.pop();
//     std::cout << "Top element after pop: " << mstack.top() << std::endl; // 3
//     std::cout << "Size after pop: " << mstack.size() << std::endl;       // 3

//     std::cout << "---- Iterate with iterator ----" << std::endl;
//     for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     std::cout << "---- Iterate with const_iterator ----" << std::endl;
//     const MutantStack<int> const_mstack = mstack;
//     for (MutantStack<int>::const_iterator it = const_mstack.begin(); it != const_mstack.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     std::cout << "---- Iterate with reverse_iterator ----" << std::endl;
//     for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
//         std::cout << *rit << " ";
//     }
//     std::cout << std::endl;

//     std::cout << "---- Iterate with const_reverse_iterator ----" << std::endl;
//     for (MutantStack<int>::const_reverse_iterator rit = const_mstack.rbegin(); rit != const_mstack.rend(); ++rit) {
//         std::cout << *rit << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }

// Expected Output
// ---- Push elements ----
// Top element: 42
// Size: 4
// ---- Pop element ----
// Top element after pop: 3
// Size after pop: 3
// ---- Iterate with iterator ----
// 5 17 3 
// ---- Iterate with const_iterator ----
// 5 17 3 
// ---- Iterate with reverse_iterator ----
// 3 17 5 
// ---- Iterate with const_reverse_iterator ----
// 3 17 5 
