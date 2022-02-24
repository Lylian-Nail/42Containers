/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:43:48 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/24 12:46:39 by lperson-         ###   ########.fr       */
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

static int testStackPush()
{
    {
        ft::stack<int> stackEmpty;

        stackEmpty.push(24);
        ASSERT(stackEmpty.top() == 24);
        ASSERT(stackEmpty.size() == 1);
        stackEmpty.push(42);
        ASSERT(stackEmpty.top() == 42);
        ASSERT(stackEmpty.size() == 2);
    }
    {
        ft::vector<int> vectorOfInts(100, 42);
        ft::stack<int, ft::vector<int> > stackOfInts(vectorOfInts);

        ASSERT(stackOfInts.top() == 42);
        stackOfInts.push(24);
        ASSERT(stackOfInts.top() == 24);
    }
    return 0;
}

static int testStackPop()
{
    {
        ft::stack<int> stackEmpty;

        stackEmpty.push(23);
        ASSERT(!stackEmpty.empty());
        stackEmpty.pop();
        ASSERT(stackEmpty.empty());
    }
    {
        ft::vector<int> vectorOfInts(24, 42);
        vectorOfInts.back() = 24;
        ft::stack<int, ft::vector<int> > stackOfInts(vectorOfInts);

        ASSERT(stackOfInts.top() == 24);
        ASSERT(stackOfInts.size() == vectorOfInts.size());
        stackOfInts.pop();
        ASSERT(stackOfInts.top() == 42);
        ASSERT(stackOfInts.size() == vectorOfInts.size() - 1);
    }
    return 0;
}

int testStackEqualityOperator()
{
    {
        ft::stack<int> emptyStack;
        ft::stack<int> emptyStackToo;

        ASSERT(emptyStack == emptyStackToo);
    }
    {
        ft::vector<int> vectorOfInts(24, 42);
        ft::stack<int, ft::vector<int> > stackOfInts(vectorOfInts);
        ft::stack<int, ft::vector<int> > stackOfIntsToo(vectorOfInts);

        ASSERT(stackOfInts == stackOfIntsToo);
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
    stack->addTest(
        new TestCase("test_stack_push", testStackPush)
    );
    stack->addTest(
        new TestCase("test_stack_pop", testStackPop)
    );
    stack->addTest(
        new TestCase("test_stack_equality_operator", testStackEqualityOperator)
    );

    return stack;
}
