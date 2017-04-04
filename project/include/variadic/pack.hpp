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

        template <typename Pack>
        struct unpack_impl
        {};

        template <template <typename...> typename Pack, typename... Packed>
        struct unpack_impl<Pack<Packed...>>
        {
            template <typename... Types>
            using parent = Pack<Types...>;

            using types = collection<Packed...>;
        };

    } // namespace detail

    template <typename... Types>
    struct pack
    {
        using types = collection<Types...>;
    };

    template <typename Pack>
    struct unpack
    {
        using types = typename detail::unpack_impl<Pack>::types;
    };

} // namespace variadic