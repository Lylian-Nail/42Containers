/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:47:20 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/22 12:48:30 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP

# define ALGORITHM_HPP

namespace ft
{

    template <class T>
    void swap(T &a, T &b)
    {
        T c(a);
        a = b;
        b = c;
    }

};

#endif
