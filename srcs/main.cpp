/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:16:12 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/26 12:03:08 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cassert>
#include <iterator.hpp>
#include <typeinfo>
#include "test.hpp"

void test_iterator_traits()
{
    {
        typedef ft::iterator_traits<int *>	traits;

        assert(
            typeid(traits::iterator_category) ==
            typeid(ft::random_access_iterator_tag)
        );

        assert(
            typeid(traits::value_type) ==
            typeid(int)
        );

        assert(
            typeid(traits::reference) ==
            typeid(int &)
        );
    }

    {
        typedef ft::iterator_traits<int const *>	traits;

        assert(
            typeid(traits::iterator_category) ==
            typeid(ft::random_access_iterator_tag)
        );

        assert(
            typeid(traits::value_type) ==
            typeid(int)
        );

        assert(
            typeid(traits::reference) ==
            typeid(int &)
        );
    }
}

void test_iterator()
{
    int	value[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    {
        ft::normal_iterator<int *, int[]> it(value);

        ft::normal_iterator<int *, int[]> itCopy(value);
        itCopy = value;

        assert(it == itCopy);
        ++it;
        assert(it != itCopy);
        itCopy += 1;
        assert(it == itCopy);

        it = it - 1;
        itCopy--;
        assert(it == itCopy); // post decrementation and offset decrementation
        assert(it++ == itCopy); // post incrementation return cpy of previous obj
        assert(1 + it == it + 1); // n + i == i + n
    }

    {
        ft::normal_iterator<int *, int[]> it(value);
        ft::normal_iterator<int *, int[]> itGreater(value + 5);
        ft::normal_iterator<int *, int[]> itCopy(it);

        assert(*it == 0);
        assert(it[0] == 0);
        assert(*(it + 1) == 1);
        assert(*(it + 1 - 1) == 0);
        assert(it < itGreater);
        assert(itGreater > it);
        assert(it >= itCopy);
        assert(itGreater >= itCopy);
        assert(it <= itCopy);
        assert(it <= itGreater);
    }
}

void test_iterator_advance()
{
    {
        int values[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        ft::normal_iterator<int const *, int const []>  it(values);
        ft::normal_iterator<int const *, int const[]> itEnd(values + 10);

        assert(10 == ft::distance(it, itEnd));
    }
}

int one_equal_one()
{
    int errcode;

    errcode = ASSERT(1 == 1);
    errcode = ASSERT(1 != 1);
    return errcode;
}

int main()
{
    TestCase test0 = CREATE_TEST(one_equal_one);
    test0.run();

    TestSuite simple_tests("simple_tests");
    simple_tests.addTest(test0);
}
