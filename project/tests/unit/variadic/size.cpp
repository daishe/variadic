//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>

#include <variadic/size.hpp>

#include <type_traits>
#include <tuple>

#include <variadic/collection.hpp>

BOOST_AUTO_TEST_CASE( variadic_size )
{
    {
        static_assert(variadic::size<>::value == 0, "Invalid size deduction for variadic::size");
        static_assert(variadic::size<char, int, int>::value == 3, "Invalid size deduction for variadic::size");
    }

    {
        static_assert(variadic::pack_size<>::value == 0, "Invalid size deduction for variadic::pack_size");

        static_assert(variadic::pack_size<variadic::collection<>>::value == 0, "Invalid size deduction for variadic::pack_size");
        static_assert(variadic::pack_size<std::tuple<>>::value == 0, "Invalid size deduction for variadic::pack_size");
        static_assert(variadic::pack_size<variadic::collection<char, int, int>>::value == 3, "Invalid size deduction for variadic::pack_size");
        static_assert(variadic::pack_size<std::tuple<char, int, int>>::value == 3, "Invalid size deduction for variadic::pack_size");

        static_assert(variadic::pack_size<variadic::collection<>, variadic::collection<>>::value == 0, "Invalid size deduction for variadic::pack_size");
        static_assert(variadic::pack_size<variadic::collection<>, std::tuple<>>::value == 0, "Invalid size deduction for variadic::pack_size");
        static_assert(variadic::pack_size<variadic::collection<>, variadic::collection<char, int, int>>::value == 3, "Invalid size deduction for variadic::pack_size");
        static_assert(variadic::pack_size<variadic::collection<>, std::tuple<char, int, int>>::value == 3, "Invalid size deduction for variadic::pack_size");
        static_assert(variadic::pack_size<variadic::collection<char, int, int>, variadic::collection<>>::value == 3, "Invalid size deduction for variadic::pack_size");
        static_assert(variadic::pack_size<variadic::collection<char, int, int>, std::tuple<>>::value == 3, "Invalid size deduction for variadic::pack_size");
        static_assert(variadic::pack_size<variadic::collection<char, int, int>, variadic::collection<char, int, int>>::value == 6, "Invalid size deduction for variadic::pack_size");
        static_assert(variadic::pack_size<variadic::collection<char, int, int>, std::tuple<char, int, int>>::value == 6, "Invalid size deduction for variadic::pack_size");
        static_assert(variadic::pack_size<std::tuple<>, variadic::collection<>>::value == 0, "Invalid size deduction for variadic::pack_size");
        static_assert(variadic::pack_size<std::tuple<>, std::tuple<>>::value == 0, "Invalid size deduction for variadic::pack_size");
        static_assert(variadic::pack_size<std::tuple<>, variadic::collection<char, int, int>>::value == 3, "Invalid size deduction for variadic::pack_size");
        static_assert(variadic::pack_size<std::tuple<>, std::tuple<char, int, int>>::value == 3, "Invalid size deduction for variadic::pack_size");
        static_assert(variadic::pack_size<std::tuple<char, int, int>, variadic::collection<>>::value == 3, "Invalid size deduction for variadic::pack_size");
        static_assert(variadic::pack_size<std::tuple<char, int, int>, std::tuple<>>::value == 3, "Invalid size deduction for variadic::pack_size");
        static_assert(variadic::pack_size<std::tuple<char, int, int>, variadic::collection<char, int, int>>::value == 6, "Invalid size deduction for variadic::pack_size");
        static_assert(variadic::pack_size<std::tuple<char, int, int>, std::tuple<char, int, int>>::value == 6, "Invalid size deduction for variadic::pack_size");
    }
}