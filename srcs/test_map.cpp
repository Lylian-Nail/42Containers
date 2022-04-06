/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:46:59 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/06 11:57:55 by lperson-         ###   ########.fr       */
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

static int testMapValueComp()
{
    ft::map<int, std::string> stringMap;
    ft::map<int, std::string>::value_compare comp = stringMap.value_comp();

    ft::pair<int, std::string> lhs = ft::make_pair(1, "Hello");
    ft::pair<int, std::string> rhs = ft::make_pair(2, "World");

    ASSERT(comp(lhs, rhs));
    ASSERT(!comp(rhs, lhs));
    return 0;
}

TestSuite *testUnitMap()
{
    TestSuite *map = new TestSuite("map");

    map->addTest(
        new TestCase("test map default constructor", testMapDefaultConstructor)
    );
    map->addTest(
        new TestCase("test map value comp", testMapValueComp)
    );

    return map;
}