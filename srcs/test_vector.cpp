/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:24:11 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/31 13:21:26 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <memory>

#ifdef STD

# include <vector>
# include <iostream>
namespace ft = std;

#else

# include "vector.hpp"

#endif

static int testVectorDefaultCtor()
{
    ft::vector<int> vector;

    ASSERT(vector.size() == 0);
    ASSERT(vector.capacity() == 0);
    ASSERT(vector.begin() == vector.end());

    return 0;
}

TestSuite *testUnitVector()
{
    TestSuite *vector = new TestSuite("vector");

    vector->addTest(
        new TestCase("test_vector_default_ctor", testVectorDefaultCtor)
    );

    return vector;
}
