/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:53:20 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/12 18:18:08 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

struct	Data {
	int toto;
	std::string karen;
	char c;
	void * nul;
};

uintptr_t
serialize(
	Data * ptr )
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *
deserialize(
	uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int
main(
	void )
{
	Data myData;
	myData.toto = 42;
	myData.karen = "Karen";
	myData.c = 'c';
	myData.nul = NULL;
	uintptr_t whereMyData;

	std::cout << "Data address: " << &myData << "\n";
	std::cout << myData.toto << " | "
		<< myData.karen << " | "
		<< myData.c << " | "
		<< myData.nul << '\n';
	whereMyData = serialize(&myData);
	std::cout << "Data address: " << whereMyData << '\n';
	Data * dataComeBack = deserialize(whereMyData);
	std::cout << "DataComeBack address: " << dataComeBack << "\n";
	std::cout << dataComeBack->toto << " | "
		<< dataComeBack->karen << " | "
		<< dataComeBack->c << " | "
		<< dataComeBack->nul << '\n';
	return 0;
}
