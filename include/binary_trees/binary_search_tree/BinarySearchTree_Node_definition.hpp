/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree_Node_definition.hpp               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:22:40 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/05 11:13:10 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_NODE_DEFINITION_HPP

# define BINARY_SEARCH_TREE_NODE_DEFINITION_HPP

namespace ft
{
    /*
    * Create binary search tree Node class
    * that contains data and pointer to parent, left child and right child.
    *
    * A node can be inserted in a tree,
    * it can be also a root or a leaf.
    * 
    * Node have to be allocated with correct allocator.
    */

    template <class T, class Compare, class Alloc>
    class BinarySearchTree<T, Compare, Alloc>::Node
    {
    public:
        /*
        * Constructors and destructors
        */

        Node();
        explicit Node(const_reference data, node_pointer parent = NULL);
        Node(Node const &copy);
        ~Node();

        /*
        * Assignement
        */

        Node &operator=(Node const &rhs);

        value_type  data;
        Node *      parent;
        Node *      leftChild;
        Node *      rightChild;
    };
}

#endif
