//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

namespace variadic
{

    template <size_t Value>
    struct size_type
    {
        static constexpr size_t value = Value;
    };

} // namespace variadic