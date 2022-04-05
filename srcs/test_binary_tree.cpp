/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_binary_tree.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:07:37 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/05 11:06:50 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include "test.hpp"
#include "binary_tree/BinaryTree.hpp"

static int testBinarySearchTreeDefaultConstructor()
{
    {
        ft::BinarySearchTree<int> intTree;

        ASSERT(intTree.get_allocator() == std::allocator<int>());
        std::less<int> comp = intTree.value_comp();
        ASSERT(comp(1, 10));
    }
    return 0;
}

static int testBinarySearchTreeRangeConstructor()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);

        ft::BinarySearchTree<int> intTree(values, values + arraySize);
        std::sort(values, values + arraySize);
        ft::BinarySearchTree<int>::iterator first = intTree.begin();
        for (std::size_t i(0); i < arraySize; ++i, ++first)
        {
            ASSERT(*first == values[i]);
        }
        ASSERT(first == intTree.end());
        ASSERT(intTree.size() == arraySize);
    }
    return 0;
}

static int testBinarySearchTreeCopyConstructor()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);

        ft::BinarySearchTree<int> intTree(values, values + arraySize);
        ft::BinarySearchTree<int> copyTree(intTree.begin(), intTree.end());
        ft::BinarySearchTree<int>::iterator first = intTree.begin();
        ft::BinarySearchTree<int>::iterator last = intTree.end();
        ft::BinarySearchTree<int>::iterator copyFirst = copyTree.begin();
        for (; first != last; ++first, ++copyFirst)
        {
            ASSERT(*first == *copyFirst);
        }
        ASSERT(copyFirst == copyTree.end());
        ASSERT(copyTree.size() == intTree.size());
    }
    return 0;
}

static int testBinarySearchTreeEmpty()
{
    {
        ft::BinarySearchTree<int> intTree;

        ASSERT(intTree.empty() == true);
    }
    return 0;
}

static int testBinarySearchTreeSize()
{
    {
        ft::BinarySearchTree<int> intTree;

        ASSERT(intTree.size() == 0);
    }
    return 0;
}

static int testBinarySearchTreeMaxSize()
{
    {
        ft::BinarySearchTree<int> intTree;

        ASSERT(intTree.max_size() == intTree.get_allocator().max_size());
    }
    return 0;
}

static int testBinarySearchTreeInsertSingleElement()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);
        ft::BinarySearchTree<int> intTree;
        for (std::size_t i(0); i < arraySize; ++i)
        {
            ft::pair<typename ft::BinarySearchTree<int>::iterator, bool> r;
            r = intTree.insert(values[i]);
            ASSERT(*r.first == values[i] && r.second == true);
        }

        std::sort(values, values + arraySize);
        ft::BinarySearchTree<int>::iterator first = intTree.begin();
        for (std::size_t i(0); i < arraySize; ++i, ++first)
        {
            ASSERT(*first == values[i]);
        }
        ASSERT(first == intTree.end());
        ASSERT(intTree.size() == arraySize);

        ft::pair<typename ft::BinarySearchTree<int>::iterator, bool> r;
        r = intTree.insert(35);
        ASSERT(*r.first == 35 && r.second == false);
    }
    return 0;
}

static int testBinarySearchTreeInsertWithHint()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);

        ft::BinarySearchTree<int> intTree;
        ft::BinarySearchTree<int>::iterator insertedPosition = intTree.begin();
        for (std::size_t i(0); i < arraySize; ++i)
        {
            insertedPosition = intTree.insert(insertedPosition, values[i]);
            ASSERT(*insertedPosition == values[i]);
        }

        std::sort(values, values + arraySize);
        ft::BinarySearchTree<int>::iterator first = intTree.begin();
        for (std::size_t i(0); i < arraySize; ++i, ++first)
        {
            ASSERT(*first== values[i]);
        }
        ASSERT(first == intTree.end());
        ASSERT(intTree.size() == arraySize);

        insertedPosition = intTree.insert(intTree.begin(), 35);
        ASSERT(*insertedPosition == 35);
    }
    {
        int sortedValues[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(sortedValues) / sizeof(sortedValues[0]);
        std::sort(sortedValues, sortedValues + arraySize);

        ft::BinarySearchTree<int> intTree;
        ft::BinarySearchTree<int>::iterator insertedPosition = intTree.begin();
        for (std::size_t i(0); i < arraySize; ++i)
        {
            insertedPosition = intTree.insert(
                insertedPosition, sortedValues[i]
            );
            ASSERT(*insertedPosition == sortedValues[i]);
        }
        ft::BinarySearchTree<int>::iterator first = intTree.begin();
        for (std::size_t i(0); i < arraySize; ++i, ++first)
        {
            ASSERT(*first == sortedValues[i]);
        }
        ASSERT(first == intTree.end());
        ASSERT(intTree.size() == arraySize);
    }
    return 0;
}

static int testBinarySearchTreeInsertRange()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);

        ft::BinarySearchTree<int> intTree;
        intTree.insert(values, values + arraySize);

        std::sort(values, values + arraySize);
        ft::BinarySearchTree<int>::iterator first = intTree.begin();
        for (std::size_t i(0); i < arraySize; ++i, ++first)
        {
            ASSERT(*first == values[i]);
        }
        ASSERT(first == intTree.end());
        ASSERT(intTree.size() == arraySize);
    }
    return 0;
}

static int testBinarySearchTreeCount()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);

        ft::BinarySearchTree<int> intTree(values, values + arraySize);
        ASSERT(intTree.count(42) == 1);
        ASSERT(*intTree.find(10) == 10);
        ASSERT(intTree.count(10) == 1);
        ASSERT(intTree.count(100) == 0);
    }
    {
        ft::BinarySearchTree<int> intTree;
        ASSERT(intTree.count(42) == 0);
    }
    return 0;
}

static int testBinarySearchTreeFind()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);

        ft::BinarySearchTree<int> intTree(values, values + arraySize);
        ft::BinarySearchTree<int>::iterator found = intTree.find(42);
        ASSERT(*found == 42);
        ASSERT(*intTree.find(24) == 24);
        ASSERT(*intTree.find(101) == 101);
        found = intTree.find(99999);
        ASSERT(found == intTree.end());
    }
    return 0;
}

static int testBinarySearchTreeLowerBound()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);

        ft::BinarySearchTree<int> intTree(values, values + arraySize);
        ft::BinarySearchTree<int>::iterator lowerBound = intTree.lower_bound(12);
        ASSERT(*lowerBound == 24);
        lowerBound = intTree.lower_bound(9);
        ASSERT(*lowerBound == 9);
        lowerBound = intTree.lower_bound(90);
        ASSERT(*lowerBound == 101)
        lowerBound = intTree.lower_bound(80);
        ASSERT(*lowerBound == 89);
    }
    {
        ft::BinarySearchTree<int> intTree;
        ft::BinarySearchTree<int>::iterator lowerBound = intTree.lower_bound(42);
        ASSERT(lowerBound == intTree.end());
    }
    return 0;
}

static int testBinarySearchTreeUpperBound()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);

        ft::BinarySearchTree<int> intTree(values, values + arraySize);
        ft::BinarySearchTree<int>::iterator lowerBound = intTree.upper_bound(12);
        ASSERT(*lowerBound == 24);
        lowerBound = intTree.upper_bound(9);
        ASSERT(*lowerBound == 10);
        lowerBound = intTree.upper_bound(90);
        ASSERT(*lowerBound == 101)
        lowerBound = intTree.upper_bound(80);
        ASSERT(*lowerBound == 89);
    }
    {
        ft::BinarySearchTree<int> intTree;
        ft::BinarySearchTree<int>::iterator lowerBound = intTree.upper_bound(42);
        ASSERT(lowerBound == intTree.end());
    }
    return 0;
}

static int testBinarySearchTreeEqualRange()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);

        ft::BinarySearchTree<int> intTree(values, values + arraySize);
        ft::pair<
            ft::BinarySearchTree<int>::iterator,
            ft::BinarySearchTree<int>::iterator
        > range = intTree.equal_range(24);

        ASSERT(*range.first == 24 && *range.second == 24);
        ASSERT(ft::distance(range.first, range.second) == 0);
        range = intTree.equal_range(101);
        ASSERT(*range.first == 101 && *range.second == 101);
        ASSERT(ft::distance(range.first, range.second) == 0);
        range = intTree.equal_range(9);
        ASSERT(*range.first == 9 && *range.second == 9);
        ASSERT(ft::distance(range.first, range.second) == 0);
        range = intTree.equal_range(13);
        ASSERT(*range.first == 24 && *range.second == 24);
        ASSERT(ft::distance(range.first, range.second) == 0);
    }
    {
        ft::BinarySearchTree<int> intTree;
        ft::pair<
            ft::BinarySearchTree<int>::iterator,
            ft::BinarySearchTree<int>::iterator
        > range = intTree.equal_range(42);
        ASSERT(range.first == intTree.end() && range.second == intTree.end());
    }
    return 0;
}

static int testBinarySearchTreeReverseIterator()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);

        ft::BinarySearchTree<int> intTree(values, values + arraySize);
        std::sort(values, values + arraySize);
        ft::BinarySearchTree<int>::reverse_iterator first = intTree.rbegin();
        ft::BinarySearchTree<int>::const_reverse_iterator last = intTree.rend();
        int i;
        for (i = arraySize - 1; first != last; ++first, --i)
        {
            ASSERT(*first == values[i]);
        }
        ASSERT(i == -1);
    }
    return 0;
}

static int testBinarySearchTreeAssignementOperator()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);

        ft::BinarySearchTree<int> intTree(values, values + arraySize);
        ft::BinarySearchTree<int> assignedTree;
        assignedTree.insert(99);
        assignedTree = intTree;
        ft::BinarySearchTree<int>::iterator first = intTree.begin();
        ft::BinarySearchTree<int>::iterator last = intTree.end();
        ft::BinarySearchTree<int>::iterator firstCopy = assignedTree.begin();
        for (; first != last; ++first, ++firstCopy)
        {
            ASSERT(*first == *firstCopy);
        }
        ASSERT(intTree.size() == assignedTree.size());
        ASSERT(firstCopy == assignedTree.end());
    }
    return 0;
}

TestSuite *testUnitBinarySearchTree()
{
    TestSuite *BinarySearchTree = new TestSuite("binary search tree");

    BinarySearchTree->addTest(
        new TestCase(
            "test binary search tree default contructor",
            testBinarySearchTreeDefaultConstructor
        )
    );
    BinarySearchTree->addTest(
        new TestCase(
            "test binary search tree range constructor",
            testBinarySearchTreeRangeConstructor
        )
    );
    BinarySearchTree->addTest(
        new TestCase(
            "test binary search tree Copy Constructor",
            testBinarySearchTreeCopyConstructor
        )
    );
    BinarySearchTree->addTest(
        new TestCase("test binary search tree empty", testBinarySearchTreeEmpty)
    );
    BinarySearchTree->addTest(
        new TestCase("test binary search tree size", testBinarySearchTreeSize)
    );
    BinarySearchTree->addTest(
        new TestCase("test binary search tree max size", testBinarySearchTreeMaxSize)
    );
    BinarySearchTree->addTest(
        new TestCase("test binary search tree count", testBinarySearchTreeCount)
    );
    BinarySearchTree->addTest(
        new TestCase("test binary search tree find", testBinarySearchTreeFind)
    );
    BinarySearchTree->addTest(
        new TestCase(
            "test binary search tree lower bound",
            testBinarySearchTreeLowerBound
        )
    );
    BinarySearchTree->addTest(
        new TestCase("test binary search tree upper bound", testBinarySearchTreeUpperBound)
    );
    BinarySearchTree->addTest(
        new TestCase(
            "test binary search tree equal range",
            testBinarySearchTreeEqualRange
        )
    );
    BinarySearchTree->addTest(
        new TestCase(
            "test binary search tree insert single element",
            testBinarySearchTreeInsertSingleElement
        )
    );
    BinarySearchTree->addTest(
        new TestCase(
            "test binary search tree insert with hint",
            testBinarySearchTreeInsertWithHint
        )
    );
    BinarySearchTree->addTest(
        new TestCase("test binary search tree insert range", testBinarySearchTreeInsertRange)
    );
    BinarySearchTree->addTest(
        new TestCase(
            "test binary search tree reverse iterator",
            testBinarySearchTreeReverseIterator
        )
    );
    BinarySearchTree->addTest(
        new TestCase(
            "test binary search tree assignement operator",
            testBinarySearchTreeAssignementOperator
        )
    );

    return BinarySearchTree;
}
