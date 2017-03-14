//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

namespace variadic
{

    namespace detail
    {

        template <template <typename> typename ... Types>
        struct nested_type;

        template <>
        struct nested_type<>
        {
            template <typename Y>
            using type = Y;
        };

        template <template <typename> typename T, template <typename> typename ... Types>
        struct nested_type<T, Types...>
        {
            template <typename Y>
            using type = T<typename nested_type<Types...>::template type<Y>>;
        };

    } // namespace detail

    template <template <typename> typename ... Types>
    using nested_type = detail::nested_type<Types...>;

} // namespace variadic
