//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

namespace variadic
{

    namespace extract
    {

        template <typename T>
        using none = T;

        template <typename T>
        using type = typename T::type;

        template <typename T>
        using value = typename T::value;

    } // namespace extract

} // namespace variadic
