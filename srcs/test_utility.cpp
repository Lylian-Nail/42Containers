/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utility.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 07:46:18 by lperson-          #+#    #+#             */
/*   Updated: 2022/03/28 08:03:15 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

#ifdef STD
    namespace ft = std;
    # include <utility>
# else
    # include "utility.hpp"
#endif

static int testPairDefaultConstructor()
{
    {
        ft::pair<bool, int> pair;
    }
    return 0;
}

static int testPairCopyConstructor()
{
    {
        ft::pair<bool, int> pair;
        pair.first = true;
        pair.second = 42;

        ft::pair<bool, int> copyPair(pair);
        ASSERT(pair.first == copyPair.first);
        ASSERT(pair.second == copyPair.second);
    }
    return 0;
}

static int testPairInitializationConstructor()
{
    {
        ft::pair<bool, int> pair(true, 42);

        ASSERT(pair.first == true);
        ASSERT(pair.second == 42);
    }
    return 0;
}

TestSuite *testUnitUtility()
{
    TestSuite *utility = new TestSuite("utility");

    utility->addTest(
        new TestCase(
            "test pair default constructor", testPairDefaultConstructor
        )
    );
    utility->addTest(
        new TestCase("test pair copy constructor", testPairCopyConstructor)
    );
    utility->addTest(
        new TestCase(
            "test pair initialization constructor",
            testPairInitializationConstructor
        )
    );

    return utility;
}
