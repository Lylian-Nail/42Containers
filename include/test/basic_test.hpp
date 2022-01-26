/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_test.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:03:11 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/26 13:47:17 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_HPP

# define MACRO_HPP

# include <string>

bool assert_failed(std::string const &file, int line, std::string const &msg);

// Return 0 if success non-zero if fails
# define ASSERT(expr) \
    if ((expr)) { ; } \
    else \
        return !assert_failed(__FILE__, __LINE__, #expr);

#endif
