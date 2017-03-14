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

        template <typename... Types>
        struct first_frame;

        template <>
        struct first_frame<>
        {};

        template <typename T, typename... Types>
        struct first_frame<T, Types...>
        {
            using type = T;
        };

    } // namespace detail

    template <typename... Types>
    using first = detail::first_frame<Types...>;

    template <typename T, typename... Types>
    using not_first = collection<Types...>;

} // namespace variadic
