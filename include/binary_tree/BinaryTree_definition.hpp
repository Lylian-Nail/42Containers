/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinaryTree_definition.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:53:41 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/04 08:38:46 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_DEFINITION_HPP

# define BINARY_TREE_DEFINITION_HPP

# include <memory>
# include <functional>
# include "utility.hpp"

namespace ft
{
    /*
     * The binary tree class
     * A simple and naive binary tree class
    */

    template <
        class T,
        class Compare = std::less<T>,
        class Alloc = std::allocator<T>
    >
    class BinaryTree
    {
    private:
        class Node;
        template <class Node>
        class in_order_iterator;

    public:
        /*
        * Template base public aliases
        */
        typedef T                                           value_type;
        typedef Compare                                     value_compare;
        typedef Alloc                                       allocator_type;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::pointer            pointer;
        typedef size_t                                      size_type;
        typedef typename allocator_type::const_pointer      const_pointer;

    private:
        typedef typename allocator_type::rebind<Node>::other
                                        node_allocator_type;
        typedef typename node_allocator_type::value_type        node_type;
        typedef typename node_allocator_type::pointer            node_pointer;
        typedef typename node_allocator_type::const_pointer
                                            node_const_pointer;
        typedef typename node_allocator_type::reference          node_reference;
        typedef typename node_allocator_type::const_reference
                                        node_const_reference;

    public:
        typedef in_order_iterator<node_pointer>         iterator;
        typedef in_order_iterator<node_const_pointer>   const_iterator;

        /*
         * Constructors and destructors
        */

        explicit BinaryTree(
            value_compare const &compare = value_compare(),
            allocator_type const &allocator = allocator_type()
        );
        ~BinaryTree();

        /*
         * Getters
        */

        value_compare value_comp() const;
        allocator_type get_allocator() const;
        bool empty() const;
        size_type size() const;
        size_type max_size() const;

        /*
         * Setters
        */

        pair<iterator, bool> insert(const_reference value);
        iterator insert(iterator position, const_reference value);
        void clear();

        /*
         * Iterators
        */

        iterator begin();
        const_iterator begin() const;

        iterator end();
        const_iterator end() const;

    private:
        node_pointer        m_superRoot;
        node_pointer        m_root;
        size_type           m_size;
        value_compare       m_compare;
        allocator_type      m_allocator;
        node_allocator_type m_node_allocator;

        /*
         * Node utilities
        */

        virtual node_pointer create_node(
            const_reference value, node_pointer parent = NULL
        );
        virtual void destroy_node(node_pointer node);
        virtual pair<iterator, bool> insert_node(
            node_pointer root, const_reference value
        );
        virtual void clear_node(node_pointer root);

    };
}
#endif
