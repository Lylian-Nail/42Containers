/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:46:59 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/12 14:08:34 by lperson-         ###   ########.fr       */
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

/*
 * Values tested
*/

template <class T>
struct Foo
{
};

static ft::map<int, std::string> getStringMap(
    int values[], std::string const &second, std::size_t arraySize
)
{
    ft::vector<ft::pair<int, std::string> > paired;
    for (std::size_t i = 0; i < arraySize; ++i)
    {
        paired.push_back(
            ft::make_pair(values[i], second)
        );
    }
    return ft::map<int, std::string>(paired.begin(), paired.end());
}

/*
 * Tests
*/

static int testMapDefaultConstructor()
{
    {
        ft::map<std::string, int> intMap;
        ASSERT(intMap.begin() == intMap.end());
        ASSERT(intMap.size() == 0);
    }
    {
        ft::map<std::string, Foo<int> > specialMap;
        ft::map<std::string, Foo<int> >::iterator it;
        it = specialMap.begin();
        ASSERT(specialMap.size() == 0)
        ASSERT(it == specialMap.end());
    }
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
        ASSERT(stringMap.size() == arraySize);
    }
    return 0;
}

static int testMapCopyConstructor()
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
        ft::map<int, std::string> copyMap(stringMap);
        ft::map<int, std::string>::const_iterator firstCopy = copyMap.begin();
        ft::map<int, std::string>::const_iterator first = stringMap.begin();
        ft::map<int, std::string>::const_iterator last = stringMap.end();
        for (; first != last; ++first, ++firstCopy)
        {
            ASSERT(first->first == firstCopy->first);
            ASSERT(first->second.compare(firstCopy->second) == 0);
        }
        ASSERT(firstCopy == copyMap.end());
        ASSERT(copyMap.get_allocator() == stringMap.get_allocator());
        ASSERT(copyMap.size() == copyMap.size());
    }
    return 0;
}

static int testMapReverseIterator()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);
        ft::map<int, std::string> stringMap = getStringMap(
            values, "World", arraySize
        );
        ASSERT(stringMap.size() == arraySize);

        std::sort(values, values + arraySize);
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

static int testMapCount()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);
        ft::map<int, std::string> stringMap = getStringMap(
            values, "World", arraySize
        );

        ASSERT(stringMap.count(42) == 1);
        ASSERT(stringMap.count(11000) == 0);
        ASSERT(stringMap.count(101) == 1);
        ASSERT(stringMap.count(8) == 1);
    }
    return 0;
}

static int testMapInsertSingleElement()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);
        ft::map<int, std::string> mapString;

        for (std::size_t i = 0; i < arraySize; ++i)
        {
            mapString.insert(ft::make_pair(values[i], "World"));
        }
        ASSERT(mapString.size() == arraySize);

        std::sort(values, values + arraySize);
        ft::map<int, std::string>::const_iterator first;
        first = mapString.begin();
        for (std::size_t i = 0; i < arraySize; ++i, ++first)
        {
            ASSERT(values[i] == first->first);
            ASSERT(first->second.compare("World") == 0);
        }
        ASSERT(first == mapString.end());
    }
    return 0;
}

static int testMapInsertWithHint()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);
        ft::map<int, std::string> mapString;

        ft::map<int, std::string>::iterator first = mapString.begin();
        for (std::size_t i = 0; i < arraySize; ++i)
        {
            first = mapString.insert(
                first, ft::make_pair(values[i], "World")
            );
            ASSERT(first->first == values[i]);
        }
        ASSERT(mapString.size() == arraySize);

        std::sort(values, values + arraySize);
        first = mapString.begin();
        for (std::size_t i = 0; i < arraySize; ++i)
        {
            ASSERT(values[i] = first->first);
            ASSERT(first->second.compare("World") == 0);
        }

        first = mapString.begin();
        ft::map<int, std::string>::iterator r = mapString.insert(
            first, ft::make_pair(12, "World")
        );
        ASSERT(r->first == 12);
        ++first;
        r = mapString.insert(first, ft::make_pair(37, "World"));
        ASSERT(r->first == 37);

        first = mapString.begin();
        ft::map<int, std::string>::const_iterator last = mapString.end();
        for (; first != last; ++first)
        {
            ft::map<int, std::string>::iterator precedent = first;
            if (precedent != mapString.begin())
            {
                --precedent;
                ASSERT(precedent->first < first->first);
            }
        }
    }
    return 0;
}

static int testMapInsertRange()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);
        ft::map<int, std::string> mapString;
        ft::vector<ft::pair<int, std::string> > paired;
        for (std::size_t i = 0; i < arraySize; ++i)
        {
            paired.push_back(
                ft::make_pair(values[i], "World")
            );
        }
        ft::vector<ft::pair<int, std::string> >::iterator first;
        first = paired.begin();
        mapString.insert(first, paired.end());
        ASSERT(paired.size() == mapString.size());

        std::sort(first, paired.end());
        first = paired.begin();
        ft::map<int, std::string>::iterator firstCopy;
        firstCopy = mapString.begin();
        ft::map<int, std::string>::iterator lastCopy = mapString.end();
        for (; firstCopy != lastCopy; ++firstCopy, ++first)
        {
            ASSERT(firstCopy->first == first->first);
            ASSERT(firstCopy->second.compare(first->second) == 0);
        }
    }
    return 0;
}

static int testMapErasePosition()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);
        ft::map<int, std::string> stringMap = getStringMap(
            values, "World", arraySize
        );

        std::sort(values, values + arraySize);
        ft::map<int, std::string>::iterator first = stringMap.begin();
        ft::map<int, std::string>::iterator last = stringMap.end();
        for (int i = 0; first != last; ++i, ++first)
        {
            ASSERT(values[i] == first->first);
            ASSERT(first->second.compare("World") == 0);
        }
        ASSERT(stringMap.size() == arraySize);

        stringMap.erase(stringMap.find(42));
        first = stringMap.begin();
        last = stringMap.end();
        for (int i = 0; first != last; ++i)
        {
            if (values[i] != 42)
            {
                ASSERT(values[i] == first->first);
                ASSERT(first->second.compare("World") == 0);
                ++first;
            }
        }
        ASSERT(stringMap.size() == arraySize - 1);

        stringMap.erase(stringMap.find(101));
        first = stringMap.begin();
        last = stringMap.end();
        for (int i = 0; first != last; ++i)
        {
            if (values[i] != 42 && values[i] != 101)
            {
                ASSERT(values[i] == first->first);
                ASSERT(first->second.compare("World") == 0);
                ++first;
            }
        }
        ASSERT(stringMap.size() == arraySize - 2);

        stringMap.erase(stringMap.find(24));
        first = stringMap.begin();
        last = stringMap.end();
        for (int i = 0; first != last; ++i)
        {
            if (values[i] != 42 && values[i] != 101 && values[i] != 24)
            {
                ASSERT(values[i] == first->first);
                ASSERT(first->second.compare("World") == 0);
                ++first;
            }
        }
        ASSERT(stringMap.size() == arraySize - 3);

        stringMap.erase(stringMap.find(70));
        first = stringMap.begin();
        last = stringMap.end();
        for (int i = 0; first != last; ++i)
        {
            if (
                values[i] != 70 && values[i] != 42
                && values[i] != 24 && values[i] != 101
            )
            {
                ASSERT(values[i] == first->first);
                ASSERT(first->second.compare("World") == 0);
                ++first;
            }
        }
        ASSERT(stringMap.size() == arraySize - 4);
    }
    return 0;
}

static int testMapEraseKey()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);
        ft::map<int, std::string> stringMap = getStringMap(
            values, "World", arraySize
        );

        std::sort(values, values + arraySize);
        ft::map<int, std::string>::iterator first = stringMap.begin();
        ft::map<int, std::string>::iterator last = stringMap.end();
        for (int i = 0; first != last; ++i, ++first)
        {
            ASSERT(values[i] == first->first);
            ASSERT(first->second.compare("World") == 0);
        }
        ASSERT(stringMap.size() == arraySize);

        stringMap.erase(42);
        first = stringMap.begin();
        last = stringMap.end();
        for (int i = 0; first != last; ++i)
        {
            if (values[i] != 42)
            {
                ASSERT(values[i] == first->first);
                ASSERT(first->second.compare("World") == 0);
                ++first;
            }
        }
        ASSERT(stringMap.size() == arraySize - 1);

        stringMap.erase(101);
        first = stringMap.begin();
        last = stringMap.end();
        for (int i = 0; first != last; ++i)
        {
            if (values[i] != 42 && values[i] != 101)
            {
                ASSERT(values[i] == first->first);
                ASSERT(first->second.compare("World") == 0);
                ++first;
            }
        }
        ASSERT(stringMap.size() == arraySize - 2);

        stringMap.erase(24);
        first = stringMap.begin();
        last = stringMap.end();
        for (int i = 0; first != last; ++i)
        {
            if (values[i] != 42 && values[i] != 101 && values[i] != 24)
            {
                ASSERT(values[i] == first->first);
                ASSERT(first->second.compare("World") == 0);
                ++first;
            }
        }
        ASSERT(stringMap.size() == arraySize - 3);

        stringMap.erase(70);
        first = stringMap.begin();
        last = stringMap.end();
        for (int i = 0; first != last; ++i)
        {
            if (
                values[i] != 70 && values[i] != 42
                && values[i] != 24 && values[i] != 101
            )
            {
                ASSERT(values[i] == first->first);
                ASSERT(first->second.compare("World") == 0);
                ++first;
            }
        }
        ASSERT(stringMap.size() == arraySize - 4);
    }
    return 0;
}

static int testMapEraseRange()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);
        ft::map<int, std::string> stringMap = getStringMap(
            values, "World", arraySize
        );

        std::sort(values, values + arraySize);
        ft::map<int, std::string>::iterator first = stringMap.begin();
        for (int i = 0; i < 5; ++i)
            ++first;
        stringMap.erase(stringMap.begin() , first);
        first = stringMap.begin();
        ft::map<int, std::string>::iterator last = stringMap.end();
        for (int i = 5; first != last; ++first, ++i)
        {
            ASSERT(values[i] == first->first);
            ASSERT(first->second.compare("World") == 0);
        }
    }
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);
        ft::map<int, std::string> stringMap = getStringMap(
            values, "World", arraySize
        );

        stringMap.erase(stringMap.begin(), stringMap.end());
        ASSERT(stringMap.size() == 0);
        ASSERT(stringMap.begin() == stringMap.end());
    }
    return 0;
}

static int testMapClear()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);
        ft::map<int, std::string> stringMap = getStringMap(
            values, "World", arraySize
        );
        ASSERT(stringMap.size() == arraySize);

        stringMap.clear();
        ASSERT(stringMap.size() == 0);
        ASSERT(stringMap.begin() == stringMap.end());
    }
    return 0;
}

static int testMapSwap()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);
        ft::map<int, std::string> stringMap = getStringMap(
            values, "World", arraySize
        );

        ft::map<int, std::string> copyMap(stringMap);
        copyMap.insert(ft::make_pair(1000, "World"));
        copyMap.swap(stringMap);

        ASSERT(copyMap.size() == arraySize);
        ASSERT(stringMap.size() == arraySize + 1);
        ft::map<int, std::string>::iterator first = copyMap.begin();
        ft::map<int, std::string>::iterator last = copyMap.end();
        ft::map<int, std::string>::iterator firstCopy = stringMap.begin();
        for (; first != last; ++first, ++firstCopy)
        {
            ASSERT(first->first == firstCopy->first);
        }
        ASSERT(firstCopy->first == 1000);
    }
    return 0;
}

static int testMapFind()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);
        ft::map<int, std::string> stringMap = getStringMap(
            values, "World", arraySize
        );

        ft::map<int, std::string>::const_iterator found = stringMap.find(101);
        ASSERT(found->first == 101);
    }
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);
        ft::map<int, std::string> stringMap = getStringMap(
            values, "World", arraySize
        );

        ft::map<int, std::string>::iterator found = stringMap.find(101);
        ASSERT(found->first == 101);
        found->second = "Hello";
        ASSERT(stringMap.find(101)->second.compare("Hello") == 0);
    }
    return 0;
}

static int testMapLowerBound()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);
        ft::map<int, std::string> stringMap = getStringMap(
            values, "World", arraySize
        );

        ft::map<int, std::string>::const_iterator lower_bound;
        lower_bound = stringMap.lower_bound(101);
        ASSERT(lower_bound->first == 101);
        lower_bound = stringMap.lower_bound(102);
        ASSERT(lower_bound == stringMap.end());
        lower_bound = stringMap.lower_bound(43);
        ASSERT(lower_bound->first == 70);
    }
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);
        ft::map<int, std::string> stringMap = getStringMap(
            values, "World", arraySize
        );

        ft::map<int, std::string>::iterator lower_bound;
        lower_bound = stringMap.lower_bound(101);
        ASSERT(lower_bound->first == 101);
        lower_bound->second = "Hello";
        ASSERT(stringMap.find(101)->second.compare("Hello") == 0);
    }
    return 0;
}

static int testMapUpperBound()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);
        ft::map<int, std::string> stringMap = getStringMap(
            values, "World", arraySize
        );

        ft::map<int, std::string>::const_iterator upper_bound;
        upper_bound = stringMap.upper_bound(101);
        ASSERT(upper_bound == stringMap.end());
        upper_bound = stringMap.upper_bound(42);
        ASSERT(upper_bound->first == 70);
    }
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);
        ft::map<int, std::string> stringMap = getStringMap(
            values, "World", arraySize
        );

        ft::map<int, std::string>::iterator lower_bound;
        lower_bound = stringMap.upper_bound(42);
        ASSERT(lower_bound->first == 70);
        lower_bound->second = "Hello";
        ASSERT(stringMap.find(70)->second.compare("Hello") == 0);
    }
    return 0;
}

static int testMapEqualRange()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);
        ft::map<int, std::string> stringMap = getStringMap(
            values, "World", arraySize
        );

        ft::pair<
            ft::map<int, std::string>::const_iterator,
            ft::map<int, std::string>::const_iterator
        > equal_range = stringMap.equal_range(33);
        ASSERT(equal_range.first == equal_range.second);
        ASSERT(equal_range.first->first == 35);
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
            ft::pair<
                ft::map<int, std::string>::iterator,
                ft::map<int, std::string>::iterator
            > equal_range = stringMap.equal_range(33);
            equal_range.first->second = "Hello";
            ASSERT(equal_range.second->second.compare("Hello") == 0);
        }
    }
    return 0;
}

static int testMapAssignementOperator()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);
        ft::map<int, std::string> stringMap = getStringMap(
            values, "World", arraySize
        );

        ft::map<int, std::string>::iterator first = stringMap.begin();
        for (int i = 0; i < 5; ++i)
            ++first;
        ft::map<int, std::string> copyMap(
            stringMap.begin(), first
        );
        ASSERT(copyMap.size() == 5);

        std::sort(values, values + arraySize);
        copyMap = stringMap;
        ft::map<int, std::string>::const_iterator firstCopy = copyMap.begin();
        first = stringMap.begin();
        ft::map<int, std::string>::const_iterator last = stringMap.end();
        for (; first != last; ++first, ++firstCopy)
        {
            ASSERT(first->first == firstCopy->first);
            ASSERT(first->second.compare(firstCopy->second) == 0);
        }
        ASSERT(firstCopy == copyMap.end());
        ASSERT(copyMap.size() == copyMap.size());
    }
    return 0;
}

static int testMapAccessOperator()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);
        ft::map<int, std::string> stringMap = getStringMap(
            values, "World", arraySize
        );

        stringMap[42] = "Hello";
        ASSERT(stringMap[42].compare("Hello") == 0);
        stringMap[1000] = "World";
        ASSERT(stringMap.size() == arraySize + 1);
        ASSERT(stringMap[1000].compare("World") == 0);

        std::sort(values, values + arraySize);
        ft::map<int, std::string>::iterator first = stringMap.begin();
        ft::map<int, std::string>::iterator last = stringMap.end();
        for (int i = 0; first != last; ++first, ++i)
        {
            if (first->first == 42)
            {
                ASSERT(first->second.compare("Hello") == 0);
            }
            if (first->first == 1000)
                ASSERT(first->second.compare("World") == 0)
            else
                ASSERT(values[i] == first->first);
        }
    }
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
        new TestCase("test map copy constructor", testMapCopyConstructor)
    );
    map->addTest(
        new TestCase("test map reverse iterator", testMapReverseIterator)
    );
    map->addTest(
        new TestCase("test map value comp", testMapValueComp)
    );
    map->addTest(
        new TestCase("test map count", testMapCount)
    );
    map->addTest(
        new TestCase(
            "test map insert single element", testMapInsertSingleElement
        )
    );
    map->addTest(
        new TestCase("test map insert with hint", testMapInsertWithHint)
    );
    map->addTest(
        new TestCase("test map insert range", testMapInsertRange)
    );
    map->addTest(
        new TestCase("test map erase position", testMapErasePosition)
    );
    map->addTest(
        new TestCase("test map erase key", testMapEraseKey)
    );
    map->addTest(
        new TestCase("test map erase range", testMapEraseRange)
    );
    map->addTest(
        new TestCase("test map clear", testMapClear)
    );
    map->addTest(
        new TestCase("test map swap", testMapSwap)
    );
    map->addTest(
        new TestCase("test map find", testMapFind)
    );
    map->addTest(
        new TestCase("test map lower bound", testMapLowerBound)
    );
    map->addTest(
        new TestCase("test map upper bound", testMapUpperBound)
    );
    map->addTest(
        new TestCase("test map equal range", testMapEqualRange)
    );
    map->addTest(
        new TestCase(
            "test map assignement operator",
            testMapAssignementOperator
        )
    );
    map->addTest(
        new TestCase("test map access operator", testMapAccessOperator)
    );

    return map;
}