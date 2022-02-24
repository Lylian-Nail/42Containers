/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_implementation.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:37:48 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/24 11:23:18 by lperson-         ###   ########.fr       */
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

};