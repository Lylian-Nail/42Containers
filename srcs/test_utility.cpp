/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utility.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 07:46:18 by lperson-          #+#    #+#             */
/*   Updated: 2022/03/28 07:53:21 by lperson-         ###   ########.fr       */
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

TestSuite *testUnitUtility()
{
    TestSuite *utility = new TestSuite("utility");

    utility->addTest(
        new TestCase(
            "test pair default constructor", testPairDefaultConstructor
        )
    );

    return utility;
}
