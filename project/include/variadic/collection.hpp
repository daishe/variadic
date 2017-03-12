//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

namespace variadic
{

    template <typename... Types>
    struct collection
    {
        template <template <typename...> typename Parent>
        using emplace = Parent<Types...>;

        template <template <typename> typename Wrapper>
        using wrap = collection<Wrapper<Types>...>;

        template <typename... OtherTypes>
        using push_back = collection<Types..., OtherTypes...>;

        template <typename... OtherTypes>
        using push_front = collection<OtherTypes..., Types...>;

        static constexpr size_t size = sizeof...(Types);
        static constexpr bool empty = sizeof...(Types) == 0;
    };

} // namespace variadic
