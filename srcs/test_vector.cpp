/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:24:11 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/21 13:10:32 by lperson-         ###   ########.fr       */
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

static int testVectorEmpty()
{
    {
        ft::vector<int> vectorOfInt(0);
    
        ASSERT(vectorOfInt.empty());
    }
    {
        ft::vector<int> vectorOfInt(10);

        ASSERT(!vectorOfInt.empty());
    }

    return 0;
}

static int testVectorReverseIterator()
{
    {
        ft::vector<int> vectorOfInt;
        ft::vector<int>::const_reverse_iterator first(vectorOfInt.rbegin());
        ft::vector<int>::const_reverse_iterator last(vectorOfInt.rend());

        for (; first != last; first++)
            ASSERT(false);
    }
    {
        ft::vector<int> vectorOfInt(100000, 42);
        ft::vector<int>::const_reverse_iterator first(vectorOfInt.rbegin());
        ft::vector<int>::const_reverse_iterator last(vectorOfInt.rend());
        ft::vector<int>::size_type size = 0;

        for (; first != last; first++)
        {
            size++;
            ASSERT(*first == 42);
        }
        ASSERT(size == vectorOfInt.size());
    }

    return 0;
}

static int testVectorAccessOperator()
{
    {
        ft::vector<std::string> vectorOfString(100, "Hello, World");

        ft::vector<std::string>::reference string = vectorOfString[0];

        string = "Hello, there";
        vectorOfString[1] = "General Kenobi";

        ft::vector<std::string>::size_type i = 0;
        ft::vector<std::string>::size_type size = vectorOfString.size();
        while (i < size)
        {
            if (i == 0)
            {
                ASSERT(vectorOfString[i].compare("Hello, there") == 0);
            }
            else if (i == 1)
            {
                ASSERT(vectorOfString[i].compare("General Kenobi") == 0);
            }
            else
            {
                ASSERT(vectorOfString[i].compare("Hello, World") == 0);
            }
            ++i;
        }
    }
    {
        ft::vector<std::string> const vectorOfString(100, "Hello, world");

        ft::vector<std::string>::size_type i = 0;
        ft::vector<std::string>::size_type size = vectorOfString.size();
        while (i < size)
        {
            ASSERT(vectorOfString[i].compare("Hello, world") == 0);
            ++i;
        }
    }
    return 0;
}

static int testVectorAt()
{
    {
        ft::vector<std::string> vectorOfString(100, "Hello, World");

        ft::vector<std::string>::size_type i = 0;
        ft::vector<std::string>::size_type size = vectorOfString.size();

        vectorOfString.at(0) = "Hello, there";
        ft::vector<std::string>::reference string = vectorOfString.at(1);
        string = "General Kenobi";
        while (i < size)
        {
            if (i == 0)
            {
                ASSERT(vectorOfString.at(i).compare("Hello, there") == 0);
            }
            else if (i == 1)
            {
                ASSERT(vectorOfString.at(i).compare("General Kenobi") == 0);
            }
            else
            {
                ASSERT(vectorOfString.at(i).compare("Hello, World") == 0);
            }
            ++i;
        }
        try
        {
            vectorOfString.at(i);
            ASSERT(false);
        }
        catch (std::out_of_range &e)
        {
            ASSERT(true);
        }
    }
    {
        ft::vector<std::string> const vectorOfString(100, "Hello, World");

        ft::vector<std::string>::size_type i = 0;
        ft::vector<std::string>::size_type size = vectorOfString.size();

        while (i < size)
        {
            ASSERT(vectorOfString.at(i).compare("Hello, World") == 0);
            ++i;
        }
        try
        {
            vectorOfString.at(i);
            ASSERT(false);
        }
        catch (std::out_of_range &e)
        {
            ASSERT(true);
        }
    }

    {
        ft::vector<int> vectorOfInt;

        try
        {
            vectorOfInt.at(0);
            ASSERT(false);
        }
        catch(const std::out_of_range &e)
        {
            ASSERT(true);
        }
    }
    return 0;
}

static int testVectorFront()
{
    {
        ft::vector<int> vectorOfInt(100, 42);

        ASSERT(vectorOfInt.front() == 42);
        vectorOfInt[0] = -42;
        ASSERT(vectorOfInt.front() == -42);
        vectorOfInt.front() = 42;
        ASSERT(vectorOfInt.front() == 42);
    }
    {
        ft::vector<int> const vectorOfInt(100, 42);
        ASSERT(vectorOfInt.front() == 42);
    }
    return 0;
}

static int testVectorBack()
{
    {
        ft::vector<int> vectorOfInt(100, 42);

        ASSERT(vectorOfInt.back() == 42);
        vectorOfInt[vectorOfInt.size() - 1] = -42;
        ASSERT(vectorOfInt.back() == -42);
        vectorOfInt.back() = 42;
        ASSERT(vectorOfInt.back() == 42);
    }
    {
        ft::vector<int> const vectorOfInt(100, 42);
        ASSERT(vectorOfInt.back() == 42);
    }
    return 0;
}

static int testVectorReserve()
{
    ft::vector<char> vector(100, 'a');
    ft::vector<char> vectorCopy(vector);
    ft::vector<char>::const_iterator first = vectorCopy.begin();

    vector.reserve(110);
    ft::vector<char>::const_iterator begin = vector.begin();
    ft::vector<char>::const_iterator last = vector.end();

    ASSERT(vector.capacity() >= 100);
    ASSERT(vectorCopy.size() == vector.size());
    ASSERT(vectorCopy.capacity() != vector.capacity());

    for (; begin != last; begin++, first++)
    {
        ASSERT(*first == *begin);
    }
    return 0;
}

static int testVectorResize()
{
    {
        ft::vector<char> vector(1000, 'a');
        ft::vector<char> vectorCopy(vector);

        vector.resize(2000, 'b');
        ft::vector<char>::size_type size = vector.size();
        ft::vector<char>::size_type sizeCopy = vectorCopy.size();

        ASSERT(vectorCopy.size() == 1000);
        ASSERT(vector.size() == 2000);
    
        for (ft::vector<char>::size_type i = 0; i < sizeCopy; i++)
            ASSERT(vector[i] == vectorCopy[i]);

        for (; sizeCopy < size; ++sizeCopy)
            ASSERT(vector[sizeCopy] == 'b');

        vector.resize(1000);

        ASSERT(vector.size() == vectorCopy.size());

        size = vector.size();
        for (ft::vector<char>::size_type i = 0; i < size; ++i)
            ASSERT(vector[i] == vectorCopy[i]);
    }
    return 0;
}

static int testVectorPushBack()
{
    {
        ft::vector<int> vectorOfInt(100, 42);
        ft::vector<int>::size_type oldSize = vectorOfInt.size();

        ASSERT(vectorOfInt.back() == 42);
        vectorOfInt.push_back(-42);
        ASSERT(vectorOfInt.back() == -42);
        ASSERT(vectorOfInt.size() == oldSize + 1);
    }
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
    vector->addTest(
        new TestCase("test_vector_empty", testVectorEmpty)
    );
    vector->addTest(
        new TestCase("test_vector_reverse_iterator", testVectorReverseIterator)
    );
    vector->addTest(
        new TestCase("test_vector_access_operator", testVectorAccessOperator)
    );
    vector->addTest(
        new TestCase("test_vector_at", testVectorAt)
    );
    vector->addTest(
        new TestCase("test_vector_front", testVectorFront)
    );
    vector->addTest(
        new TestCase("test_vector_back", testVectorBack)
    );
    vector->addTest(
        new TestCase("test_vector_reserve", testVectorReserve)
    );
    vector->addTest(
        new TestCase("test_vector_resize", testVectorResize)
    );
    vector->addTest(
        new TestCase("test_vector_push_back", testVectorPushBack)
    );

    return vector;
}
