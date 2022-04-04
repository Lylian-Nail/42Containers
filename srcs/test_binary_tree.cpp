/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_binary_tree.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:07:37 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/04 09:11:54 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include "test.hpp"
#include "binary_tree/BinaryTree.hpp"

static int testBinaryTreeConstructor()
{
    {
        ft::BinaryTree<int> intTree;

        ASSERT(intTree.get_allocator() == std::allocator<int>());
        std::less<int> comp = intTree.value_comp();
        ASSERT(comp(1, 10));
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
            ASSERT(r.first->data == values[i] && r.second == true);
        }

        std::sort(values, values + arraySize);
        ft::BinaryTree<int>::iterator first = intTree.begin();
        for (std::size_t i(0); i < arraySize; ++i, ++first)
        {
            ASSERT(first->data == values[i]);
        }
        ASSERT(first == intTree.end());
        ASSERT(intTree.size() == arraySize);

        ft::pair<typename ft::BinaryTree<int>::iterator, bool> r;
        r = intTree.insert(35);
        ASSERT(r.first->data == 35 && r.second == false);
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
            ASSERT(insertedPosition->data == values[i]);
        }

        std::sort(values, values + arraySize);
        ft::BinaryTree<int>::iterator first = intTree.begin();
        for (std::size_t i(0); i < arraySize; ++i, ++first)
        {
            ASSERT(first->data == values[i]);
        }
        ASSERT(first == intTree.end());
        ASSERT(intTree.size() == arraySize);

        insertedPosition = intTree.insert(intTree.begin(), 35);
        ASSERT(insertedPosition->data == 35);
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
            ASSERT(insertedPosition->data == sortedValues[i]);
        }
        ft::BinaryTree<int>::iterator first = intTree.begin();
        for (std::size_t i(0); i < arraySize; ++i, ++first)
        {
            ASSERT(first->data == sortedValues[i]);
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
            ASSERT(first->data == values[i]);
        }
        ASSERT(first == intTree.end());
        ASSERT(intTree.size() == arraySize);
    }
    return 0;
}

TestSuite *testUnitBinaryTree()
{
    TestSuite *binaryTree = new TestSuite("binary tree");

    binaryTree->addTest(
        new TestCase("test binary tree contructor", testBinaryTreeConstructor)
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

    return binaryTree;
}
