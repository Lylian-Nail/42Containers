/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestCase.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:54:29 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/26 13:34:15 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "test/TestCase.hpp"
#include "test/ansii_color.hpp"

TestCase::TestCase():
    m_name(),
    m_test(),
    m_result(),
    m_mstime()
{
}

TestCase::TestCase(std::string const &name, testF test):
    m_name(name),
    m_test(test),
    m_result(0),
    m_mstime(-1)
{
}

TestCase::TestCase(TestCase const &copy):
    m_name(copy.getName()),
    m_test(copy.m_test),
    m_result(copy.getResult()),
    m_mstime(copy.getMSTime())
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

long TestCase::getMSTime() const
{
    return m_mstime;
}

int TestCase::run()
{
    std::cout << "Testing: " BWHT << m_name << RST << std::endl;
    std::clock_t clock = std::clock();

    m_result = m_test();
    if (m_result)
        std::cout << BWHT << m_name << ": " BRED << "failed!" RST << std::endl;
    else
        std::cout << BWHT << m_name << ": " BGRN << "success!" RST << std::endl;

    m_mstime = (std::clock() - clock) / CLOCKS_PER_SEC * 1000;
    std::cout << "Time: " BWHT << m_mstime << "ms" RST << std::endl;
    return m_result;
}

TestCase &TestCase::operator=(TestCase const &rhs)
{
    if (this != &rhs)
    {
        m_name = rhs.getName();
        m_test = rhs.m_test;
        m_result = rhs.getResult();
        m_mstime = rhs.getMSTime();
    }
    return *this;
}
