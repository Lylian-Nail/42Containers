/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_implementation.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:37:48 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/24 13:03:30 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{

    /*
     * Constructor and destructor
    */

    template <class T, class Container>
    stack<T, Container>::stack(container_type const &container):
        m_container(container)
    {
    }

    template <class T, class Container>
    stack<T, Container>::~stack()
    {
    }

    /*
     * Getters
    */

    template <class T, class Container>
    typename stack<T, Container>::size_type stack<T, Container>::size() const
    {
        return m_container.size();
    }

    template <class T, class Container>
    bool stack<T, Container>::empty() const
    {
        return m_container.empty();
    }

    template <class T, class Container>
    typename stack<T, Container>::value_type const &
    stack<T, Container>::top() const
    {
        return m_container.back();
    }

    /*
     * Setters
    */

    template <class T, class Container>
    typename stack<T, Container>::value_type &stack<T, Container>::top()
    {
        return m_container.back();
    }

    template <class T, class Container>
    void stack<T, Container>::push(value_type const &value)
    {
        m_container.push_back(value);
    }

    template <class T, class Container>
    void stack<T, Container>::pop()
    {
        m_container.pop_back();
    }


    /*
     * Non-members relationnal operators
    */

    template <class T1, class Container1>
    bool operator==(
        stack<T1, Container1> const &lhs, stack<T1, Container1> const &rhs
    )
    {
        return lhs.m_container == rhs.m_container;
    }

    template <class T1, class Container1>
    bool operator!=(
        stack<T1, Container1> const &lhs, stack<T1, Container1> const &rhs
    )
    {
        return lhs.m_container != rhs.m_container;
    }

};