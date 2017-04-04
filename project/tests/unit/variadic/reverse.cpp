//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>

#include <variadic/reverse.hpp>

#include <type_traits>

BOOST_AUTO_TEST_CASE( variadic_reverse )
{
    static_assert(std::is_same<variadic::reverse<>::types, variadic::collection<>>::value, "Invalid reversion of collection for variadic::reverse");
    static_assert(std::is_same<variadic::reverse<char>::types, variadic::collection<char>>::value, "Invalid reversion of collection for variadic::reverse");
    static_assert(std::is_same<variadic::reverse<int, char>::types, variadic::collection<char, int>>::value, "Invalid reversion of collection for variadic::reverse");
    static_assert(std::is_same<variadic::reverse<float, int, char>::types, variadic::collection<char, int, float>>::value, "Invalid reversion of collection for variadic::reverse");
}