/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:57:57 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/27 11:01:00 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <typeinfo>
#include "test.hpp"
#include "iterator.hpp"

static int test_iterator_traits()
{
    {
        typedef ft::iterator_traits<int *> traits;

        ASSERT(
            typeid(traits::iterator_category) ==
            typeid(ft::random_access_iterator_tag)
        );

        ASSERT(
            typeid(traits::value_type) ==
            typeid(int)
        );

        ASSERT(
            typeid(traits::reference) ==
            typeid(int &)
        );
    }

    {
        typedef ft::iterator_traits<int const *> traits;

        ASSERT(
            typeid(traits::iterator_category) ==
            typeid(ft::random_access_iterator_tag)
        );

        ASSERT(
            typeid(traits::value_type) ==
            typeid(int)
        );

        ASSERT(
            typeid(traits::reference) ==
            typeid(int &)
        );
    }
    return 0;
}

static int test_normal_iterator()
{
    int	value[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    {
        ft::normal_iterator<int *, int[]> it(value);

        ft::normal_iterator<int *, int[]> itCopy(value);
        itCopy = value;

        ASSERT(it == itCopy);
        ++it;
        ASSERT(it != itCopy);
        itCopy += 1;
        ASSERT(it == itCopy);

        it = it - 1;
        itCopy--;
        ASSERT(it == itCopy); // post decrementation and offset decrementation
        ASSERT(it++ == itCopy); // post incrementation return cpy of previous obj
        ASSERT(1 + it == it + 1); // n + i == i + n
    }

    {
        ft::normal_iterator<int *, int[]> it(value);
        ft::normal_iterator<int *, int[]> itGreater(value + 5);
        ft::normal_iterator<int *, int[]> itCopy(it);

        ASSERT(*it == 0);
        ASSERT(it[0] == 0);
        ASSERT(*(it + 1) == 1);
        ASSERT(*(it + 1 - 1) == 0);
        ASSERT(it < itGreater);
        ASSERT(itGreater > it);
        ASSERT(it >= itCopy);
        ASSERT(itGreater >= itCopy);
        ASSERT(it <= itCopy);
        ASSERT(it <= itGreater);
    }
    return 0;
}

static int test_iterator_advance()
{
    {
        int values[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        ft::normal_iterator<int const *, int const []>  it(values);
        ft::normal_iterator<int const *, int const[]> itEnd(values + 10);

        ASSERT(10 == ft::distance(it, itEnd));
    }
    return 0;
}

TestSuite *testUnitIterator()
{
    TestSuite *iterator =  new TestSuite("iterator");

    iterator->addTest(
        new TestCase("test_iterator_traits", test_iterator_traits)
    );
    iterator->addTest(
        new TestCase("test_normal_iterator", test_normal_iterator)
    );
    iterator->addTest(
        new TestCase("test_iterator_advance", test_iterator_advance)
    );

    return iterator;
}
