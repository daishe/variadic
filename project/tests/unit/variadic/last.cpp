//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>

#include <variadic/last.hpp>

#include <type_traits>

BOOST_AUTO_TEST_CASE( variadic_last )
{
    static_assert(std::is_same<variadic::last<char>::type, char>::value, "1[/1]st item extraction failed for variadic::last");
    static_assert(std::is_same<variadic::last<char, int, float, double>::type, double>::value, "4th[/4] item extraction failed for variadic::last");

    static_assert(std::is_same<variadic::not_last<char>, variadic::collection<>>::value, "Colleciton extraction failed for variadic::not_last");
    static_assert(std::is_same<variadic::not_last<char, int>::emplace<variadic::not_last>, variadic::collection<>>::value, "Colleciton extraction failed for variadic::not_last");
    static_assert(std::is_same<variadic::not_last<char, int, float>, variadic::collection<char, int>>::value, "Colleciton extraction failed for variadic::not_last");
}