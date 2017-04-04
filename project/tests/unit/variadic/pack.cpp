//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>

#include <variadic/pack.hpp>

#include <type_traits>
#include <tuple>

#include <variadic/collection.hpp>

BOOST_AUTO_TEST_CASE( variadic_pack )
{
    static_assert(std::is_same<variadic::pack<>::types, variadic::collection<>>::value, "Invalid pack creation for variadic::pack");
    static_assert(std::is_same<variadic::pack<char, int, int>::types, variadic::collection<char, int, int>>::value, "Invalid pack creation for variadic::pack");

    static_assert(std::is_same<variadic::unpack<std::tuple<>>::types, variadic::collection<>>::value, "Invalid pack extraction for variadic::unpack");
    static_assert(std::is_same<variadic::unpack<std::tuple<char, int, int>>::types, variadic::collection<char, int, int>>::value, "Invalid pack extraction for variadic::unpack");
    static_assert(std::is_same<variadic::unpack<variadic::collection<>>::types, variadic::collection<>>::value, "Invalid pack extraction for variadic::unpack");
    static_assert(std::is_same<variadic::unpack<variadic::collection<char, int, int>>::types, variadic::collection<char, int, int>>::value, "Invalid pack extraction for variadic::unpack");
}