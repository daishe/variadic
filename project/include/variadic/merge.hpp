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

        template <typename ResultCollection, typename... Collections>
        struct merge_frame;

        template <typename ResultCollection>
        struct merge_frame<ResultCollection>
        {
            using types = ResultCollection;
        };

        template <typename ResultCollection, typename C0, typename... Collections>
        struct merge_frame<ResultCollection, C0, Collections...>
        {
            using types = typename merge_frame<typename C0::template emplace<ResultCollection::template push_back>, Collections...>::types;
        };

    } // namespace detail

    template <typename... Collections>
    using merge = typename detail::merge_frame<collection<>, Collections...>::types;

    template <typename... Types>
    struct merge_types
    {
        template <typename... OtherTypes>
        using with = merge_types<Types..., OtherTypes...>;

        template <typename... Collections>
        using with_collection = typename merge<collection<Types...>, Collections...>::template emplace<merge_types>;

        using types = collection<Types...>;
    };

} // namespace variadic
