/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IBaseTest.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:35:39 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/27 10:52:36 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IBASE_TEST_HPP

# define IBASE_TEST_HPP

class IBaseTest
{
public:
    virtual ~IBaseTest();

    virtual int run()= 0;
};

#endif
