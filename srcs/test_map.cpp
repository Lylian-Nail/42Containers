/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:46:59 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/06 11:26:02 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <string>

#ifdef STD

# include <map>
namespace ft = std;

#else

# include "map.hpp"

#endif

static int testMapDefaultConstructor()
{
    ft::map<std::string, int> intMap;
    (void)intMap;
    return 0;
}

TestSuite *testUnitMap()
{
    TestSuite *map = new TestSuite("map");

    map->addTest(
        new TestCase("test map default constructor", testMapDefaultConstructor)
    );

    return map;
}