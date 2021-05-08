/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:34:39 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/04 15:59:45 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <string>

class Pony {

private:
    const std::string   m_sFartSound;
    const std::string   m_sName;

public:
    Pony( std::string where, std::string name );
    virtual ~Pony();

    void    CanYouFart() const;

};

#endif
