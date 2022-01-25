/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestCase.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:51:14 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/25 15:00:29 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_CASE_HPP

# define TEST_CASE_HPP

# include <string>

class TestCase
{
public:
	typedef int (*testF)();

	TestCase(std::string const &name, testF test);
	~TestCase();

	std::string const &getName() const;

private:
	std::string m_name;
	testF const m_test;

	TestCase();
	TestCase(TestCase const &copy);

	TestCase &operator=(TestCase const &rhs);

};

#endif
