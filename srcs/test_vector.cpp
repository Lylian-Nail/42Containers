/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:24:11 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/31 15:53:47 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <memory>

#ifdef STD

# include <vector>
# include <iostream>
namespace ft = std;

#else

# include "vector.hpp"

#endif

static int testVectorDefaultCtor()
{
    ft::vector<int> vector;

    ASSERT(vector.size() == 0);
    ASSERT(vector.capacity() == 0);
    ASSERT(vector.begin() == vector.end());

    return 0;
}

static int testVectorFillCtor()
{
    {
        ft::vector<std::string> vector(10, "Hey");
    
        ASSERT(vector.size() == 10);
        ASSERT(vector.capacity() == 10);
        ft::vector<std::string>::const_iterator itBegin(vector.begin());
        ft::vector<std::string>::const_iterator itEnd(vector.end());
        for (; itBegin != itEnd; itBegin++)
            ASSERT(itBegin->compare("Hey") == 0);
    }

    {
        ft::vector<std::string> vector(1000);

        ASSERT(vector.size() == 1000);
        ASSERT(vector.capacity() == 1000);
        ft::vector<std::string>::const_iterator itBegin(vector.begin());
        ft::vector<std::string>::const_iterator itEnd(vector.end());
        for (; itBegin != itEnd; itBegin++)
            ASSERT(itBegin->empty());
    }
    return 0;
}

static int testVectorRangeCtor()
{
    std::vector<int> vectorOfInt(10000, 42);
    std::vector<int>::const_iterator first(vectorOfInt.begin());
    std::vector<int>::const_iterator last(vectorOfInt.end());

    ft::vector<int> vector(vectorOfInt.begin(), vectorOfInt.end());
    ft::vector<int>::const_iterator itBegin(vector.begin());
    ft::vector<int>::const_iterator itEnd(vector.end());

    for (; itBegin != itEnd; itBegin++, first++)
    {
        ASSERT(*first == *itBegin);
    }
    return 0;
}

static int testVectorCopyCtor()
{
    ft::vector<int> vectorOfInt(100000, 42);
    ft::vector<int>::const_iterator first(vectorOfInt.begin());
    ft::vector<int>::const_iterator last(vectorOfInt.end());
    ft::vector<int> vector(vectorOfInt);
    ft::vector<int>::const_iterator begin(vector.begin());
    ft::vector<int>::const_iterator end(vector.end());

    ASSERT(vectorOfInt.size() == vector.size());
    ASSERT(vectorOfInt.capacity() == vector.capacity());
    ASSERT(vectorOfInt.get_allocator() == vector.get_allocator());
    ASSERT(first != begin);

    for (; first != last; first++, begin++)
        ASSERT(*first == *begin);
    return 0;
}

static int testVectorMaxSize()
{
    ft::vector<int> vectorOfInt(1000, 42);
    std::allocator<int> alloc;

    ASSERT(vectorOfInt.max_size() == alloc.max_size());

    return 0;
}

TestSuite *testUnitVector()
{
    TestSuite *vector = new TestSuite("vector");

    vector->addTest(
        new TestCase("test_vector_default_ctor", testVectorDefaultCtor)
    );
    vector->addTest(
        new TestCase("test_vector_fill_ctor", testVectorFillCtor)
    );
    vector->addTest(
        new TestCase("test_vector_range_ctor", testVectorRangeCtor)
    );
    vector->addTest(
        new TestCase("test_vector_copy_ctor", testVectorCopyCtor)
    );
    vector->addTest(
        new TestCase("test_vector_max_size", testVectorMaxSize)
    );

    return vector;
}
