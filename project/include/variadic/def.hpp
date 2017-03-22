//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

namespace variadic
{

    template <size_t Idx, typename... Types>
    struct at;

    template <typename Pack>
    struct pack_clear;

    template <typename Pack>
    struct unpack;

    template <typename... Types>
    struct back;

    template <typename... Types>
    struct collection;

    template <typename... Types>
    struct front;

    template <typename... Types>
    struct pack;

    template <typename... Types>
    struct pop_back;

    template <typename... Types>
    struct pop_front;

    template <typename... Types>
    struct reverse;

} // namespace variadic