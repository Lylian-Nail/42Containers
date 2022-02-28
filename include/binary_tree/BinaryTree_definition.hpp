/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinaryTree_definition.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:53:41 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/28 11:54:01 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_DEFINITION_HPP

# define BINARY_TREE_DEFINITION_HPP

# include <memory>
# include <functional>

namespace ft
{

    /*
     * Create Binary Tree Node class
     * that contains data and pointer to parent, left child and right child.
     * 
     * A node can be inserted in a tree,
     * it can be also a root or a leaf.
     * 
     * Node have to be allocated with correct allocator.
    */

    template <class T>
    class BinaryTreeNode
    {
    public:
        /*
         * Template aliases
        */

        typedef T                                           value_type;
        typedef T &                                         reference;
        typedef T const &                                   const_reference;
        typedef T *                                         pointer;
        typedef T const *                                   const_pointer;

        /*
         * Constructors and destructors
        */

        BinaryTreeNode();
        explicit BinaryTreeNode(const_reference data);
        BinaryTreeNode(BinaryTreeNode const &copy);
        ~BinaryTreeNode();

        /*
         * Getters
        */

        const_reference getData() const;
        pointer         getParent() const;
        pointer         getLeftChild() const;
        pointer         getRightChild() const;

        /*
         * Assignement
        */

        BinaryTreeNode &operator=(BinaryTreeNode const &rhs);

    private:
        value_type      m_data;
        pointer         m_parent;
        pointer         m_leftChild;
        pointer         m_rightChild;

    };

}

#endif
