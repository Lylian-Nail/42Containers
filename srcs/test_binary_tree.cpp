/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_binary_tree.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:07:37 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/28 16:27:15 by lperson-         ###   ########.fr       */
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

static int testBinaryTreeNodeConstructor()
{
    {
        ft::BinaryTree<int>::Node intNode(42);

        ASSERT(intNode.getData() == 42);
        ASSERT(intNode.getParent() == NULL);
        ASSERT(intNode.getLeftChild() == NULL);
        ASSERT(intNode.getRightChild() == NULL);
    }
    {
        ft::BinaryTree<std::string>::Node stringNode("Hello, World");

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
        ft::BinaryTree<int>::Node intNode(42);
        ft::BinaryTree<int>::Node intNodeCopy(intNode);

        ASSERT(intNodeCopy.getData() == intNode.getData());
        ASSERT(intNodeCopy.getParent() == intNode.getParent());
        ASSERT(intNodeCopy.getLeftChild() == intNode.getLeftChild());
        ASSERT(intNodeCopy.getRightChild() == intNode.getRightChild());
    }
    {
        ft::BinaryTree<std::string>::Node stringNodeEmpty;
        ft::BinaryTree<std::string>::Node stringNodeCopy(stringNodeEmpty);

        ASSERT(stringNodeEmpty.getData() == stringNodeCopy.getData());
        ASSERT(stringNodeEmpty.getParent() == stringNodeCopy.getParent());
        ASSERT(stringNodeEmpty.getLeftChild() == stringNodeCopy.getLeftChild());
        ASSERT(
            stringNodeEmpty.getRightChild() == stringNodeCopy.getRightChild()
        );
    }
    {
        ft::BinaryTree<int>::Node const intNode(42);
        ft::BinaryTree<int>::Node const intNodeCopy(intNode);

        ASSERT(intNodeCopy.getData() == intNode.getData());
        ASSERT(intNodeCopy.getParent() == intNode.getParent());
        ASSERT(intNodeCopy.getLeftChild() == intNode.getLeftChild());
        ASSERT(intNodeCopy.getRightChild() == intNode.getRightChild());
    }
    return 0;
}

static int testBinaryTreeNodeAssignementOperator()
{
    {
        ft::BinaryTree<int>::Node intNode(42);
        ft::BinaryTree<int>::Node intNodeCopy(intNode);

        ASSERT(intNodeCopy.getData() == intNode.getData());
        ASSERT(intNodeCopy.getParent() == intNode.getParent());
        ASSERT(intNodeCopy.getLeftChild() == intNode.getLeftChild());
        ASSERT(intNodeCopy.getRightChild() == intNode.getRightChild());
    }
    {
        ft::BinaryTree<int>::Node const intNode(42);
        ft::BinaryTree<int>::Node const intNodeCopy(intNode);

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
    binaryTree->addTest(
        new TestCase(
            "test binary tree node assignement operator",
            testBinaryTreeNodeAssignementOperator
        )
    );
    binaryTree->addTest(
        new TestCase(
            "test binary tree contructor",
            testBinaryTreeConstructor
        )
    );

    return binaryTree;
}
