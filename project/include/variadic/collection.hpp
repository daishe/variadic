//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <variadic/def.hpp>

namespace variadic
{

    ///
    /// \brief      Handler for a collection of types
    ///
    /// \tparam     Types  collection types
    ///
    template <typename... Types>
    struct collection
    {
        ///
        /// \brief      Self typedef
        ///
        /// Considering collection `c` of types `t0`, `t1` and `t2` (`typedef collection<t0, t1, t2> c`), expression `c::types` is equivalent to `collection<t0, t1, t2>`.
        ///
        using types = collection<Types...>;

        ///
        /// \brief      Emplace collection in another handler
        ///
        /// Considering collection `c` of types `t0`, `t1` and `t2` (`typedef collection<t0, t1, t2> c`), expression `c::emplace<std::tuple>` is equivalent to `std::tuple<t0, t1, t2>`.
        ///
        template <template <typename...> typename Parent>
        using emplace = Parent<Types...>;

        ///
        /// \brief      Wrap every item with wrapping type
        ///
        /// Considering collection `c` of types `t0`, `t1` and `t2` (`typedef collection<t0, t1, t2> c`), expression `c::wrap<std::uinque_ptr>` is equivalent to `collection<std::uinque_ptr<t0>, std::uinque_ptr<t1>, std::uinque_ptr<t2>>`.
        ///
        template <template <typename> typename Wrapper>
        using wrap = collection<Wrapper<Types>...>;

        ///
        /// \brief      Pushes item to back of collection
        ///
        /// Considering collection `c` of types `t0`, `t1` and `t2` (`typedef collection<t0, t1, t2> c`) and types `ot0`, `ot1`:
        ///  - expression `c::push_back<>` is equivalent to `collection<t0, t1, t2>`,
        ///  - expression `c::push_back<ot0>` is equivalent to `collection<t0, t1, t2, ot0>`,
        ///  - expression `c::push_back<ot0, ot1>` is equivalent to `collection<t0, t1, t2, ot0, ot1>`.
        ///
        template <typename... OtherTypes>
        using push_back = collection<Types..., OtherTypes...>;

        ///
        /// \brief      Pushes item to front of collection
        ///
        /// Considering collection `c` of types `t0`, `t1` and `t2` (`typedef collection<t0, t1, t2> c`) and types `ot0`, `ot1`:
        ///  - expression `c::push_front<>` is equivalent to `collection<t0, t1, t2>`,
        ///  - expression `c::push_front<ot0>` is equivalent to `collection<ot0, t0, t1, t2>`,
        ///  - expression `c::push_front<ot0, ot1>` is equivalent to `collection<ot0, ot1, t0, t1, t2>`.
        ///
        template <typename... OtherTypes>
        using push_front = collection<OtherTypes..., Types...>;

        ///
        /// \brief      Allow to access nth item in collection
        ///
        /// Considering collection `c` of types `t0`, `t1` and `t2` (`typedef collection<t0, t1, t2> c`):
        ///  - expression `c::at<0>` is equivalent to `t0`,
        ///  - expression `c::at<1>` is equivalent to `t1`,
        ///  - expression `c::at<2>` is equivalent to `t2`,
        ///  - putting any value `N`, other than 0, 1 or 2, as template parameter to `c::at<N>` cause compilation error.
        ///
        /// Expression `collection<>::at<N>` for any value `N` (for empty collection), cause compilation error.
        ///
        template <size_t Idx>
        using at = typename at<Idx, Types...>::type;

        ///
        /// \brief      Allow to access first item in collection
        ///
        /// Considering collection `c` of types `t0`, `t1` and `t2` (`typedef collection<t0, t1, t2> c`), expression `c::front<>` is equivalent to `t0`.
        ///
        /// Expression `collection<>::front<>` (for empty collection), cause compilation error.
        ///
        template <template <typename...> typename Extractor = front>
        using front = typename Extractor<Types...>::type;

        ///
        /// \brief      Equivalent to collection with first item from current collection extracted
        ///
        /// Considering collection `c` of types `t0`, `t1` and `t2` (`typedef collection<t0, t1, t2> c`), expression `c::pop_front<>` is equivalent to `collection<t1, t2>`.
        ///
        /// Expression `collection<>::pop_front<>` (for empty collection), cause compilation error.
        ///
        template <template <typename...> typename Extractor = pop_front>
        using pop_front = typename Extractor<Types...>::types;

        ///
        /// \brief      Allow to access last item in collection
        ///
        /// Considering collection `c` of types `t0`, `t1` and `t2` (`typedef collection<t0, t1, t2> c`), expression `c::back<>` is equivalent to `t2`.
        ///
        /// Expression `collection<>::back<>` (for empty collection), cause compilation error.
        ///
        template <template <typename...> typename Extractor = back>
        using back = typename Extractor<Types...>::type;

        ///
        /// \brief      Equivalent to collection with last item from current collection extracted
        ///
        /// Considering collection `c` of types `t0`, `t1` and `t2` (`typedef collection<t0, t1, t2> c`), expression `c::pop_back<>` is equivalent to `collection<t0, t1>`.
        ///
        /// Expression `collection<>::pop_back<>` (for empty collection), cause compilation error.
        ///
        template <template <typename...> typename Extractor = pop_back>
        using pop_back = typename Extractor<Types...>::types;

        ///
        /// \brief      Size of collection
        ///
        static constexpr size_t size = sizeof...(Types);

        ///
        /// \brief      true if collection is empty, false otherwise
        ///
        static constexpr bool empty = sizeof...(Types) == 0;
    };

} // namespace variadic
