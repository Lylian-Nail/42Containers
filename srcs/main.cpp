/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:16:12 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/11 21:32:07 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "debug.hpp"

int main()
{
    TestSuite containers("ft_containers");

    containers.addTest(testUnitIterator());
    containers.addTest(testUnitTypeTraits());
    containers.addTest(testUnitVector());
    containers.addTest(testUnitStack());
    containers.addTest(testUnitUtility());
    containers.addTest(testUnitBinarySearchTree());
    containers.addTest(testUnitMap());

    int r = containers.run();

    ft::debug_all();
    return r;
}
