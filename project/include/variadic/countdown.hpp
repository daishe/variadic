//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

namespace variadic
{

    namespace countdown
    {

        typedef bool condition_type;

        constexpr condition_type final_value    = true;
        constexpr condition_type continue_value = false;

        template <typename T>
        constexpr condition_type condition(T value)
        {
            return value == 0;
        };

    } // namespace countdown

} // namespace variadic
