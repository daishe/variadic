//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <type_traits>
#include <utility>

#include <variadic/def.hpp>
#include <variadic/type_frame.hpp>

namespace variadic
{

    namespace detail
    {

        // template <size_t Idx, typename... Types>
        // struct at_impl;

        // template <typename T, typename... Types>
        // struct at_impl<0, T, Types...>
        // {
        //     using type = T;
        // };

        // template <size_t Idx, typename T, typename... Types>
        // struct at_impl<Idx, T, Types...>
        // {
        //     using type = typename at<Idx - 1, Types...>::type;
        // };

        template <size_t Idx, typename = std::make_index_sequence<Idx>>
        struct at_impl;

        template <size_t Idx, size_t... Ignore>
        struct at_impl<Idx, std::index_sequence<Ignore...>>
        {
            template <typename T>
            static T deducer(decltype((void*)Ignore)..., T*, ...);
        };

        template <size_t Idx, typename... Types>
        using at_impl_shortcut = decltype(at_impl<Idx>::deducer(static_cast<type_frame<Types>*>(nullptr)...));

    } // namespace detail

    template <size_t Idx, typename... Types>
    struct at
    {
        static_assert(Idx < sizeof...(Types), "Index out of range");

        using type = typename detail::at_impl_shortcut<Idx, Types...>::type;
    };

} // namespace variadic