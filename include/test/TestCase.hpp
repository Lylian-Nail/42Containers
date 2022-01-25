/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestCase.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:53:35 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/19 13:53:35 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTCASE_HPP_
# define TESTCASE_HPP_

# include <string>

class TestCase
{
 public:
  TestCase();
  TestCase(std::string const &name, int (*testF)());
  TestCase(TestCase const &copy);
  virtual ~TestCase();

  void getTest
};

#endif
