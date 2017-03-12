//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

namespace variadic
{

    template <typename T>
    struct type_frame
    {
        typedef T type;
    };

    template <template<typename...> typename T>
    struct templated_type_frame
    {
        template <typename... Types>
        using type = T<Types...>;
    };

} // namespace variadic
