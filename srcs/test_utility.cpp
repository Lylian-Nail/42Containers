/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utility.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 07:46:18 by lperson-          #+#    #+#             */
/*   Updated: 2022/03/28 09:25:08 by lperson-         ###   ########.fr       */
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
    {
        ft::pair<bool, std::string> pair;
        ASSERT(pair.second.length() == 0);
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
    {
        ft::pair <bool, int> const pair(true, 42);

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

static int testPairOperatorCopyAssignement()
{
    {
        ft::pair<bool, int> pair(true, 42);

        ft::pair<bool, int> pairAssignement(false, 24);
        pairAssignement = pair;

        ASSERT(pair.first == pairAssignement.first);
        ASSERT(pair.second == pairAssignement.second)
    }
    return 0;
}

static int testPairEqualityOperator()
{
    {
        ft::pair<bool, int> pair(true, 42);
        ft::pair<bool, int> copyPair(pair);

        ASSERT(pair == copyPair);
    }
    {
        ft::pair<bool, int> pair(true, 42);
        ft::pair<bool, int> otherPair(false, 24);

        ASSERT(!(pair == otherPair));
    }
    {
        ft::pair<bool, int> pair(true, 42);
        ft::pair<bool, int> otherPair(true, 24);

        ASSERT(!(pair == otherPair));
    }
    {
        ft::pair<bool, int> const pair(true, 42);
        ft::pair<bool, int> copyPair(pair);

        ASSERT(pair == copyPair);
    }
    return 0;
}

static int testPairDifferenceOperator()
{
    {
        ft::pair<bool, int> pair(true, 42);
        ft::pair<bool, int> copyPair(pair);

        ASSERT(!(pair != copyPair));
    }
    {
        ft::pair<bool, int> pair(true, 42);
        ft::pair<bool, int> otherPair(false, 24);

        ASSERT(pair != otherPair);
    }
    {
        ft::pair<bool, int> pair(true, 42);
        ft::pair<bool, int> otherPair(true, 24);

        ASSERT(pair != otherPair);
    }
    {
        ft::pair<bool, int> const pair(true, 42);
        ft::pair<bool, int> copyPair(pair);
        copyPair.second = 24;

        ASSERT(pair != copyPair);
    }
    return 0;
}

static int testPairLessThanOperator()
{
    {
        ft::pair<int, int> pair(24, 42);
        ft::pair<int, int> otherPair(24, 24);

        ASSERT(otherPair < pair);
    }
    {
        ft::pair<int, int> pair(21, 42);
        ft::pair<int, int> otherPair(24, 42);

        ASSERT(pair < otherPair);
    }
    {
        ft::pair<int, int> const pair(24, 42);
        ft::pair<int, int> otherPair(24, 24);

        ASSERT(otherPair < pair);
    }
    return 0;
}

static int testPairLessThanOrEqualOperator()
{
        {
        ft::pair<int, int> pair(24, 42);
        ft::pair<int, int> otherPair(24, 24);

        ASSERT(otherPair < pair);
    }
    {
        ft::pair<int, int> pair(21, 42);
        ft::pair<int, int> otherPair(24, 42);

        ASSERT(pair < otherPair);
    }
    {
        ft::pair<int, int> const pair(24, 42);
        ft::pair<int, int> otherPair(24, 24);

        ASSERT(otherPair < pair);
    }
    {
        ft::pair<int, int> pair(21, 42);
        ft::pair<int, int> copyPair(pair);

        ASSERT(pair <= copyPair);
    }
    return 0;
}

static int testPairMoreThanOperator()
{
    {
        ft::pair<int, int> pair(24, 42);
        ft::pair<int, int> otherPair(24, 24);

        ASSERT(pair > otherPair);
    }
    {
        ft::pair<int, int> pair(21, 42);
        ft::pair<int, int> otherPair(24, 42);

        ASSERT(otherPair > pair);
    }
    {
        ft::pair<int, int> const pair(24, 42);
        ft::pair<int, int> otherPair(24, 24);

        ASSERT(pair > otherPair);
    }
    return 0;
}

static int testMoreThanOrEqualOperator()
{
    {
        ft::pair<int, int> pair(24, 42);
        ft::pair<int, int> otherPair(24, 24);

        ASSERT(pair > otherPair);
    }
    {
        ft::pair<int, int> pair(21, 42);
        ft::pair<int, int> otherPair(24, 42);

        ASSERT(otherPair > pair);
    }
    {
        ft::pair<int, int> const pair(24, 42);
        ft::pair<int, int> otherPair(24, 24);

        ASSERT(pair > otherPair);
    }
    {
        ft::pair<int, int> const pair(24, 42);
        ft::pair<int, int> copyPair(pair);

        ASSERT(pair >= copyPair);
    }
    return 0;
}

static int testMakePair()
{
    {
        ft::pair<int, int> pair;

        pair = ft::make_pair(21, 42);
        ASSERT(pair.first == 21 && pair.second == 42);
    }
    {
        ft::pair<int, int> pair;

        pair = ft::make_pair(21.5, 42.5);
        ASSERT(pair.first == 21 && pair.second == 42);
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
    utility->addTest(
        new TestCase(
            "test pair operator copy assignement",
            testPairOperatorCopyAssignement
        )
    );
    utility->addTest(
        new TestCase("test pair equality operator", testPairEqualityOperator)
    );
    utility->addTest(
        new TestCase(
            "test pair difference operator",
            testPairDifferenceOperator
        )
    );
    utility->addTest(
        new TestCase("test pair less than operator", testPairLessThanOperator)
    );
    utility->addTest(
        new TestCase(
            "test pair less than or equal operator",
            testPairLessThanOrEqualOperator
        )
    );
    utility->addTest(
        new TestCase("test pair more than operator", testPairMoreThanOperator)
    );
    utility->addTest(
        new TestCase(
            "test pair more than or equal operator",
            testMoreThanOrEqualOperator
        )
    );
    utility->addTest(
        new TestCase("test make pair", testMakePair)
    );

    return utility;
}