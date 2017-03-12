//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>

#include <variadic/first.hpp>

#include <type_traits>

BOOST_AUTO_TEST_CASE( variadic_first )
{
    static_assert(std::is_same<variadic::first<char>::type, char>::value, "1[/1]st item extraction failed for variadic::first");
    static_assert(std::is_same<variadic::first<char, int, float, double>::type, char>::value, "1st[/4] item extraction failed for variadic::first");

    static_assert(std::is_same<variadic::not_first<char>, variadic::collection<>>::value, "Colleciton extraction failed for variadic::not_first");
    static_assert(std::is_same<variadic::not_first<char, int, float>, variadic::collection<int, float>>::value, "Colleciton extraction failed for variadic::not_first");
}