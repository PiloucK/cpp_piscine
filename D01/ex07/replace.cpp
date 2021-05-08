/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:01:58 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/07 13:12:14 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

std::string
actualReplace(
    std::string oString
    , const std::string & strToFind
    , const std::string & strToInsert)
{
    std::string::size_type found;
    std::string::size_type lenStrToFind(strToFind.length());
    std::string::size_type lenStrToInsert(strToInsert.length());

    found = oString.find(strToFind);
    while (found != std::string::npos) {
        oString.erase(found, lenStrToFind);
        oString.insert(found, strToInsert);

        found = oString.find(strToFind, found + lenStrToInsert);
    }

    return (oString);
}

int
main(
    int argc
    , char **argv )
{

    if (argc < 4 || !argv[1][0] || !argv[2][0] || !argv[3][0]) {
        return 0;
    }

    std::fstream    iFileStream;
    iFileStream.open(argv[1], std::fstream::in);

    if (iFileStream.fail() != true && iFileStream.is_open()) {

        std::fstream    oFileStream;
        std::string     oFileName(argv[1]);

        oFileName += (std::string)".replace";
        oFileStream.open(oFileName.c_str(), std::fstream::out);

        if (oFileStream.fail() != true && oFileStream.is_open()) {

            std::stringstream     oStringStream;
            oStringStream << iFileStream.rdbuf();

            if (oStringStream.fail() != true) {
                oFileStream << actualReplace(oStringStream.str(), argv[2], argv[3]);
            } else {
                std::cerr << "Error: rdbuf failed at some point\n";
            }

        } else {
            std::cerr << "Error: output file did not open" << '\n';
        }

        oFileStream.close();

    } else {
        std::cerr << "Error: input file did not open" << '\n';
    }

    iFileStream.close();

    return 0;
}
