//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <variadic/def.hpp>

namespace variadic
{

    namespace detail
    {

        template <typename Pack>
        struct pack_size_impl
        {};

        template <template <typename...> typename Pack, typename... Packed>
        struct pack_size_impl<Pack<Packed...>>
        {
            static constexpr size_t value = sizeof...(Packed);
        };

        template <size_t... Values>
        constexpr size_t pack_size_impl__sum()
        {
            constexpr size_t values[] {Values...};

            size_t res = 0;
            for (size_t i = 0; i < sizeof...(Values); ++i)
                res += values[i];
            return res;
        };

    } // namespace detail

    template <typename... Types>
    struct size
    {
        static constexpr size_t value = sizeof...(Types);
    };

    template <typename... Packs>
    struct pack_size
    {
        static constexpr size_t value = detail::pack_size_impl__sum<detail::pack_size_impl<Packs>::value...>();
    };

} // namespace variadic