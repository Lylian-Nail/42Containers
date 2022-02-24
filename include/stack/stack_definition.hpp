/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_definition.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:41:08 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/24 13:20:07 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_DEFINITION_HPP

# define STACK_DEFINITION_HPP

# include "vector.hpp"

namespace ft
{

    template <class T, class Container = vector<T> >
    class stack
    {
    public:
        /*
         Typedef members
        */

        typedef T value_type;
        typedef Container container_type;
        typedef size_t size_type;

        /*
         * Constructors and destructors
         */

        explicit stack(container_type const &container = container_type());
        ~stack();

        /*
         * Getters
        */

        size_type size() const;
        bool empty() const;
        value_type const &top() const;

        /*
         * Setters
        */

        value_type &top();
        void push(value_type const &value);
        void pop();

        /*
        * Non-members relationnal operators
        */

        template <class T1, class Container1>
        friend bool operator==(
            stack<T1, Container1> const &lhs, stack<T1, Container1> const &rhs
        );

        template <class T1, class Container1>
        friend bool operator!=(
            stack<T1, Container1> const &lhs, stack<T1, Container1> const &rhs
        );

        template <class T1, class Container1>
        friend bool operator<(
            stack<T1, Container1> const &lhs, stack<T1, Container1> const &rhs
        );

        template <class T1, class Container1>
        friend bool operator<=(
            stack<T1, Container1> const &lhs, stack<T1, Container1> const &rhs
        );

        template <class T1, class Container1>
        friend bool operator>(
            stack<T1, Container1> const &lhs, stack<T1, Container1> const &rhs
        );

    private:
        container_type m_container;

    };

};

#endif
