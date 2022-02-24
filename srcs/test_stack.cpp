/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:43:48 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/24 10:57:24 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

#ifdef STD

# include <stack>
namespace ft = std;

#else

# include "stack.hpp"

#endif

# include <iostream>

static int testStackDefaultConstructor()
{
    {
        ft::stack<int> emptyStack();
    }

    {
        ft::vector<int> vectorOfInt(1000, 42);
        ft::stack<int, ft::vector<int> > stackOfInt(vectorOfInt);
    }

    return 0;
}

TestSuite *testUnitStack()
{
    TestSuite *stack = new TestSuite("stack");

    stack->addTest(new TestCase(
        "test_stack_default_constructor", testStackDefaultConstructor
    ));

    return stack;
}
