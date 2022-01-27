/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:24:11 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/27 13:25:48 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "test.hpp"

TestSuite *testUnitVector()
{
    TestSuite *vector = new TestSuite("vector");

    return vector;
}
