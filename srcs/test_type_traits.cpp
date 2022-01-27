/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_type_traits.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:23:22 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/27 12:38:30 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <type_traits.hpp>
#include "test.hpp"

static int test_integral_constant()
{
    ft::integral_constant<int, 42> value;

    ASSERT(value == 42);
    ASSERT(value() == 42);
    ASSERT((ft::integral_constant<int, 42>::value) == 42);
    ASSERT((ft::integral_constant<int, 42>()) == 42);

    return 0;
}

static int test_true_type()
{
    ft::true_type   value;

    ASSERT(ft::true_type() == true);
    ASSERT(value == true);
    ASSERT(value() == true);

    return 0;
}

static int test_false_type()
{
    ft::false_type   value;

    ASSERT(value == false);
    ASSERT(value() == false);
    ASSERT(ft::false_type() == false);

    return 0;
}

static int test_is_same()
{
    ASSERT((ft::is_same<bool, bool>()) == true);
    ASSERT((ft::is_same<bool, bool const>()) == false);
    ASSERT((ft::is_same<int, bool>()) == false);

    return 0;
}

static int test_remove_const()
{
    ASSERT(
        (ft::is_same<bool, ft::remove_const<bool>::type>()) == true
    );
    ASSERT(
        (ft::is_same<bool, ft::remove_const<bool const>::type>()) == true
    );
    ASSERT(
        (ft::is_same<bool const*, ft::remove_const<bool const *const >::type>())
            == true
    );

    return 0;
}

static int test_remove_cv()
{
    ASSERT(
        (ft::is_same<bool, ft::remove_cv<bool>::type>()) == true
    );
    ASSERT(
        (ft::is_same<bool, ft::remove_cv<bool const>::type>()) == true
    );
    ASSERT(
        (ft::is_same<bool const *, ft::remove_cv<bool const *const>::type>())
            == true
    );
    ASSERT(
        (ft::is_same<bool, ft::remove_cv<volatile bool>::type>()) == true
    );
    ASSERT(
        (ft::is_same<bool, ft::remove_cv<volatile const bool>::type>()) == true
    );
    ASSERT(
        (ft::is_same<bool volatile *, 
         ft::remove_cv<bool volatile * volatile>::type>()) == true
    );
    ASSERT(
        (ft::is_same<volatile bool const *,
         ft::remove_cv<volatile bool const *const volatile>::type>()) == true
    );
    return 0;
}

TestSuite *testUnitTypeTraits()
{
    TestSuite *typeTraits = new TestSuite("type_traits");

    typeTraits->addTest(
        new TestCase("test_integral_constant", test_integral_constant)
    );
    typeTraits->addTest(
        new TestCase("test_true_type", test_true_type)
    );
    typeTraits->addTest(
        new TestCase("test_false_type", test_false_type)
    );
    typeTraits->addTest(
        new TestCase("test_is_same", test_is_same)
    );
    typeTraits->addTest(
        new TestCase("test_remove_const", test_remove_const)
    );
    typeTraits->addTest(
        new TestCase("test_remove_vc", test_remove_cv)
    );

    return typeTraits;
}
