/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:07:05 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/11 21:21:51 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.hpp"

void ft::debug_all()
{
    int values[] = {42, 24, 70, 35, 89, 101, 8, 9, 10};
    std::size_t arraySize = sizeof(values) / sizeof(values[0]);
    ft::BinarySearchTree<int> intTree(values, values + arraySize);

    debug_tree(intTree);
}
