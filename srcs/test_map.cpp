/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:46:59 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/06 10:48:21 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

#ifdef STD

# include <map>
namespace ft = std;

#else

# include "stack.hpp"

#endif

TestSuite *testUnitMap()
{
    TestSuite *map = new TestSuite("map");

    return map;
}