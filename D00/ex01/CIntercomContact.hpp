/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CIntercomContact.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 22:28:38 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/02 19:50:06 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CINTERCOM_CONTACT_CLASS_HPP
# define CINTERCOM_CONTACT_CLASS_HPP

# include <string>

class CIntercomContact {

private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string login;
    std::string postal_address;
    std::string email_address;
    std::string phone_number;
    std::string birthday_date;
    std::string favorite_meal;
    std::string underwear_color;
    std::string darkest_secret;

    static int  ContactCount;

public:
    CIntercomContact( void );
    virtual ~CIntercomContact( void );

    void    FillInformations( void );
    void    PrintPreview( void ) const;
    void    PrintComplete( void ) const;

    static int  GetContactCount( void );

};

#endif
