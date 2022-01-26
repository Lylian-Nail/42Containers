/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestSuite.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:56:53 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/26 12:41:22 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "test/TestSuite.hpp"
#include "test/ansii_color.hpp"

TestSuite::TestSuite():
    m_name(),
    m_tests(),
    m_fails()
{
}

TestSuite::TestSuite(std::string const &name):
    m_name(name),
    m_tests(),
    m_fails(0)
{
}

TestSuite::TestSuite(TestSuite const &copy):
    m_name(copy.getName()),
    m_tests(copy.m_tests),
    m_fails(copy.getFails())
{
}

TestSuite::~TestSuite()
{
}

std::string const &TestSuite::getName() const
{
    return m_name;
}

int TestSuite::getFails() const
{
    return m_fails;
}

int TestSuite::getTotalTests() const
{
    return m_tests.size();
}

void TestSuite::addTest(TestCase const &test)
{
    m_tests.push_back(test);
}

int TestSuite::run()
{
    std::cout << "Running unit: " BWHT << m_name << RST << std::endl;

    std::vector<TestCase>::iterator itBegin = m_tests.begin();
    std::vector<TestCase>::iterator itEnd = m_tests.end();

    for (;itBegin != itEnd; itBegin++)
    {
        std::cout << std::endl;
        if (itBegin->run())
            m_fails++;
    }

    int passed_tests = m_tests.size() - m_fails;

    std::cout << std::endl << "passed tests: " BWHT "(" BGRN << passed_tests
              << BWHT "/" << getTotalTests() << ") " RST;
    std::cout << "failed tests: " BWHT "(" << BRED << m_fails
              << BWHT "/" << getTotalTests() << ")" RST << std::endl;

    return m_fails;
}

TestSuite &TestSuite::operator=(TestSuite const &rhs)
{
    if (this != &rhs)
    {
        m_name = rhs.getName();
        m_tests = rhs.m_tests;
        m_fails = rhs.getFails();
    }
    return *this;
}
