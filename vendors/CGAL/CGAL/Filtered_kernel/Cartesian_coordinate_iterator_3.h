// Copyright (c) 2006  INRIA Sophia-Antipolis (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; version 2.1 of the License.
// See the file LICENSE.LGPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.5-branch/Filtered_kernel/include/CGAL/Filtered_kernel/Cartesian_coordinate_iterator_3.h $
// $Id: Cartesian_coordinate_iterator_3.h 42821 2008-04-09 18:06:00Z spion $
//
//
// Author(s)     : Andreas Fabri, Sylvain Pion

#ifndef CGAL_CARTESIAN_COORDINATE_ITERATOR_3_H
#define CGAL_CARTESIAN_COORDINATE_ITERATOR_3_H

#include <cstddef>
#include <iterator>
#include <boost/variant.hpp>

CGAL_BEGIN_NAMESPACE

// This class should go away.
// It is now only used by the Filtered_kernel.
// It allows to iterate over the coordinates of both a Point_3 and a Vector_3,
// using a boost::variant, as the iterator types are the same at the kernel level.

template <class K>
class Cartesian_coordinate_iterator_3
{
  typedef typename K::Point_3 P;
  typedef typename K::Vector_3 V;
  boost::variant<const P*, const V*> var;
  int index;
  typedef Cartesian_coordinate_iterator_3<K> Self;

public:

  typedef typename K::FT FT;

  typedef std::random_access_iterator_tag iterator_category;
  typedef FT                              value_type;
  typedef std::ptrdiff_t                  difference_type;
  typedef const value_type&               reference;
  typedef const value_type*               pointer;

  Cartesian_coordinate_iterator_3()
    : var((const P*) NULL), index(0) {}

  Cartesian_coordinate_iterator_3(const P *const p, int _index = 0)
    : var(p), index(_index) {}

  Cartesian_coordinate_iterator_3(const V *const v, int _index = 0)
    : var(v), index(_index) {}

  const FT
  operator*() const {
    if (const P* const* p = boost::get<const P*>(&var))
      return (*p)->cartesian(index);
    if (const V* const* v = boost::get<const V*>(&var))
      return (*v)->cartesian(index);
    // std::cerr << "type of var = " << var.type().name() << std::endl;
    CGAL_error();
    std::abort(); // to kill warning
  }

  Self&  operator++() {
    index++;
    return *this;
  }

  Self&
  operator--() {
    index--;
    return *this;
  }

  Self
  operator++(int) {
    Self tmp(*this);
    ++(*this);
    return tmp;
  }

  Self
  operator--(int) {
    Self tmp(*this);
    --(*this);
    return tmp;
  }

  Self&
  operator+=(difference_type i) {
    index+=i;
    return *this;
  }

  Self&
  operator-=(difference_type i) {
    index -= i;
    return *this;
  }

  Self
  operator+(difference_type i) const {
    Self tmp=*this;
    return tmp += i;
  }

  Self operator-(difference_type i) const {
    Self tmp=*this;
    return tmp -= i;
  }

  difference_type
  operator-(const Self& x) const {
    CGAL_kernel_assertion(var == x.var);
    return index - x.index;
  }

  reference operator[](difference_type i) const {
    return *(*this + i);
  }

  bool operator==(const Self& x) const {
    return (var == x.var) && (index == x.index) ;
  }

  bool operator!=(const Self& x) const {
    return ! (*this==x);
  }

  bool operator<(const Self& x) const
  {
    return (x - *this) > 0;
  }

};

CGAL_END_NAMESPACE

#endif // CGAL_CARTESIAN_COORDINATE_ITERATOR_3_H