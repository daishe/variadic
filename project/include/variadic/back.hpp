//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <utility>

#include <variadic/at.hpp>
#include <variadic/collection.hpp>
#include <variadic/def.hpp>

namespace variadic
{

    namespace detail
    {

        // template <typename... Types>
        // struct back_impl;

        // template <>
        // struct back_impl<>
        // {};

        // template <typename T>
        // struct back_impl<T>
        // {
        //     using type = T;
        // };

        // template <typename T, typename Y, typename... Types>
        // struct back_impl<T, Y, Types...>
        // {
        //     using type = typename back<Y, Types...>::type;
        // };

        template <typename... Types>
        struct back_impl;

        template <>
        struct back_impl<>
        {};

        template <typename T, typename... Types>
        struct back_impl<T, Types...>
        {
            using type = typename at<sizeof...(Types), T, Types...>::type;
        };

        template <class Sequence, typename... Types>
        struct pop_back_impl;

        template <size_t... Idxs, typename... Types>
        struct pop_back_impl<std::index_sequence<Idxs...>, Types...>
        {
            using types = collection<typename at<Idxs, Types...>::type...>;
        };

    } // namespace detail

    template <typename... Types>
    struct back
    {
        static_assert(sizeof...(Types) > 0, "No back item in empty template parametr pack");

        using type = typename detail::back_impl<Types...>::type;
    };

    template <typename... Types>
    struct pop_back
    {
        static_assert(sizeof...(Types) > 0, "No not back item(s) in empty template parametr pack");

        using types = typename detail::pop_back_impl<std::make_index_sequence<sizeof...(Types) - 1>, Types...>::types;
    };

} // namespace variadic