/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestSuite.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:56:53 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/26 12:02:12 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test/TestSuite.hpp"

TestSuite::TestSuite():
    m_name(),
    m_tests()
{
}

TestSuite::TestSuite(std::string const &name):
    m_name(name),
    m_tests()
{
}

TestSuite::TestSuite(TestSuite const &copy):
    m_name(copy.getName()),
    m_tests(copy.m_tests)
{
}

TestSuite::~TestSuite()
{
}

std::string const &TestSuite::getName() const
{
    return m_name;
}

void TestSuite::addTest(TestCase const &test)
{
    m_tests.push_back(test);
}

TestSuite &TestSuite::operator=(TestSuite const &rhs)
{
    if (this != &rhs)
    {
        m_name = rhs.getName();
        m_tests = rhs.m_tests;
    }
    return *this;
}
