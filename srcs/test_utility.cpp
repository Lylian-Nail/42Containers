/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utility.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 07:46:18 by lperson-          #+#    #+#             */
/*   Updated: 2022/03/28 07:59:17 by lperson-         ###   ########.fr       */
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

    return utility;
}
