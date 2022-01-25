/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:33:35 by lperson-          #+#    #+#             */
/*   Updated: 2021/12/08 12:34:03 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP

# define TESTS_HPP

# ifdef TEST_STD

# include <iterator>
# include <type_traits>
# include <container>
# include <map>
namespace ft = std;

# else

# include <iterator.hpp>
# include <type_traits.hpp>

# endif

void test_type_traits();

#endif
