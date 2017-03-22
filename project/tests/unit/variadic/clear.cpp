//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>

#include <variadic/clear.hpp>

#include <type_traits>
#include <tuple>

#include <variadic/collection.hpp>
#include <variadic/type_frame.hpp>

BOOST_AUTO_TEST_CASE( variadic_clear )
{
    static_assert(std::is_same<variadic::ttf<variadic::pack_clear<std::tuple<>>::type>, variadic::ttf<std::tuple>>::value, "Invalid pack extraction for variadic::pack_clear");
    static_assert(std::is_same<variadic::ttf<variadic::pack_clear<std::tuple<char, int, int>>::type>, variadic::ttf<std::tuple>>::value, "Invalid pack extraction for variadic::pack_clear");
    static_assert(std::is_same<variadic::ttf<variadic::pack_clear<variadic::collection<>>::type>, variadic::ttf<variadic::collection>>::value, "Invalid pack extraction for variadic::pack_clear");
    static_assert(std::is_same<variadic::ttf<variadic::pack_clear<variadic::collection<char, int, int>>::type>, variadic::ttf<variadic::collection>>::value, "Invalid pack extraction for variadic::pack_clear");
}