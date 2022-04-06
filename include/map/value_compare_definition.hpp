/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_compare_definition.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:22:48 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/06 12:38:09 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALUE_COMPARE_DEFINITION_HPP

# define VALUE_COMPARE_DEFINITION_HPP

# include <functional>

namespace ft
{
    template <class Key, class T, class Compare, class Alloc>
    class map<Key, T, Compare, Alloc>::value_compare
        : public std::binary_function<value_type, value_type, bool>
    {
        friend class map;

    protected:
        Compare m_comp;

        explicit value_compare(Compare comp);
    public:
        value_compare();
        value_compare(value_compare const &copy);
        ~value_compare();

        bool operator()(value_type const &lhs, value_type const &rhs) const;
        value_compare &operator=(value_compare const &rhs);
    };
}

#endif
