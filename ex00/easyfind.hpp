/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:42:29 by aelaaser          #+#    #+#             */
/*   Updated: 2025/09/27 15:09:13 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <iterator>
#include <algorithm>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Number not found");
		}
	
};

template<typename T>
typename T::iterator easyfind(T& x, int i)
{
    typename T::iterator it;

    it = std::find(x.begin(), x.end(), i);
    if (it != x.end())
        return it;
    else
        throw NotFoundException();
}

#endif
