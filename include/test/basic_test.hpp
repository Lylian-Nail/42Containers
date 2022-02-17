/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_test.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:03:11 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/16 13:17:49 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_TEST_HPP

# define BASIC_TEST_HPP

# include <string>

bool assertFailed(std::string const &file, int line, std::string const &msg);

// Return 0 if success non-zero if fails
# define ASSERT(expr) \
    if ((expr)) \
    { \
        ; \
    } \
    else \
    { \
        return !assertFailed(__FILE__, __LINE__, #expr); \
    }

#endif
