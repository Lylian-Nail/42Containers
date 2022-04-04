/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:16:12 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/04 18:31:26 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <set>

int main()
{
    TestSuite containers("ft_containers");

    containers.addTest(testUnitIterator());
    containers.addTest(testUnitTypeTraits());
    containers.addTest(testUnitVector());
    containers.addTest(testUnitStack());
    containers.addTest(testUnitUtility());
    containers.addTest(testUnitBinaryTree());

    std::set<int> set;
    set.insert(42);
    set.lower_bound(42);

    return containers.run();
}
