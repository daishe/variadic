//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <variadic/collection.hpp>
#include <variadic/countdown.hpp>
#include <variadic/def.hpp>
#include <variadic/front.hpp>
#include <variadic/back.hpp>

namespace variadic
{

    namespace detail
    {

        template <size_t Count, countdown::condition_type condition, typename... Types>
        struct skip_front_impl;

        template <typename... Types>
        struct skip_front_impl<0, countdown::final_value, Types...>
        {
            using types = collection<Types...>;
        };

        template <size_t Count, typename T, typename... Types>
        struct skip_front_impl<Count, countdown::continue_value, T, Types...>
        {
            template <typename... NextTypes>
            using next = skip_front_impl<Count-1, countdown::condition(Count-1), NextTypes...>;

            using types = typename pop_front<T, Types...>::types::template emplace<next>::types;
        };

        template <size_t Count, countdown::condition_type condition, typename... Types>
        struct skip_back_impl;

        template <typename... Types>
        struct skip_back_impl<0, countdown::final_value, Types...>
        {
            using types = collection<Types...>;
        };

        template <size_t Count, typename T, typename... Types>
        struct skip_back_impl<Count, countdown::continue_value, T, Types...>
        {
            template <typename... NextTypes>
            using next = skip_back_impl<Count-1, countdown::condition(Count-1), NextTypes...>;

            using types = typename pop_back<T, Types...>::types::template emplace<next>::types;
        };

    } // namespace detail


    ///
    /// \brief      Skips given count of items from template parameter pack
    ///
    /// \tparam     Count  How many items to skip
    ///
    /// \todo       Change the underlying implementation to the same algorithm as with variadic::at
    ///
    template <size_t Count>
    struct skip
    {
        template <typename... Types>
        using front = typename detail::skip_front_impl<Count, countdown::condition(Count), Types...>::types;

        template <typename... Types>
        using back = typename detail::skip_back_impl<Count, countdown::condition(Count), Types...>::types;
    };

} // namespace variadic
