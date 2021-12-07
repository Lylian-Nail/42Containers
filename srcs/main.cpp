/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:16:12 by lperson-          #+#    #+#             */
/*   Updated: 2021/12/07 11:36:25 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cassert>
#include <iterators/normal_iterator.hpp>
#include <vector.hpp>

void test_iterator()
{
	int	value[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	{
		NormalIterator<int *, int[]> it(value);

		NormalIterator<int *, int[]> itCopy(value);
		itCopy = value;

		assert(it == itCopy);
		++it;
		assert(it != itCopy);
		itCopy += 1;
		assert(it == itCopy);

		it = it - 1;
		itCopy--;
		assert(it == itCopy); // post decrementation and offset decrementation
		assert(it++ == itCopy); // post incrementation return cpy of previous obj
		assert(1 + it == it + 1); // n + i == i + n
	}

	{
		NormalIterator<int *, int[]> it(value);
		NormalIterator<int *, int[]> itGreater(value + 5);
		NormalIterator<int *, int[]> itCopy(it);

		assert(*it == 0);
		assert(it[0] == 0);
		assert(*(it + 1) == 1);
		assert(*(it + 1 - 1) == 0);
		assert(it < itGreater);
		assert(itGreater > it);
		assert(it >= itCopy);
		assert(itGreater >= itCopy);
		assert(it <= itCopy);
		assert(it <= itGreater);
	}
}

void test_vector_ctor()
{
	{
		ft::vector<int>	vector;
	}

	{
		ft::vector<int>	vector(10, 100);
	}

	{
		ft::vector<int>	vector(100, 42);
		ft::vector<int>
	}

}

#include <vector.hpp>

int main()
{
	test_iterator();
}
