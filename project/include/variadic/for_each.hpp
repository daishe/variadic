//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <initializer_list>
#include <type_traits>

#include <boost/none.hpp>

namespace variadic
{

    template <typename Callback, typename... Types>
    inline Callback for_each(Callback callback, Types&... types)
    {
        std::initializer_list<boost::none_t> ({
            [](Callback & c, auto & t) -> boost::none_t {
                c(t);
                return boost::none;
            }(callback, types)...
        });
        return callback;
    }

    template <typename Callback, typename... Types>
    inline Callback for_each(Callback callback, const Types&... types)
    {
        std::initializer_list<boost::none_t> ({
            [](Callback & c, const auto & t) -> boost::none_t {
                c(t);
                return boost::none;
            }(callback, types)...
        });
        return callback;
    }

} // namespace variadic
