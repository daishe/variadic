//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <utility>

#include <variadic/at.hpp>
#include <variadic/collection.hpp>

namespace variadic
{

    // template <typename... Types>
    // struct last;

    // template <>
    // struct last<>
    // {};

    // template <typename T>
    // struct last<T>
    // {
    //     using type = T;
    // };

    // template <typename T, typename Y, typename... Types>
    // struct last<T, Y, Types...>
    // {
    //     using type = typename last<Y, Types...>::type;
    // };


    namespace detail
    {

        template <typename... Types>
        struct last_frame;

        template <>
        struct last_frame<>
        {};

        template <typename T, typename... Types>
        struct last_frame<T, Types...>
        {
            using type = typename at<sizeof...(Types), T, Types...>::type;
        };

        template <class Sequence, typename... Types>
        struct not_last_frame;

        template <size_t... Idxs, typename... Types>
        struct not_last_frame<std::index_sequence<Idxs...>, Types...>
        {
            using types = collection<typename at<Idxs, Types...>::type...>;
        };

    } // namespace detail

    template <typename... Types>
    using last = detail::last_frame<Types...>;

    template <typename... Types>
    using not_last = typename detail::not_last_frame<std::make_index_sequence<sizeof...(Types) - 1>, Types...>::types;

} // namespace variadic