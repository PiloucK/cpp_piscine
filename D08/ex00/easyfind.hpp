/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <cluznie@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:50:35 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/11 23:07:18 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template< typename T >
bool
easyfind(
    T & container
    , int toFind)
{
    std::iterator i = std::find(container.begin(), container.end(), toFind);
    
    if (i == container.end()) {
        return (false);
    }
    return (true);
}


#endif
