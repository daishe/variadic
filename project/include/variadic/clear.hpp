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
        struct pack_clear_impl
        {};

        template <template <typename...> typename Pack, typename... Packed>
        struct pack_clear_impl<Pack<Packed...>>
        {
            template <typename... Types>
            using type = Pack<Types...>;
        };

    } // namespace detail

    template <typename Pack>
    struct pack_clear
    {
        template <typename... Types>
        using type = typename detail::pack_clear_impl<Pack>::template type<Types...>;
    };

} // namespace variadic