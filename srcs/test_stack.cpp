/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:43:48 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/24 11:22:35 by lperson-         ###   ########.fr       */
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

static int testStackEmpty()
{
    {
        ft::stack<int> emptyStack;

        ASSERT(emptyStack.empty());
    }
    {
        ft::vector<int> vectorOfInts(10000, 42);
        ft::stack<int, ft::vector<int> > stackOfInts(vectorOfInts);

        ASSERT(!stackOfInts.empty());
    }
    return 0;
}

static int testStackTop()
{
    {
        ft::vector<int> vectorOfInts(10, 42);
        vectorOfInts.back() = 24;
        ft::stack<int, ft::vector<int> > stackOfInts(vectorOfInts);

        ASSERT(stackOfInts.top() == 24);
        stackOfInts.top() = 42;
        ASSERT(stackOfInts.top() == 42);
    }
    {
        ft::vector<int> const vectorOfInts(10, 42);
        ft::stack<int, ft::vector<int> > const stackOfInts(vectorOfInts);

        ASSERT(stackOfInts.top() == 42);
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
    stack->addTest(
        new TestCase("test_stack_empty", testStackEmpty)
    );
    stack->addTest(
        new TestCase("test_stack_top", testStackTop)
    );

    return stack;
}
