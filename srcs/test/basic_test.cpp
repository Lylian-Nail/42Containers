/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:00:57 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/26 12:44:08 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include "test/ansii_color.hpp"

bool assert_failed(std::string const &file, int line, std::string const &msg)
{
    std::cout << BRED "error: " UWHT << file << ":" << line << RST " | "
                 BRED << msg <<  RST << std::endl;
    return false;
}
