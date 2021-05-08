/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:55:16 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/04 21:18:09 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {

private:
    std::string   m_sType;
    std::string   m_sName;
    static const std::string sNameArray[10];
    static const std::string sTypeArray[10];

public:
    Zombie( void );
    Zombie( std::string type, std::string name );
    virtual ~Zombie();

    void    announce() const;
    static const std::string getAName( int index );
    static const std::string getAType( int index );
    void setName( std::string name );
    void setType( std::string type );

};

#endif
