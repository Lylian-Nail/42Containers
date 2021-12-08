/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_type_traits.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:23:22 by lperson-          #+#    #+#             */
/*   Updated: 2021/12/08 12:46:10 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <type_traits.hpp>

static void test_integral_constant()
{
    ft::integral_constant<int, 42> value;

    std::cout << "Test integral constant: " << std::endl;
    std::cout << value << std::endl;
    std::cout << value() << std::endl;
    std::cout << ft::integral_constant<int, 42>::value << std::endl;
    std::cout << ft::integral_constant<int, 42>() << std::endl;

    std::cout << std::endl;
}

static void test_true_type()
{
    ft::true_type   value;

    std::cout << "Test true type" << std::endl;

    std::cout << value << std::endl;
    std::cout << value() << std::endl;
    std::cout << ft::true_type() << std::endl;

    std::cout << std::endl;
}

static void test_false_type()
{
    ft::false_type   value;

    std::cout << "Test false type" << std::endl;

    std::cout << value << std::endl;
    std::cout << value() << std::endl;
    std::cout << (bool)ft::false_type() << std::endl;

    std::cout << std::endl;
}

static void test_base_type_traits()
{
    test_integral_constant();
    test_true_type();
    test_false_type();
}

void test_type_traits()
{
    test_base_type_traits();
}
