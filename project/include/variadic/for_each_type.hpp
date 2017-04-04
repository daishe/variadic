//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <type_traits>

#include <boost/none.hpp>

#include <variadic/for_each.hpp>
#include <variadic/type_frame.hpp>

namespace variadic
{

    template <typename... Types, typename Callback>
    inline Callback for_each_type(Callback callback)
    {
        for_each(
            [&callback](auto & t) {
                callback.operator ()<typename std::remove_reference<decltype(t)>::type::type>();
            },
            type_frame<Types>()...
        );
        return callback;
    }

} // namespace variadic
