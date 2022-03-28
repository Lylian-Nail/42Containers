/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_binary_tree.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:07:37 by lperson-          #+#    #+#             */
/*   Updated: 2022/03/28 07:25:31 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

TestSuite *testUnitBinaryTree()
{
    TestSuite *binaryTree = new TestSuite("binary tree");

    binaryTree->addTest(
        new TestCase(
            "test binary tree contructor",
            testBinaryTreeConstructor
        )
    );
    binaryTree->addTest(
        new TestCase("test binary tree empty", testBinaryTreeEmpty)
    );
    binaryTree->addTest(
        new TestCase("test binary tree size", testBinaryTreeSize)
    );

    return binaryTree;
}
