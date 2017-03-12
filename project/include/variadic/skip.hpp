//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <variadic/collection.hpp>
#include <variadic/countdown.hpp>
#include <variadic/first.hpp>
#include <variadic/last.hpp>

namespace variadic
{

    template <size_t Count, countdown::condition_type condition, typename... Types>
    struct skip_front_frame;

    template <typename... Types>
    struct skip_front_frame<0, countdown::final_value, Types...>
    {
        using types = collection<Types...>;
    };

    template <size_t Count, typename T, typename... Types>
    struct skip_front_frame<Count, countdown::continue_value, T, Types...>
    {
        template <typename... NextTypes>
        using next = skip_front_frame<Count-1, countdown::condition(Count-1), NextTypes...>;

        using types = typename not_first<T, Types...>::template emplace<next>::types;
    };

    template <size_t Count, countdown::condition_type condition, typename... Types>
    struct skip_back_frame;

    template <typename... Types>
    struct skip_back_frame<0, countdown::final_value, Types...>
    {
        using types = collection<Types...>;
    };

    template <size_t Count, typename T, typename... Types>
    struct skip_back_frame<Count, countdown::continue_value, T, Types...>
    {
        template <typename... NextTypes>
        using next = skip_back_frame<Count-1, countdown::condition(Count-1), NextTypes...>;

        using types = typename not_last<T, Types...>::template emplace<next>::types;
    };

    template <size_t Count>
    struct skip
    {
        template <typename... Types>
        using front = typename skip_front_frame<Count, countdown::condition(Count), Types...>::types;

        template <typename... Types>
        using back = typename skip_back_frame<Count, countdown::condition(Count), Types...>::types;
    };

} // namespace variadic
