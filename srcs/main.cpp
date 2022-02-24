/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:16:12 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/24 12:58:56 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <stack>

int main()
{
    TestSuite containers("ft_containers");

    containers.addTest(testUnitIterator());
    containers.addTest(testUnitTypeTraits());
    containers.addTest(testUnitVector());
    containers.addTest(testUnitStack());

    return containers.run();
}
