/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_binary_tree.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:07:37 by lperson-          #+#    #+#             */
/*   Updated: 2022/03/20 19:07:13 by lperson-         ###   ########.fr       */
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

TestSuite *testUnitBinaryTree()
{
    TestSuite *binaryTree = new TestSuite("binary tree");

    binaryTree->addTest(
        new TestCase(
            "test binary tree contructor",
            testBinaryTreeConstructor
        )
    );

    return binaryTree;
}
