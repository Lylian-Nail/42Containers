/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_implementation.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:37:48 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/24 10:59:15 by lperson-         ###   ########.fr       */
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

};