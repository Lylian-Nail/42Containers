/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_test.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:03:11 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/26 12:45:10 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_HPP

# define MACRO_HPP

# include <string>

bool assert_failed(std::string const &file, int line, std::string const &msg);

// Use property of OR boolean operator to avoid dangling else danger.
// Return 0 if success non-zero if fails
# define ASSERT(expr) \
    (!((expr) || \
        assert_failed(__FILE__, __LINE__, #expr)))

#endif
