/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestCase.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:51:14 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/26 13:27:59 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_CASE_HPP

# define TEST_CASE_HPP

# include <string>

class TestCase
{
public:
    typedef int (*testF)();

    TestCase();
    TestCase(TestCase const &copy);
    TestCase(std::string const &name, testF test);
    ~TestCase();

    std::string const &getName() const;
    int getResult() const;
    long getMSTime() const;

    int run();

    TestCase &operator=(TestCase const &rhs);

private:
    std::string m_name;
    testF       m_test;
    int         m_result;
    long        m_mstime;

};

#endif
