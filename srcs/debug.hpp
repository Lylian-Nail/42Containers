/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:53:41 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/11 21:33:13 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_HPP

# define DEBUG_HPP

# include "binary_trees/BinarySearchTree.hpp"
# include <iostream>

namespace ft
{
    template <class T2, class Compare2, class Alloc2>
    static bool print_level(
        typename ft::BinarySearchTree<
            T2, Compare2, Alloc2
        >::node_pointer const root,
        int level
    )
    {
        if (root == NULL)
            return false;
        
        if (level == 1)
        {
            std::cout << root->data << " ";
            return true;
        }
        bool left = print_level<T2, Compare2, Alloc2>(
            root->leftChild, level - 1
        );
        bool right = print_level<T2, Compare2, Alloc2>(
            root->rightChild, level - 1
        );
        return left || right;
    }

    template <class T2, class Compare2, class Alloc2>
    void debug_tree(ft::BinarySearchTree<T2, Compare2, Alloc2> const &bst)
    {
        int level = 1;
        while (print_level<T2, Compare2, Alloc2>(bst.m_root, level))
        {
            std::cout << std::endl;
            ++level;
        }
    }

    void debug_all();
}

#endif
