/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:04:56 by lperson-          #+#    #+#             */
/*   Updated: 2021/12/06 16:52:05 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_ITERATOR_HPP

# define NORMAL_ITERATOR_HPP

# include <iterator>

/*
 * This class is used to wrap a pointer as a simple random-access iterator
 * The iterator class name is the pointer
 * The Container is just used to differentiates the differents container
 * that used this class
*/

template <class Iterator, class Container>
class NormalIterator
{
public:

    /*
     * We guess the differents iterator traits of our pointer or iterator
     * with the iterator_traits template function
    */

    typedef typename std::iterator_traits<Iterator>::iterator_category
                                                            iterator_category;
    typedef typename std::iterator_traits<Iterator>::value_type
                                                            value_type;
    typedef typename std::iterator_traits<Iterator>::difference_type
                                                            difference_type;
    typedef typename std::iterator_traits<Iterator>::pointer
                                                            pointer;
    typedef typename std::iterator_traits<Iterator>::reference
                                                            reference;

    NormalIterator(): _it() {}
    NormalIterator(Iterator const &it): _it(it) {}
    NormalIterator(NormalIterator const &copy): _it(copy.getBase()) {}

    NormalIterator &operator=(NormalIterator const &rhs)
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

    NormalIterator &operator++()
    {
        ++_it;
        return *this;
    }

    NormalIterator operator++(int)
    {
        NormalIterator copy(*this);
        _it++;
        return copy;
    }

    /*
     * Bidirectionnal iterator spec
    */

    NormalIterator &operator--()
    {
        --_it;
        return *this;
    }

    NormalIterator operator--(int)
    {
        NormalIterator copy(*this);
        _it--;
        return copy;
    }

    /*
     * Random Access iterator spec
    */

    NormalIterator &operator+=(difference_type const &rhs)
    {
        _it += rhs;
        return *this;
    }

    NormalIterator operator+(difference_type const &rhs) const
    {
        return NormalIterator(_it + rhs);
    }

    NormalIterator &operator-=(difference_type const &rhs)
    {
        _it -= rhs;
        return *this;
    }

    NormalIterator operator-(difference_type const &rhs) const
    {
        return NormalIterator(_it - rhs);
    }

    reference operator[](difference_type const &rhs) const
    {
        return _it[rhs];
    }

    Iterator getBase() const
    {
        return _it;
    }

    ~NormalIterator() {}

private:
    Iterator    _it;
};

/*
 * This functions are for handling differents cv-qualifiers for Iterators
 * We uses 2 things for that:
 *  -templating
 *  - and implicit conversion !
 *
 * Overloading operators outside its class permits to make:
 *  n + a and a + n !
*/

// Forward iterator specs

template<typename IteratorL, typename IteratorR, typename Container>
inline bool operator==(
    NormalIterator<IteratorL, Container> const &lhs,
    NormalIterator<IteratorR, Container> const &rhs
)
{
    return lhs.getBase() == rhs.getBase();
}

template<class Iterator, typename Container>
inline bool operator==(
    NormalIterator<Iterator, Container> const &lhs,
    NormalIterator<Iterator, Container> const &rhs
)
{
    return lhs.getBase() == rhs.getBase();
}

template<typename IteratorL, class IteratorR, typename Container>
inline bool operator!=(
    NormalIterator<IteratorL, Container> const &lhs,
    NormalIterator<IteratorR, Container> const &rhs
)
{
    return lhs.getBase() != rhs.getBase();
}

template<typename Iterator, typename Container>
inline bool operator!=(
    NormalIterator<Iterator, Container> const &lhs,
    NormalIterator<Iterator, Container> const &rhs
)
{
    return lhs.getBase() != rhs.getBase();
}

//Random access iterator specs

template<class IteratorL, typename IteratorR, typename Container>
inline bool operator<(
    NormalIterator<IteratorL, Container> const &lhs,
    NormalIterator<IteratorR, Container> const &rhs
)
{
    return lhs.getBase() < rhs.getBase();
}

template<typename Iterator, typename Container>
inline bool operator<(
    NormalIterator<Iterator, Container> const &lhs,
    NormalIterator<Iterator, Container> const &rhs
)
{
    return lhs.getBase() < rhs.getBase();
}

template<typename IteratorL, typename IteratorR, typename Container>
inline bool operator>(
    NormalIterator<IteratorL, Container> const &lhs,
    NormalIterator<IteratorR, Container> const &rhs
)
{
    return lhs.getBase() > rhs.getBase();
}

template<typename Iterator, typename Container>
inline bool operator>(
    NormalIterator<Iterator, Container> const &lhs,
    NormalIterator<Iterator, Container> const &rhs
)
{
    return lhs.getBase() > rhs.getBase();
}

template<typename IteratorL, typename IteratorR, typename Container>
inline bool operator<=(
    NormalIterator<IteratorL, Container> const &lhs,
    NormalIterator<IteratorL, Container> const &rhs
)
{
    return lhs.getBase() <= rhs.getBase();
}

template<typename Iterator, typename Container>
inline bool operator<=(
    NormalIterator<Iterator, Container> const &lhs,
    NormalIterator<Iterator, Container> const &rhs
)
{
    return lhs.getBase() <= rhs.getBase();
}

template<typename IteratorL, typename IteratorR, typename Container>
inline bool operator>=(
    NormalIterator<IteratorL, Container> const &lhs,
    NormalIterator<IteratorR, Container> const &rhs
)
{
    return lhs.getBase() >= rhs.getBase();
}

template<typename Iterator, typename Container>
inline bool operator>=(
    NormalIterator<Iterator, Container> const &lhs,
    NormalIterator<Iterator, Container> const &rhs
)
{
    return lhs.getBase() >= rhs.getBase();
}

// n + a
template<typename Iterator, typename Container>
inline NormalIterator<Iterator, Container> operator+(
    typename NormalIterator<Iterator, Container>::difference_type const &lhs,
    NormalIterator<Iterator, Container> const &rhs
)
{
    return NormalIterator<Iterator, Container>(rhs.getBase() + lhs);
}

template<typename IteratorL, typename IteratorR, typename Container>
inline typename NormalIterator<IteratorL, Container>::difference_type
    operator-(
        NormalIterator<IteratorL, Container> const &lhs,
        NormalIterator<IteratorR, Container> const &rhs
    )
{
    return lhs.getBase() - rhs.getBase();
}

template<typename Iterator, typename Container>
inline typename NormalIterator<Iterator, Container>::difference_type
    operator-(
        NormalIterator<Iterator, Container> const &lhs,
        NormalIterator<Iterator, Container> const &rhs
    )
{
    return lhs.getBase() - rhs.getBase();
}

#endif
