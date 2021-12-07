/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:21:37 by lperson-          #+#    #+#             */
/*   Updated: 2021/12/07 17:09:29 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP

# define REVERSE_ITERATOR_HPP

namespace ft
{
    template <class Iterator>
    class reverse_iterator : public iterator<
        typename iterator_traits<Iterator>::iterator_category,
        typename iterator_traits<Iterator>::value_type,
        typename iterator_traits<Iterator>::difference_type,
        typename iterator_traits<Iterator>::pointer,
        typename iterator_traits<Iterator>::reference
    >
    {
    public:
        typedef Iterator                            iterator_type;
        typedef typename iterator_traits<Iterator>::iterator_category
                                                    iterator_category;
        typedef typename iterator_traits<Iterator>::value_type
                                                    value_type;
        typedef typename iterator_traits<Iterator>::difference_type
                                                    difference_type;
        typedef typename iterator_traits<Iterator>::pointer
                                                    pointer;
        typedef typename iterator_traits<Iterator>::reference
                                                    reference;

        reverse_iterator();
        explicit reverse_iterator(iterator_type it): _base(it) {}
        template <class Iter>
        reverse_iterator(reverse_iterator<Iter> const &copy):
                _base(copy.base()) {}

        iterator_type   base() const { return _base; }

        reference operator*() const
        {
            Iterator copy(_base);
            --copy;
            return *copy;
        }

        pointer operator->() const
        {
            return &(operator*());
        }

        reverse_iterator &operator++()
        {
            --_base;
            return *this;
        }

        reverse_iterator operator++(int)
        {
            reverse_iterator copy(*this);
            ++(*this);
            return copy;
        }

        reverse_iterator &operator--()
        {
            ++_base;
            return *this;
        }

        reverse_iterator operator--(int)
        {
            reverse_iterator copy(*this);
            --(*this);
            return copy;
        }

        reference operator[](difference_type n) const
        {
            return *(_base - n - 1);
        }

        reverse_iterator operator+(difference_type n) const
        {
            return reverse_iterator(_base - n);
        }

        reverse_iterator &operator+(difference_type n)
        {
            _base -= n;
            return *this;
        }

        reverse_iterator operator-(difference_type n) const
        {
            return reverse_iterator(_base + n);
        }

        reverse_iterator operator-(difference_type n)
        {
            _base += n;
            return *this;
        }

    private:
        iterator_type    _base;
    };

    template <class Iterator>
    reverse_iterator<Iterator> operator+(
        typename reverse_iterator<Iterator>::difference_type lhs,
        reverse_iterator<Iterator> const &rhs
    )
    {
        return reverse_iterator<Iterator>(rhs.base() - lhs);
    }

    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(
        reverse_iterator<Iterator> const &lhs,
        reverse_iterator<Iterator> const &rhs
    )
    {
        return lhs.base() - rhs.base();
    }

    template <class Iterator>
    bool operator==(
        reverse_iterator<Iterator> const &lhs,
        reverse_iterator<Iterator> const &rhs
    )
    {
        return lhs.base() == rhs.base();
    }

    template <class Iterator>
    bool operator!=(
        reverse_iterator<Iterator> const &lhs,
        reverse_iterator<Iterator> const &rhs
    )
    {
        return lhs.base() != rhs.base();
    }

    template <class Iterator>
    bool operator>(
        reverse_iterator<Iterator> const &lhs,
        reverse_iterator<Iterator> const &rhs
    )
    {
        return lhs.base() < rhs.base();
    }

    template <class Iterator>
    bool operator>=(
        reverse_iterator<Iterator> const &lhs,
        reverse_iterator<Iterator> const &rhs
    )
    {
        return lhs.base() <= rhs.base();
    }

    template <class Iterator>
    bool operator<(
        reverse_iterator<Iterator> const &lhs,
        reverse_iterator<Iterator> const &rhs
    )
    {
        return lhs.base() > rhs.base();
    }

    template <class Iterator>
    bool operator<=(
        reverse_iterator<Iterator> const &lhs,
        reverse_iterator<Iterator> const &rhs
    )
    {
        return lhs.base() >= rhs.base();
    }
}

#endif
