/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_binary_tree.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:07:37 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/05 09:50:38 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include "test.hpp"
#include "binary_tree/BinaryTree.hpp"

static int testBinaryTreeDefaultConstructor()
{
    {
        ft::BinaryTree<int> intTree;

        ASSERT(intTree.get_allocator() == std::allocator<int>());
        std::less<int> comp = intTree.value_comp();
        ASSERT(comp(1, 10));
    }
    return 0;
}

static int testBinaryTreeRangeConstructor()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);

        ft::BinaryTree<int> intTree(values, values + arraySize);
        std::sort(values, values + arraySize);
        ft::BinaryTree<int>::iterator first = intTree.begin();
        for (std::size_t i(0); i < arraySize; ++i, ++first)
        {
            ASSERT(*first == values[i]);
        }
        ASSERT(first == intTree.end());
        ASSERT(intTree.size() == arraySize);
    }
    return 0;
}

static int testBinaryTreeCopyConstructor()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);

        ft::BinaryTree<int> intTree(values, values + arraySize);
        ft::BinaryTree<int> copyTree(intTree.begin(), intTree.end());
        ft::BinaryTree<int>::iterator first = intTree.begin();
        ft::BinaryTree<int>::iterator last = intTree.end();
        ft::BinaryTree<int>::iterator copyFirst = copyTree.begin();
        for (; first != last; ++first, ++copyFirst)
        {
            ASSERT(*first == *copyFirst);
        }
        ASSERT(copyFirst == copyTree.end());
        ASSERT(copyTree.size() == intTree.size());
    }
    return 0;
}

static int testBinaryTreeEmpty()
{
    {
        ft::BinaryTree<int> intTree;

        ASSERT(intTree.empty() == true);
    }
    return 0;
}

static int testBinaryTreeSize()
{
    {
        ft::BinaryTree<int> intTree;

        ASSERT(intTree.size() == 0);
    }
    return 0;
}

static int testBinaryTreeMaxSize()
{
    {
        ft::BinaryTree<int> intTree;

        ASSERT(intTree.max_size() == intTree.get_allocator().max_size());
    }
    return 0;
}

static int testBinaryTreeInsertSingleElement()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);
        ft::BinaryTree<int> intTree;
        for (std::size_t i(0); i < arraySize; ++i)
        {
            ft::pair<typename ft::BinaryTree<int>::iterator, bool> r;
            r = intTree.insert(values[i]);
            ASSERT(*r.first == values[i] && r.second == true);
        }

        std::sort(values, values + arraySize);
        ft::BinaryTree<int>::iterator first = intTree.begin();
        for (std::size_t i(0); i < arraySize; ++i, ++first)
        {
            ASSERT(*first == values[i]);
        }
        ASSERT(first == intTree.end());
        ASSERT(intTree.size() == arraySize);

        ft::pair<typename ft::BinaryTree<int>::iterator, bool> r;
        r = intTree.insert(35);
        ASSERT(*r.first == 35 && r.second == false);
    }
    return 0;
}

static int testBinaryTreeInsertWithHint()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);

        ft::BinaryTree<int> intTree;
        ft::BinaryTree<int>::iterator insertedPosition = intTree.begin();
        for (std::size_t i(0); i < arraySize; ++i)
        {
            insertedPosition = intTree.insert(insertedPosition, values[i]);
            ASSERT(*insertedPosition == values[i]);
        }

        std::sort(values, values + arraySize);
        ft::BinaryTree<int>::iterator first = intTree.begin();
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

        ft::BinaryTree<int> intTree;
        ft::BinaryTree<int>::iterator insertedPosition = intTree.begin();
        for (std::size_t i(0); i < arraySize; ++i)
        {
            insertedPosition = intTree.insert(
                insertedPosition, sortedValues[i]
            );
            ASSERT(*insertedPosition == sortedValues[i]);
        }
        ft::BinaryTree<int>::iterator first = intTree.begin();
        for (std::size_t i(0); i < arraySize; ++i, ++first)
        {
            ASSERT(*first == sortedValues[i]);
        }
        ASSERT(first == intTree.end());
        ASSERT(intTree.size() == arraySize);
    }
    return 0;
}

static int testBinaryTreeInsertRange()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);

        ft::BinaryTree<int> intTree;
        intTree.insert(values, values + arraySize);

        std::sort(values, values + arraySize);
        ft::BinaryTree<int>::iterator first = intTree.begin();
        for (std::size_t i(0); i < arraySize; ++i, ++first)
        {
            ASSERT(*first == values[i]);
        }
        ASSERT(first == intTree.end());
        ASSERT(intTree.size() == arraySize);
    }
    return 0;
}

static int testBinaryTreeCount()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);

        ft::BinaryTree<int> intTree(values, values + arraySize);
        ASSERT(intTree.count(42) == 1);
        ASSERT(*intTree.find(10) == 10);
        ASSERT(intTree.count(10) == 1);
        ASSERT(intTree.count(100) == 0);
    }
    {
        ft::BinaryTree<int> intTree;
        ASSERT(intTree.count(42) == 0);
    }
    return 0;
}

static int testBinaryTreeFind()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);

        ft::BinaryTree<int> intTree(values, values + arraySize);
        ft::BinaryTree<int>::iterator found = intTree.find(42);
        ASSERT(*found == 42);
        ASSERT(*intTree.find(24) == 24);
        ASSERT(*intTree.find(101) == 101);
        found = intTree.find(99999);
        ASSERT(found == intTree.end());
    }
    return 0;
}

static int testBinaryTreeLowerBound()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);

        ft::BinaryTree<int> intTree(values, values + arraySize);
        ft::BinaryTree<int>::iterator lowerBound = intTree.lower_bound(12);
        ASSERT(*lowerBound == 24);
        lowerBound = intTree.lower_bound(9);
        ASSERT(*lowerBound == 9);
        lowerBound = intTree.lower_bound(90);
        ASSERT(*lowerBound == 101)
        lowerBound = intTree.lower_bound(80);
        ASSERT(*lowerBound == 89);
    }
    {
        ft::BinaryTree<int> intTree;
        ft::BinaryTree<int>::iterator lowerBound = intTree.lower_bound(42);
        ASSERT(lowerBound == intTree.end());
    }
    return 0;
}

static int testBinaryTreeUpperBound()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);

        ft::BinaryTree<int> intTree(values, values + arraySize);
        ft::BinaryTree<int>::iterator lowerBound = intTree.upper_bound(12);
        ASSERT(*lowerBound == 24);
        lowerBound = intTree.upper_bound(9);
        ASSERT(*lowerBound == 10);
        lowerBound = intTree.upper_bound(90);
        ASSERT(*lowerBound == 101)
        lowerBound = intTree.upper_bound(80);
        ASSERT(*lowerBound == 89);
    }
    {
        ft::BinaryTree<int> intTree;
        ft::BinaryTree<int>::iterator lowerBound = intTree.upper_bound(42);
        ASSERT(lowerBound == intTree.end());
    }
    return 0;
}

static int testBinaryTreeEqualRange()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);

        ft::BinaryTree<int> intTree(values, values + arraySize);
        ft::pair<
            ft::BinaryTree<int>::iterator,
            ft::BinaryTree<int>::iterator
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
        ft::BinaryTree<int> intTree;
        ft::pair<
            ft::BinaryTree<int>::iterator,
            ft::BinaryTree<int>::iterator
        > range = intTree.equal_range(42);
        ASSERT(range.first == intTree.end() && range.second == intTree.end());
    }
    return 0;
}

static int testBinaryTreeReverseIterator()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);

        ft::BinaryTree<int> intTree(values, values + arraySize);
        std::sort(values, values + arraySize);
        ft::BinaryTree<int>::reverse_iterator first = intTree.rbegin();
        ft::BinaryTree<int>::const_reverse_iterator last = intTree.rend();
        int i;
        for (i = arraySize - 1; first != last; ++first, --i)
        {
            ASSERT(*first == i);
        }
        ASSERT(i == 0);
    }
    return 0;
}

static int testBinaryTreeAssignementOperator()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);

        ft::BinaryTree<int> intTree(values, values + arraySize);
        ft::BinaryTree<int> assignedTree;
        assignedTree.insert(99);
        assignedTree = intTree;
        ft::BinaryTree<int>::iterator first = intTree.begin();
        ft::BinaryTree<int>::iterator last = intTree.end();
        ft::BinaryTree<int>::iterator firstCopy = assignedTree.begin();
        for (; first != last; ++first, ++firstCopy)
        {
            ASSERT(*first == *firstCopy);
        }
        ASSERT(intTree.size() == assignedTree.size());
        ASSERT(firstCopy == assignedTree.end());
    }
    return 0;
}

TestSuite *testUnitBinaryTree()
{
    TestSuite *binaryTree = new TestSuite("binary tree");

    binaryTree->addTest(
        new TestCase(
            "test binary tree default contructor",
            testBinaryTreeDefaultConstructor
        )
    );
    binaryTree->addTest(
        new TestCase(
            "test binary tree range constructor",
            testBinaryTreeRangeConstructor
        )
    );
    binaryTree->addTest(
        new TestCase(
            "test binary tree Copy Constructor",
            testBinaryTreeCopyConstructor
        )
    );
    binaryTree->addTest(
        new TestCase("test binary tree empty", testBinaryTreeEmpty)
    );
    binaryTree->addTest(
        new TestCase("test binary tree size", testBinaryTreeSize)
    );
    binaryTree->addTest(
        new TestCase("test binary tree max size", testBinaryTreeMaxSize)
    );
    binaryTree->addTest(
        new TestCase("test binary tree count", testBinaryTreeCount)
    );
    binaryTree->addTest(
        new TestCase("test binary tree find", testBinaryTreeFind)
    );
    binaryTree->addTest(
        new TestCase("test binary tree lower bound", testBinaryTreeLowerBound)
    );
    binaryTree->addTest(
        new TestCase("test binary tree upper bound", testBinaryTreeUpperBound)
    );
    binaryTree->addTest(
        new TestCase("test binary tree equal range", testBinaryTreeEqualRange)
    );
    binaryTree->addTest(
        new TestCase(
            "test binary tree insert single element",
            testBinaryTreeInsertSingleElement
        )
    );
    binaryTree->addTest(
        new TestCase(
            "test binary tree insert with hint",
            testBinaryTreeInsertWithHint
        )
    );
    binaryTree->addTest(
        new TestCase("test binary tree insert range", testBinaryTreeInsertRange)
    );
    binaryTree->addTest(
        new TestCase(
            "test binary tree reverse iterator",
            testBinaryTreeReverseIterator
        )
    );
    binaryTree->addTest(
        new TestCase(
            "test binary tree assignement operator",
            testBinaryTreeAssignementOperator
        )
    );

    return binaryTree;
}
