/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestCase.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:54:29 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/25 15:01:17 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test/TestCase.hpp"

TestCase::TestCase():
	m_name(),
	m_test()
{
}

TestCase::TestCase(std::string const &name, testF test):
	m_name(name),
	m_test(test)
{
}

TestCase::TestCase(TestCase const &copy):
	m_name(copy.getName()),
	m_test(copy.m_test)
{
}

TestCase::~TestCase()
{
}

std::string const &TestCase::getName() const
{
	return m_name;
}

TestCase &TestCase::operator=(TestCase const &rhs)
{
	if (this != &rhs)
	{
		m_name = rhs.getName();
	}
	return *this;
}
