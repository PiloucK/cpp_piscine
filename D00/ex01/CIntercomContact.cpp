/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CIntercomContact.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 22:38:46 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/02 19:50:00 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CIntercomContact.hpp"
#include <iostream>
#include <iomanip>

int     CIntercomContact::ContactCount = 0;

CIntercomContact::CIntercomContact(
    void )
{
    return ;
}

CIntercomContact::~CIntercomContact(
    void )
{
    return ;
}

void
CIntercomContact::FillInformations(
    void )
{
    std::cout << std::endl;

    std::cout << "Please enter this contact's first name: " << std::endl;
    std::getline(std::cin, this->first_name);

    std::cout << "Please enter this contact's last name: " << std::endl;
    std::getline(std::cin, this->last_name);

    std::cout << "Please enter this contact's nickname: " << std::endl;
    std::getline(std::cin, this->nickname);

    std::cout << "Please enter this contact's login: " << std::endl;
    std::getline(std::cin, this->login);

    std::cout << "Please enter this contact's postal address: " << std::endl;
    std::getline(std::cin, this->postal_address);

    std::cout << "Please enter this contact's email address: " << std::endl;
    std::getline(std::cin, this->email_address);

    std::cout << "Please enter this contact's phone number: " << std::endl;
    std::getline(std::cin, this->phone_number);

    std::cout << "Please enter this contact's birthday date: " << std::endl;
    std::getline(std::cin, this->birthday_date);

    std::cout << "Please enter this contact's favorite meal: " << std::endl;
    std::getline(std::cin, this->favorite_meal);

    std::cout << "Please enter this contact's underwear color: " << std::endl;
    std::getline(std::cin, this->underwear_color);
    std::cout << "(disgusting)" << std::endl;

    std::cout << "Please enter this contact's darkest secret: " << std::endl;
    std::getline(std::cin, this->darkest_secret);
    
    std::cout << std::endl << "Guuud Jooob !!" << std::endl << std::endl;
    
    if (CIntercomContact::ContactCount < 8) {
        CIntercomContact::ContactCount += 1;
    }
}

void
CIntercomContact::PrintPreview(
    void ) const
{
    if (this->first_name.length() >= 10) {
        std::cout << this->first_name.substr(0, 9) << "." << "|";
    }
    else {
        std::cout.width(10); std::cout << this->first_name << "|";
    }

    if (this->last_name.length() >= 10) {
        std::cout << this->last_name.substr(0, 9) << "." << "|";
    }
    else {
        std::cout.width(10); std::cout << this->last_name << "|";
    }

    if (this->nickname.length() >= 10) {
        std::cout << this->nickname.substr(0, 9) << ".";
    }
    else {
        std::cout.width(10); std::cout << this->nickname;
    }
}

void
CIntercomContact::PrintComplete(
    void ) const
{
    std::cout << "First name : " << this->first_name << std::endl;
    std::cout << "Last name : " << this->last_name << std::endl;
    std::cout << "Nickname : " << this->nickname << std::endl;
    std::cout << "Loign : " << this->login << std::endl;
    std::cout << "Postal address : " << this->postal_address << std::endl;
    std::cout << "Email address : " << this->email_address << std::endl;
    std::cout << "Phone number : " <<  this->phone_number << std::endl;
    std::cout << "Birthday date : " << this->birthday_date << std::endl;
    std::cout << "Favorite meal : " << this->favorite_meal << std::endl;
    std::cout << "Underwear color : " << this->underwear_color << std::endl;
    std::cout << "Darkest secret : " << this->darkest_secret << std::endl;
}

int
CIntercomContact::GetContactCount(
    void )
{
    return CIntercomContact::ContactCount;
}
