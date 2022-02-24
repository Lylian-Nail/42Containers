/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_implementation.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:37:48 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/24 11:08:27 by lperson-         ###   ########.fr       */
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

};