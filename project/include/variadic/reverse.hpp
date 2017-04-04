//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <variadic/collection.hpp>
#include <variadic/def.hpp>

namespace variadic
{

    namespace detail
    {

        template <typename ResultCollection, typename... Types>
        struct reverse_impl;

        template <typename ResultCollection>
        struct reverse_impl<ResultCollection>
        {
            using types = ResultCollection;
        };

        template <typename ResultCollection, typename T, typename... Types>
        struct reverse_impl<ResultCollection, T, Types...>
        {
            using types = typename reverse_impl<typename ResultCollection::template push_front<T>, Types...>::types;
        };

    } // namespace detail

    template <typename... Types>
    struct reverse
    {
        using types = typename detail::reverse_impl<collection<>, Types...>::types;
    };

} // namespace variadic
