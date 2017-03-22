//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <variadic/collection.hpp>
#include <variadic/def.hpp>
#include <variadic/pack.hpp>

namespace variadic
{

    namespace detail
    {

        // template <typename ResultCollection, typename... Collections>
        // struct pack_cat_impl;

        // template <typename ResultCollection>
        // struct pack_cat_impl<ResultCollection>
        // {
        //     using types = ResultCollection;
        // };

        // template <typename ResultCollection, typename C0, typename... Collections>
        // struct pack_cat_impl<ResultCollection, C0, Collections...>
        // {
        //     using types = typename pack_cat_impl<typename C0::template emplace<ResultCollection::template push_back>, Collections...>::types;
        // };

        template <typename FirstCollection, typename... Collections>
        struct pack_cat_impl__collections;

        template <typename FirstCollection>
        struct pack_cat_impl__collections<FirstCollection>
        {
            using types = FirstCollection;
        };

        template <typename FirstCollection, typename NextCollection, typename... Collections>
        struct pack_cat_impl__collections<FirstCollection, NextCollection, Collections...>
        {
            using types = typename pack_cat_impl__collections<typename NextCollection::template emplace<FirstCollection::template push_back>, Collections...>::types;
        };

        template <typename... Packs>
        struct pack_cat_impl
        {
            using types = typename pack_cat_impl__collections<collection<>, typename unpack_impl<Packs>::types...>::types;
        };

    } // namespace detail

    template <typename... Packs>
    struct pack_cat
    {
        using types = typename detail::pack_cat_impl<Packs...>::types;
    };

    template <typename... Types>
    struct cat
    {
        template <typename... OtherTypes>
        using with = cat<Types..., OtherTypes...>;

        template <typename... Packs>
        using with_pack = typename pack_cat<collection<Types...>, Packs...>::types::template emplace<cat>;

        using types = collection<Types...>;
    };

} // namespace variadic
