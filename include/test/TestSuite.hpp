/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestSuite.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:52:40 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/26 12:16:50 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_SUITE_HPP

# define TEST_SUITE_HPP

# include <string>
# include <vector>
# include "TestCase.hpp"

class TestSuite
{
public:
    TestSuite();
    TestSuite(std::string const &name);
    TestSuite(TestSuite const &copy);
    ~TestSuite();

    std::string const &getName() const;
    int getFails() const;
    int getTotalTests() const;

    void addTest(TestCase const &test);

    int run();

    TestSuite &operator=(TestSuite const &rhs);

private:
    std::string m_name;
    std::vector<TestCase> m_tests;
    int m_fails;

};

#endif
