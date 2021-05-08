/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:53:46 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/04 15:46:36 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>

void
ponyOnTheStack(
    void )
{
    Pony    my_beautiful_stack_pony("on the stack", "Pepouni");

    my_beautiful_stack_pony.CanYouFart();
}

void
ponyOnTheHeap(
    void )
{
    Pony    *my_beautiful_heap_pony = new Pony("on the heap", "Coyot");

    my_beautiful_heap_pony->CanYouFart();

    delete  my_beautiful_heap_pony;
}

int
main(
    void )
{
    ponyOnTheStack();

    // my_beautiful_stack_pony.CanYouFart();
    
    ponyOnTheHeap();

    // my_beautiful_heap_pony->CanYouFart();

    return 0;
}