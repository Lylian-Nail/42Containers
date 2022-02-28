/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_binary_tree.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:07:37 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/28 11:50:45 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "binary_tree/BinaryTree.hpp"

static int testBinaryTreeNodeConstructor()
{
    {
        ft::BinaryTreeNode<int> intNode(42);

        ASSERT(intNode.getData() == 42);
        ASSERT(intNode.getParent() == NULL);
        ASSERT(intNode.getLeftChild() == NULL);
        ASSERT(intNode.getRightChild() == NULL);
    }
    {
        ft::BinaryTreeNode<std::string> stringNode("Hello, World");

        ASSERT(stringNode.getData().compare("Hello, World") == 0);
        ASSERT(stringNode.getParent() == NULL);
        ASSERT(stringNode.getLeftChild() == NULL);
        ASSERT(stringNode.getRightChild() == NULL);
    }
    return 0;
}

static int testBinaryTreeNodeCopyConstructor()
{
    {
        ft::BinaryTreeNode<int> intNode(42);
        ft::BinaryTreeNode<int> intNodeCopy(intNode);

        ASSERT(intNodeCopy.getData() == intNode.getData());
        ASSERT(intNodeCopy.getParent() == intNode.getParent());
        ASSERT(intNodeCopy.getLeftChild() == intNode.getLeftChild());
        ASSERT(intNodeCopy.getRightChild() == intNode.getRightChild());
    }
    {
        ft::BinaryTreeNode<std::string> stringNodeEmpty;
        ft::BinaryTreeNode<std::string> stringNodeCopy(stringNodeEmpty);

        ASSERT(stringNodeEmpty.getData() == stringNodeCopy.getData());
        ASSERT(stringNodeEmpty.getParent() == stringNodeCopy.getParent());
        ASSERT(stringNodeEmpty.getLeftChild() == stringNodeCopy.getLeftChild());
        ASSERT(
            stringNodeEmpty.getRightChild() == stringNodeCopy.getRightChild()
        );
    }
    {
        ft::BinaryTreeNode<int> const intNode(42);
        ft::BinaryTreeNode<int> const intNodeCopy(intNode);

        ASSERT(intNodeCopy.getData() == intNode.getData());
        ASSERT(intNodeCopy.getParent() == intNode.getParent());
        ASSERT(intNodeCopy.getLeftChild() == intNode.getLeftChild());
        ASSERT(intNodeCopy.getRightChild() == intNode.getRightChild());
    }
    return 0;
}

TestSuite *testUnitBinaryTree()
{
    TestSuite *binaryTree = new TestSuite("binary tree");

    binaryTree->addTest(
        new TestCase(
            "test binary tree node constructor",
            testBinaryTreeNodeConstructor
        )
    );
    binaryTree->addTest(
        new TestCase(
            "test binary tree node copy constructor",
            testBinaryTreeNodeCopyConstructor
        )
    );

    return binaryTree;
}
