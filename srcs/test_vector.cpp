/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:24:11 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/31 13:52:12 by lperson-         ###   ########.fr       */
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

static int testVectorFillCtor()
{
    ft::vector<std::string> vector(10, "Hey");

    ASSERT(vector.size() == 10);
    ASSERT(vector.capacity() == 10);
    ft::vector<std::string>::const_iterator itBegin(vector.begin());
    ft::vector<std::string>::const_iterator itEnd(vector.end());
    for (; itBegin != itEnd; itBegin++)
        ASSERT(itBegin->compare("Hey") == 0);

    return 0;
}

TestSuite *testUnitVector()
{
    TestSuite *vector = new TestSuite("vector");

    vector->addTest(
        new TestCase("test_vector_default_ctor", testVectorDefaultCtor)
    );
    vector->addTest(
        new TestCase("test_vector_fill_ctor", testVectorFillCtor)
    );

    return vector;
}
