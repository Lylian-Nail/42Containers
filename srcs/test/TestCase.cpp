/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestCase.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:54:29 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/26 12:43:07 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "test/TestCase.hpp"
#include "test/ansii_color.hpp"

TestCase::TestCase():
    m_name(),
    m_test(),
    m_result()
{
}

TestCase::TestCase(std::string const &name, testF test):
    m_name(name),
    m_test(test),
    m_result(0)
{
}

TestCase::TestCase(TestCase const &copy):
    m_name(copy.getName()),
    m_test(copy.m_test),
    m_result(copy.getResult())
{
}

TestCase::~TestCase()
{
}

std::string const &TestCase::getName() const
{
    return m_name;
}

int TestCase::getResult() const
{
    return m_result;
}

int TestCase::run()
{
    std::cout << "Testing: " BWHT << m_name << RST << std::endl;
    m_result = m_test();
    if (m_result)
        std::cout << BWHT << m_name << ": " BRED << "failed!" RST << std::endl;
    else
        std::cout << BWHT << m_name << ": " BGRN << "success!" RST << std::endl;
    return m_result;
}

TestCase &TestCase::operator=(TestCase const &rhs)
{
    if (this != &rhs)
    {
        m_name = rhs.getName();
        m_test = rhs.m_test;
        m_result = rhs.getResult();
    }
    return *this;
}
