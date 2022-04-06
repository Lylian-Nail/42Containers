/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:46:59 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/06 16:41:14 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <string>
#include <cstdlib>
# include <algorithm>

#ifdef STD

# include <map>
# include <vector>
namespace ft = std;

#else

# include "vector.hpp"
# include "map.hpp"

#endif

static int testMapDefaultConstructor()
{
    ft::map<std::string, int> intMap;
    (void)intMap;
    return 0;
}

static int testMapRangeConstructor()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);
        ft::vector<ft::pair<int, std::string> > paired;
        for (std::size_t i(0); i < arraySize; ++i)
        {
            paired.push_back(
                ft::make_pair<int, std::string>(values[i], "World")
            );
        }

        ft::map<int, std::string> stringMap(paired.begin(), paired.end());
        std::sort(values, values + arraySize);

        ASSERT(stringMap.size() == paired.size());
        ft::map<int, std::string>::iterator first = stringMap.begin();
        ft::map<int, std::string>::const_iterator last = stringMap.end();
        for (int i = 0; first != last; ++i, ++first)
        {
            ASSERT(first->first == values[i]);
            ASSERT(first->second.compare("World") == 0);
        }
    }
    return 0;
}

static int testMapReverseIterator()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);
        ft::vector<ft::pair<int, std::string> > paired;
        for (std::size_t i(0); i < arraySize; ++i)
        {
            paired.push_back(
                ft::make_pair<int, std::string>(values[i], "World")
            );
        }

        ft::map<int, std::string> stringMap(paired.begin(), paired.end());
        std::sort(values, values + arraySize);

        ASSERT(stringMap.size() == paired.size());
        ft::map<int, std::string>::reverse_iterator first = stringMap.rbegin();
        ft::map<int, std::string>::const_reverse_iterator last;
        last = stringMap.rend();
        for (std::size_t i = arraySize -1; first != last; ++first, --i)
        {
            ASSERT(first->first == values[i]);
            ASSERT(first->second.compare("World") == 0);
        }
    }
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
        new TestCase("test map range constructor", testMapRangeConstructor)
    );
    map->addTest(
        new TestCase("test map reverse iterator", testMapReverseIterator)
    );
    map->addTest(
        new TestCase("test map value comp", testMapValueComp)
    );

    return map;
}