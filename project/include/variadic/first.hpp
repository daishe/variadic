//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <variadic/collection.hpp>

namespace variadic
{

    template <typename... Types>
    struct first;

    template <>
    struct first<>
    {};

    template <typename T, typename... Types>
    struct first<T, Types...>
    {
        using type = T;
    };

    template <typename T, typename... Types>
    using not_first = collection<Types...>;

} // namespace variadic
