//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <utility>

#include <variadic/type_frame.hpp>

namespace variadic
{

    // template <size_t Idx, typename... Types>
    // struct at;

    // template <typename T, typename... Types>
    // struct at<0, T, Types...>
    // {
    //     using type = T;
    // };

    // template <size_t Idx, typename T, typename... Types>
    // struct at<Idx, T, Types...>
    // {
    //     using type = typename at<Idx - 1, Types...>::type;
    // };

    namespace detail
    {

        template <size_t Idx, typename = std::make_index_sequence<Idx>>
        struct at_frame_impl;

        template <size_t Idx, size_t... Ignore>
        struct at_frame_impl<Idx, std::index_sequence<Ignore...>>
        {
            template <typename T>
            static T deducer(decltype((void*)Ignore)..., T*, ...);
        };

        template <size_t Idx, typename... Types>
        using at_frame = decltype(at_frame_impl<Idx>::deducer(static_cast<type_frame<Types>*>(nullptr)...));

    } // namespace detail

    template <size_t Idx, typename... Types>
    struct at
    {
        using type = typename detail::at_frame<Idx, Types...>::type;
    };

} // namespace variadic