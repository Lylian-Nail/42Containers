/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:00:57 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/26 11:21:27 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include "test/ansii_color.hpp"

bool assert_failed(std::string const &file, int line, std::string const &msg)
{
    std::cout << BRED "error: " UWHT << file << RST ":" UWHT << line << RST
                 " | " BRED << msg.c_str() << std::endl;
    return false;
}
