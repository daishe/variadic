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

        template <typename... Types>
        struct front_impl;

        template <>
        struct front_impl<>
        {};

        template <typename T, typename... Types>
        struct front_impl<T, Types...>
        {
            using type = T;
        };

        template <typename... Types>
        struct pop_front_impl;

        template <>
        struct pop_front_impl<>
        {};

        template <typename T, typename... Types>
        struct pop_front_impl<T, Types...>
        {
            using types = collection<Types...>;
        };

    } // namespace detail

    template <typename... Types>
    struct front
    {
        static_assert(sizeof...(Types) > 0, "No front item in empty template parametr pack");

        using type = typename detail::front_impl<Types...>::type;
    };

    template <typename... Types>
    struct pop_front
    {
        static_assert(sizeof...(Types) > 0, "No not front item(s) in empty template parametr pack");

        using types = typename detail::pop_front_impl<Types...>::types;
    };

} // namespace variadic
