/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:02:32 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/06 10:46:21 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP

# define TEST_HPP

# include "test/basic_test.hpp"
# include "test/TestCase.hpp"
# include "test/TestSuite.hpp"

TestSuite *testUnitIterator();
TestSuite *testUnitTypeTraits();
TestSuite *testUnitVector();
TestSuite *testUnitStack();
TestSuite *testUnitUtility();
TestSuite *testUnitBinarySearchTree();
TestSuite *testUnitMap();

#endif
