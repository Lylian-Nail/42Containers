/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:04:56 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/12 11:07:32 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_ITERATOR_HPP

# define NORMAL_ITERATOR_HPP

namespace ft
{
    /*
    * This class is used to wrap a pointer as a simple random-access iterator
    * The iterator class name is the pointer
    * The Container is just used to differentiate the different containers
    * that used this class
    */

    template <class Iterator, class Container>
    class normal_iterator : public iterator<
        typename iterator_traits<Iterator>::iterator_category,
        typename iterator_traits<Iterator>::value_type,
        typename iterator_traits<Iterator>::difference_type,
        typename iterator_traits<Iterator>::pointer,
        typename iterator_traits<Iterator>::reference
    >
    {
    public:
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

        normal_iterator(): _it() {}
        normal_iterator(Iterator const &it): _it(it) {}

        // Allow iterator to const iterator conversion
        template <class Iter>
        normal_iterator(
            normal_iterator<Iter, Container> const &copy): 
            _it(copy.getBase())
        {
        }

        normal_iterator &operator=(normal_iterator const &rhs)
        {
            if (this != &rhs)
            {
                _it = rhs.getBase();
            }
            return *this;
        }

        /*
        * Forward iterator spec
        */

        reference operator*() const { return *_it; }
        pointer operator->() const { return _it; }

        normal_iterator &operator++()
        {
            ++_it;
            return *this;
        }

        normal_iterator operator++(int)
        {
            normal_iterator copy(*this);
            _it++;
            return copy;
        }

        /*
        * Bidirectional iterator spec
        */

        normal_iterator &operator--()
        {
            --_it;
            return *this;
        }

        normal_iterator operator--(int)
        {
            normal_iterator copy(*this);
            _it--;
            return copy;
        }

        /*
        * Random Access iterator spec
        */

        normal_iterator &operator+=(difference_type const &rhs)
        {
            _it += rhs;
            return *this;
        }

        normal_iterator operator+(difference_type const &rhs) const
        {
            return normal_iterator(_it + rhs);
        }

        normal_iterator &operator-=(difference_type const &rhs)
        {
            _it -= rhs;
            return *this;
        }

        normal_iterator operator-(difference_type const &rhs) const
        {
            return normal_iterator(_it - rhs);
        }

        reference operator[](difference_type const &rhs) const
        {
            return _it[rhs];
        }

        Iterator getBase() const
        {
            return _it;
        }

        ~normal_iterator() {}

    private:
        Iterator    _it;
    };

    /*
    * These functions are for handling different cv-qualifiers for Iterators
    * We use 2 things for that:
    *  - templating
    *  - and implicit conversion !
    *
    * Overloading operators outside its class permits making:
    *  n + a and a + n !
    */

    // Forward iterator specs

    template<typename IteratorL, typename IteratorR, typename Container>
    inline bool operator==(
        normal_iterator<IteratorL, Container> const &lhs,
        normal_iterator<IteratorR, Container> const &rhs
    )
    {
        return lhs.getBase() == rhs.getBase();
    }

    template<class Iterator, typename Container>
    inline bool operator==(
        normal_iterator<Iterator, Container> const &lhs,
        normal_iterator<Iterator, Container> const &rhs
    )
    {
        return lhs.getBase() == rhs.getBase();
    }

    template<typename IteratorL, class IteratorR, typename Container>
    inline bool operator!=(
        normal_iterator<IteratorL, Container> const &lhs,
        normal_iterator<IteratorR, Container> const &rhs
    )
    {
        return lhs.getBase() != rhs.getBase();
    }

    template<typename Iterator, typename Container>
    inline bool operator!=(
        normal_iterator<Iterator, Container> const &lhs,
        normal_iterator<Iterator, Container> const &rhs
    )
    {
        return lhs.getBase() != rhs.getBase();
    }

    //Random access iterator specs

    template<class IteratorL, typename IteratorR, typename Container>
    inline bool operator<(
        normal_iterator<IteratorL, Container> const &lhs,
        normal_iterator<IteratorR, Container> const &rhs
    )
    {
        return lhs.getBase() < rhs.getBase();
    }

    template<typename Iterator, typename Container>
    inline bool operator<(
        normal_iterator<Iterator, Container> const &lhs,
        normal_iterator<Iterator, Container> const &rhs
    )
    {
        return lhs.getBase() < rhs.getBase();
    }

    template<typename IteratorL, typename IteratorR, typename Container>
    inline bool operator>(
        normal_iterator<IteratorL, Container> const &lhs,
        normal_iterator<IteratorR, Container> const &rhs
    )
    {
        return lhs.getBase() > rhs.getBase();
    }

    template<typename Iterator, typename Container>
    inline bool operator>(
        normal_iterator<Iterator, Container> const &lhs,
        normal_iterator<Iterator, Container> const &rhs
    )
    {
        return lhs.getBase() > rhs.getBase();
    }

    template<typename IteratorL, typename IteratorR, typename Container>
    inline bool operator<=(
        normal_iterator<IteratorL, Container> const &lhs,
        normal_iterator<IteratorR, Container> const &rhs
    )
    {
        return lhs.getBase() <= rhs.getBase();
    }

    template<typename Iterator, typename Container>
    inline bool operator<=(
        normal_iterator<Iterator, Container> const &lhs,
        normal_iterator<Iterator, Container> const &rhs
    )
    {
        return lhs.getBase() <= rhs.getBase();
    }

    template<typename IteratorL, typename IteratorR, typename Container>
    inline bool operator>=(
        normal_iterator<IteratorL, Container> const &lhs,
        normal_iterator<IteratorR, Container> const &rhs
    )
    {
        return lhs.getBase() >= rhs.getBase();
    }

    template<typename Iterator, typename Container>
    inline bool operator>=(
        normal_iterator<Iterator, Container> const &lhs,
        normal_iterator<Iterator, Container> const &rhs
    )
    {
        return lhs.getBase() >= rhs.getBase();
    }

    // n + a
    template<typename Iterator, typename Container>
    inline normal_iterator<Iterator, Container> operator+(
        typename normal_iterator<Iterator, Container>::difference_type const &lhs,
        normal_iterator<Iterator, Container> const &rhs
    )
    {
        return normal_iterator<Iterator, Container>(rhs.getBase() + lhs);
    }

    template<typename IteratorL, typename IteratorR, typename Container>
    inline typename normal_iterator<IteratorL, Container>::difference_type
        operator-(
            normal_iterator<IteratorL, Container> const &lhs,
            normal_iterator<IteratorR, Container> const &rhs
        )
    {
        return lhs.getBase() - rhs.getBase();
    }

    template<typename Iterator, typename Container>
    inline typename normal_iterator<Iterator, Container>::difference_type
        operator-(
            normal_iterator<Iterator, Container> const &lhs,
            normal_iterator<Iterator, Container> const &rhs
        )
    {
        return lhs.getBase() - rhs.getBase();
    }
}

#endif
