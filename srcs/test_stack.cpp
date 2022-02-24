/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:43:48 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/24 11:08:17 by lperson-         ###   ########.fr       */
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
        ft::stack<int> emptyStack;
    }

    {
        ft::vector<int> vectorOfInt(1000, 42);
        ft::stack<int, ft::vector<int> > stackOfInt(vectorOfInt);
    }

    return 0;
}

static int testStackSize()
{
    {
        ft::stack<int> emptyStack;

        ASSERT(emptyStack.size() == 0);
    }
    {
        ft::vector<int> vectorOfInts(100000, 42);
        ft::stack<int, ft::vector<int> > stackOfInts(vectorOfInts);

        ASSERT(vectorOfInts.size() == stackOfInts.size());
    }
    return 0;
}

TestSuite *testUnitStack()
{
    TestSuite *stack = new TestSuite("stack");

    stack->addTest(
        new TestCase(
            "test_stack_default_constructor", testStackDefaultConstructor
        )
    );
    stack->addTest(
        new TestCase("test_stack_size", testStackSize)
    );

    return stack;
}
