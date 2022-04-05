/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:02:32 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/05 11:04:08 by lperson-         ###   ########.fr       */
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

#endif
