//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <variadic/collection.hpp>

namespace variadic
{

    namespace detail
    {

        template <typename ResultCollection, typename... Types>
        struct reverse_frame;

        template <typename ResultCollection>
        struct reverse_frame<ResultCollection>
        {
            using types = ResultCollection;
        };

        template <typename ResultCollection, typename T, typename... Types>
        struct reverse_frame<ResultCollection, T, Types...>
        {
            using types = typename reverse_frame<typename ResultCollection::template push_front<T>, Types...>::types;
        };

    } // namespace detail

    template <typename... Types>
    using reverse = typename detail::reverse_frame<collection<>, Types...>::types;

} // namespace variadic
