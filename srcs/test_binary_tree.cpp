/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_binary_tree.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:07:37 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/04 14:13:21 by lperson-         ###   ########.fr       */
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

static int testBinaryTreeFind()
{
    {
        int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
        std::size_t arraySize = sizeof(values) / sizeof(values[0]);

        ft::BinaryTree<int> intTree(values, values + arraySize);
        ft::BinaryTree<int>::iterator found = intTree.find(42);
        ASSERT(*found == 42);
        found = intTree.find(99999);
        ASSERT(found == intTree.end());
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
        new TestCase("test binary tree find", testBinaryTreeFind)
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
            "test binary tree assignement operator",
            testBinaryTreeAssignementOperator
        )
    );

    return binaryTree;
}
