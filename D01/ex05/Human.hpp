/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:06:17 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/04 20:48:49 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"
# include <string>

class Human {

private:
    const Brain brain;

public:
    Human( void );
    virtual ~Human( void );

    std::string identify( void ) const;
    const Brain& getBrain( void ) const;

};

#endif
