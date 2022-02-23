/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:24:11 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/23 15:07:29 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <memory>

#include <stdexcept>

#ifdef STD

# include <vector>
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

    ASSERT(vectorOfInt.size() == vector.size());
    ASSERT(vectorOfInt.capacity() == vector.capacity());

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
    {
        ft::vector<int> vectorEmpty;

        vectorEmpty.push_back(-42);
        ASSERT(vectorEmpty.back() == -42);
        ASSERT(vectorEmpty.front() == -42);
        ASSERT(vectorEmpty.size() == 1);
    }
    return 0;
}

static int testVectorPopBack()
{
    {
        ft::vector<int> vectorOfInt(100, 42);
        ft::vector<int>::size_type oldSize = vectorOfInt.size();

        ASSERT(vectorOfInt.back() == 42);
        vectorOfInt.push_back(-42);
        ASSERT(vectorOfInt.back() == -42);
        ASSERT(vectorOfInt.size() == oldSize + 1);
        vectorOfInt.pop_back();
        ASSERT(vectorOfInt.back() == 42);
        ASSERT(vectorOfInt.size() == oldSize);
    }
    {
        ft::vector<int> vectorEmpty;

        vectorEmpty.push_back(-42);
        ASSERT(vectorEmpty.back() == -42);
        ASSERT(vectorEmpty.front() == -42);
        ASSERT(vectorEmpty.size() == 1);
        vectorEmpty.pop_back();
        ASSERT(vectorEmpty.size() == 0);
    }
    return 0;
}

static int testVectorClear()
{
    {
        ft::vector<int> vectorOfInt(100, 42);

        ASSERT(vectorOfInt.size() != 0);
        vectorOfInt.clear();
        ASSERT(vectorOfInt.size() == 0);
        ASSERT(vectorOfInt.begin() == vectorOfInt.end());
    }
    {
        ft::vector<int> vectorEmpty;

        ASSERT(vectorEmpty.size() == 0);
        ASSERT(vectorEmpty.begin() == vectorEmpty.end());
        vectorEmpty.clear();
        ASSERT(vectorEmpty.size() == 0);
        ASSERT(vectorEmpty.begin() == vectorEmpty.end());
    }
    return 0;
}

static int testVectorAssignRange()
{
    {
        ft::vector<int> vectorOfInt(100, 42);
        ft::vector<int> vectorCopied(150, -42);

        ft::vector<int>::const_iterator first(vectorOfInt.begin());
        ft::vector<int>::const_iterator last(vectorOfInt.end());
        ft::vector<int>::const_iterator firstCopied(vectorCopied.begin());
        ft::vector<int>::const_iterator lastCopied(vectorCopied.end());
        for (; first != last; first++)
            ASSERT(*first == 42);

        vectorOfInt.assign(vectorCopied.begin(), vectorCopied.end());
        first = vectorOfInt.begin();
        last = vectorOfInt.end();
        for (; first != last; first++, firstCopied++)
            ASSERT(*first == *firstCopied);
        ASSERT(vectorOfInt.size() == vectorCopied.size());
    }
    {
        ft::vector<int> vectorOfInt(100, 42);
        ft::vector<int> vectorEmpty;

        vectorOfInt.assign(vectorEmpty.begin(), vectorEmpty.end());
        ASSERT(vectorOfInt.size() == 0);
        ASSERT(vectorOfInt.begin() == vectorOfInt.end());
    }
    return 0;
}

static int testVectorAssignFill()
{
    {
        ft::vector<int> vectorOfInt(100, 42);
        ft::vector<int>::const_iterator first(vectorOfInt.begin());
        ft::vector<int>::const_iterator last(vectorOfInt.end());

        for (; first != last; first++)
            ASSERT(*first == 42);
        vectorOfInt.assign(150, -42);
        first = vectorOfInt.begin();
        last = vectorOfInt.end();
        for (; first != last; first++)
            ASSERT(*first == -42);
    }
    {
        ft::vector<int> vectorOfInt(100, 42);

        ASSERT(vectorOfInt.size() > 0);
        vectorOfInt.assign(0, -42);
        ASSERT(vectorOfInt.size() == 0);
        ASSERT(vectorOfInt.begin() == vectorOfInt.end());
    }
    return 0;
}

static int testVectorErasePosition()
{
    {
        ft::vector<int> vectorOfInt;

        for (ft::vector<int>::size_type i = 1; i < 100; ++i)
            vectorOfInt.push_back(i);
        
        ft::vector<int>::size_type erasePosition = 9;
        ft::vector<int>::iterator newPos;
        newPos = vectorOfInt.erase(vectorOfInt.begin() + erasePosition);
        ASSERT(*newPos == 11);

        ft::vector<int>::const_iterator first(vectorOfInt.begin());
        ft::vector<int>::const_iterator last(vectorOfInt.end());
        for (int i = 1; first != newPos; first++, i++)
        {
            ASSERT(i == *first);
        }
        for (int i = *newPos; newPos != last; newPos++, ++i)
        {
            ASSERT(i == *newPos);
        }
    }
    {
        ft::vector<int> vectorOfInt;

        for (int i = 1; i < 100; ++i)
            vectorOfInt.push_back(i);

        ft::vector<int>::iterator newPos;
        newPos = vectorOfInt.erase(vectorOfInt.end() - 1);
        ASSERT(newPos == vectorOfInt.end());
        ASSERT(vectorOfInt.back() == 98);
    }
    return 0;
}

static int testVectorEraseRange()
{
    {
        ft::vector<int> vectorOfInt;

        for (int i = 1; i < 300; ++i)
            vectorOfInt.push_back(i);

        ft::vector<int>::iterator newPosition = vectorOfInt.erase(
            vectorOfInt.begin() + 99, vectorOfInt.begin() + 199
        );
        ft::vector<int>::const_iterator first = vectorOfInt.begin();
        for (int i = 1; first != newPosition; first++, ++i)
        {
            ASSERT(*first == i);
        }

        ASSERT(*newPosition == 200);
        ft::vector<int>::const_iterator last = vectorOfInt.end();
        for (int i = 200; newPosition != last; ++i, ++newPosition)
        {
            ASSERT(i == *newPosition);
        }
    }
    {
        ft::vector<int> vectorOfInt;

        for (int i = 1; i <= 10; ++i)
            vectorOfInt.push_back(i);

        ft::vector<int>::iterator newPosition = vectorOfInt.erase(
            vectorOfInt.begin() + 4, vectorOfInt.begin() + 8
        );
        ft::vector<int>::const_iterator first = vectorOfInt.begin();
        for (int i = 1; first != newPosition; ++i, ++first)
        {
            ASSERT(i == *first);
        }
        ASSERT(*newPosition == 9);
        ft::vector<int>::const_iterator last = vectorOfInt.end();
        for (int i = 9; newPosition != last; ++i, ++newPosition)
        {
            ASSERT(i == *newPosition);
        }
    }
    {
        ft::vector<int> vectorOfInt;

        for (int i = 1; i <= 10; ++i)
            vectorOfInt.push_back(i);

        ft::vector<int>::iterator newPosition = vectorOfInt.erase(
            vectorOfInt.begin(), vectorOfInt.end()
        );

        ASSERT(vectorOfInt.size() == 0);
        ASSERT(newPosition == vectorOfInt.end());
    }
    return 0;
}

static int testVectorAssignementOperator()
{
    {
        ft::vector<int> vectorOfInt(100, 42);
        ft::vector<int> vectorCopy(250, -42);

        ASSERT(vectorCopy.size() != vectorOfInt.size());
        vectorCopy = vectorOfInt;
        ASSERT(vectorCopy.capacity() != vectorOfInt.capacity());
        ASSERT(vectorCopy.size() == vectorOfInt.size());
        ft::vector<int>::const_iterator first = vectorOfInt.begin();
        ft::vector<int>::const_iterator last = vectorOfInt.end();
        ft::vector<int>::const_iterator copied = vectorCopy.begin();

        for (; first != last; ++first, ++copied)
        {
            ASSERT(*first == *copied);
        }
    }
    {
        ft::vector<int> vectorEmpty;
        ft::vector<int> vectorCopied(100, 42);

        vectorCopied = vectorEmpty;
        ASSERT(vectorCopied.size() == vectorEmpty.size());
        ASSERT(vectorCopied.end() == vectorCopied.begin());
        ASSERT(vectorCopied.capacity() != vectorEmpty.capacity());
    }
    return 0;
}

static int testVectorSwap()
{
    {
        ft::vector<int> vectorOfInt;
        ft::vector<int> vectorSwapped;

        for (int i = 1; i < 100; ++i)
            vectorOfInt.push_back(i);
        for (int i = 100; i < 300; ++i)
            vectorSwapped.push_back(i);

        ft::vector<int> vectorCopy(vectorOfInt);
        ft::vector<int>::const_iterator first = vectorOfInt.begin();
        ft::vector<int>::const_iterator last = vectorOfInt.end();

        vectorOfInt.swap(vectorSwapped);
        ASSERT(vectorSwapped.size() == vectorCopy.size());
        ASSERT(vectorOfInt.size() == 200);

        // Check validity of iterators after swap
        for (int i = 1; first != last; ++first, ++i)
            ASSERT(*first == i);

        first = vectorSwapped.begin();
        last = vectorSwapped.end();
        ft::vector<int>::const_iterator copy = vectorCopy.begin();
        for (; first != last; ++copy, ++first)
            ASSERT(*copy == *first);

        first = vectorOfInt.begin();
        last = vectorOfInt.end();
        for (int i = 100; first != last; ++i, ++first)
        {
            ASSERT(i == *first);
        }
    }
    return 0;
}

static int testVectorInsertSingleElement()
{
    {
        ft::vector<int> vectorOfInt;

        for (int i = 1; i < 100; ++i)
            vectorOfInt.push_back(i);
        ft::vector<int>::size_type oldSize = vectorOfInt.size();
        ft::vector<int>::iterator newPosition = vectorOfInt.insert(
            vectorOfInt.begin() + 50, 420
        );
        ASSERT(oldSize == vectorOfInt.size() - 1);

        ft::vector<int>::const_iterator first = vectorOfInt.begin();
        for (int i = 1; first != newPosition; ++i, ++first)
        {
            ASSERT(*first == i);
        }
        ASSERT(*newPosition == 420);
        ++newPosition;
        ft::vector<int>::const_iterator last = vectorOfInt.end();
        for (int i = 51; newPosition != last; ++i, ++newPosition)
        {
            ASSERT(*newPosition == i);
        }
    }
    {
        ft::vector<int> vectorEmpty;
        ft::vector<int>::iterator newPosition = vectorEmpty.insert(
            vectorEmpty.begin(), 420
        );

        ASSERT(vectorEmpty.size() == 1);
        ASSERT(vectorEmpty.front() == vectorEmpty.back());
        ASSERT(vectorEmpty.front() == *newPosition);
        ASSERT(*newPosition == 420);
    }
    return 0;
}

static int testVectorNonMemberSwap()
{
    {
        ft::vector<int> vectorOfInt;
        ft::vector<int> vectorSwapped;
        for (int i = 1; i < 100; ++i)
            vectorOfInt.push_back(i);
        for (int i = 100; i < 300; ++i)
            vectorSwapped.push_back(i);
    
        ft::vector<int> vectorCopy(vectorOfInt);
        ft::vector<int>::const_iterator first = vectorOfInt.begin();
        ft::vector<int>::const_iterator last = vectorOfInt.end();
    
        vectorOfInt.swap(vectorSwapped);
        ASSERT(vectorSwapped.size() == vectorCopy.size());
        ASSERT(vectorOfInt.size() == 200);
    
        // Check validity of iterators after swap
        for (int i = 1; first != last; ++first, ++i)
            ASSERT(*first == i);
    
        first = vectorSwapped.begin();
        last = vectorSwapped.end();
        ft::vector<int>::const_iterator copy = vectorCopy.begin();
        for (; first != last; ++copy, ++first)
            ASSERT(*copy == *first);
    
        first = vectorOfInt.begin();
        last = vectorOfInt.end();
        for (int i = 100; first != last; ++i, ++first)
        {
            ASSERT(i == *first);
        }
    }
    return 0;
}

static int testVectorInsertFill()
{
    {
        ft::vector<int> vectorOfInt;

        for (int i = 1; i <= 10; ++i)
        {
            vectorOfInt.push_back(i);
        }

        ASSERT(vectorOfInt.size() == 10);
        ft::vector<int>::iterator insertedPosition = vectorOfInt.begin() + 4;
        vectorOfInt.insert(
            insertedPosition,
            3,
            42
        );
        ASSERT(vectorOfInt.size() == 13);

        insertedPosition = vectorOfInt.begin() + 4;
        ft::vector<int>::iterator first = vectorOfInt.begin();
        for (int i = 1; first != insertedPosition; ++first, ++i)
        {
            ASSERT(i == *first);
        }

        ft::vector<int>::iterator lastInsertedPosition = insertedPosition + 3;
        for (; insertedPosition != lastInsertedPosition; ++insertedPosition)
        {
            ASSERT(*insertedPosition == 42);
        }

        ft::vector<int>::iterator last = vectorOfInt.end();
        for (
            int i = 5;
            lastInsertedPosition != last;
            ++lastInsertedPosition, ++i
        )
        {
            ASSERT(*lastInsertedPosition == i)
        }
    }
    {
        ft::vector<int> vectorOfInt;

        vectorOfInt.insert(vectorOfInt.begin(), 10, 42);
        ASSERT(vectorOfInt.size() == 10);

        ft::vector<int>::const_iterator first = vectorOfInt.begin();
        ft::vector<int>::const_iterator last = vectorOfInt.end();
        for (; first != last; ++first)
        {
            ASSERT(*first == 42);
        }
    }
    return 0;
}

static int testVectorInsertRange()
{
    {
        ft::vector<int> vectorOfInt;
        ft::vector<int> insertedVector;

        for (int i = 1; i <= 10; ++i)
        {
            vectorOfInt.push_back(i);
        }
        for (int i = 11; i <= 20; ++i)
        {
            insertedVector.push_back(i);
        }

        ASSERT(vectorOfInt.size() == 10);
        vectorOfInt.insert(
            vectorOfInt.begin() + 4,
            insertedVector.begin(),
            insertedVector.end()
        );
        ft::vector<int>::const_iterator first = vectorOfInt.begin();
        ft::vector<int>::const_iterator insertedPosition;
        insertedPosition = vectorOfInt.begin() + 4;
        for (int i = 1; first != insertedPosition; ++first, ++i)
        {
            ASSERT(i == *first);
        }

        ft::vector<int>::const_iterator lastInsertedPosition;
        lastInsertedPosition = insertedPosition + insertedVector.size();
        for (
            int i = 11; 
            insertedPosition != lastInsertedPosition; 
            ++insertedPosition, ++i
        )
        {
            ASSERT(i == *insertedPosition);
        }

        ft::vector<int>::const_iterator last = vectorOfInt.end();
        for (
            int i = 5;
            lastInsertedPosition != last;
            ++lastInsertedPosition, ++i
        )
        {
            ASSERT(i == *lastInsertedPosition);
        }
    }
    {
        ft::vector<int> vectorEmpty;
        ft::vector<int> vectorInserted;

        for (int i = 1; i <= 10; ++i)
        {
            vectorInserted.push_back(i);
        }

        vectorEmpty.insert(
            vectorEmpty.begin(),
            vectorInserted.begin(),
            vectorInserted.end()
        );
        ASSERT(vectorEmpty.size() == 10);
        ft::vector<int>::const_iterator first = vectorEmpty.begin();
        ft::vector<int>::const_iterator last = vectorEmpty.end();
        for (int i = 1; first != last; ++first, ++i)
        {
            ASSERT(*first == i);
        }
    }
    return 0;
}

int testVectorEqualOperator()
{
    {
        ft::vector<int> vectorOfInts;

        for (int i = 0; i < 100; ++i)
            vectorOfInts.push_back(i);

        ft::vector<int> vectorCopy(vectorOfInts);
        ASSERT(vectorOfInts == vectorCopy);
    }
    {
        ft::vector<int> vectorEmpty;
        ft::vector<int> vectorEmptyToo;

        ASSERT(vectorEmpty == vectorEmptyToo);
        vectorEmpty.push_back(42);
        ASSERT(!(vectorEmpty == vectorEmptyToo));
    }
    return 0;
}

int testVectorDifferenceOperator()
{
    {
        ft::vector<int> vectorOfInts;

        for (int i = 0; i < 100; ++i)
            vectorOfInts.push_back(i);
        
        ft::vector<int> vectorOfIntsToo;

        for (int i = 0; i < 101; ++i)
            vectorOfInts.push_back(i);
        ASSERT(vectorOfInts != vectorOfIntsToo);
    }
    {
        ft::vector<int> vectorEmpty;
        ft::vector<int> vectorEmptyToo;

        ASSERT(!(vectorEmpty != vectorEmptyToo));
    }
    return 0;
}

int testVectorLessThanOperator()
{
    {
        ft::vector<int> vectorOfInts;

        for (int i = 0; i < 100; ++i)
            vectorOfInts.push_back(i);
        
        ft::vector<int> vectorOfIntsToo(vectorOfInts);
        vectorOfIntsToo.back() = vectorOfInts.back() - 1;
        ASSERT(vectorOfIntsToo < vectorOfInts);
    }
    {
        ft::vector<int> vectorEmpty;
        ft::vector<int> vectorOfInts(1, 42);

        ASSERT(vectorEmpty < vectorOfInts);
    }
    return 0;
}

int testVectorLessThanOrEqualOperator()
{
    {
        ft::vector<int> vectorOfInts;

        for (int i = 0; i < 100; ++i)
            vectorOfInts.push_back(i);

        ft::vector<int> vectorOfIntsToo(vectorOfInts);
        ASSERT(vectorOfInts <= vectorOfInts);
        vectorOfIntsToo.back() = vectorOfIntsToo.back() - 1;
        ASSERT(vectorOfIntsToo <= vectorOfInts);
    }
    {
        ft::vector<int> vectorEmpty;
        ft::vector<int> vectorEmptyToo;

        ASSERT(vectorEmpty <= vectorEmptyToo);
        vectorEmptyToo.push_back(42);
        ASSERT(vectorEmpty <= vectorEmptyToo);
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
    vector->addTest(
        new TestCase("test_vector_pop_back", testVectorPopBack)
    );
    vector->addTest(
        new TestCase("test_vector_clear", testVectorClear)
    );
    vector->addTest(
        new TestCase("test_vector_assign_range", testVectorAssignRange)
    );
    vector->addTest(
        new TestCase("test_vector_assign_fill", testVectorAssignFill)
    );
    vector->addTest(
        new TestCase("test_vector_erase_position", testVectorErasePosition)
    );
    vector->addTest(
        new TestCase("test_vector_erase_range", testVectorEraseRange)
    );
    vector->addTest(
        new TestCase(
            "test_vector_assignement_operator", testVectorAssignementOperator
        )
    );
    vector->addTest(
        new TestCase("test_vector_swap", testVectorSwap)
    );
    vector->addTest(
        new TestCase("test_vector_non_member_swap", testVectorNonMemberSwap)
    );
    vector->addTest(
        new TestCase(
            "test_vector_insert_single_element", testVectorInsertSingleElement
        )
    );
    vector->addTest(
        new TestCase(
            "test_vector_insert_fill", testVectorInsertFill
        )
    );
    vector->addTest(
        new TestCase(
            "test_vector_insert_range", testVectorInsertRange
        )
    );
    vector->addTest(
        new TestCase("test_vector_equal_operator", testVectorEqualOperator)
    );
    vector->addTest(
        new TestCase(
            "test_vector_difference_operator", testVectorDifferenceOperator
        )
    );
    vector->addTest(
        new TestCase(
            "test_vector_less_than_operator", testVectorLessThanOperator
        )
    );
    vector->addTest(
        new TestCase(
            "test_vector_less_than_or_equal_operator",
            testVectorLessThanOrEqualOperator
        )
    );

    return vector;
}
