//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>

#include <variadic/back.hpp>

#include <type_traits>

BOOST_AUTO_TEST_CASE( variadic_back )
{
    static_assert(std::is_same<variadic::back<char>::type, char>::value, "1[/1]st item extraction failed for variadic::back");
    static_assert(std::is_same<variadic::back<char, int, float, double>::type, double>::value, "4th[/4] item extraction failed for variadic::back");

    static_assert(std::is_same<variadic::pop_back<char>::types, variadic::collection<>>::value, "Colleciton extraction failed for variadic::pop_back");
    static_assert(std::is_same<variadic::pop_back<char, int>::types::emplace<variadic::pop_back>::types, variadic::collection<>>::value, "Colleciton extraction failed for variadic::pop_back");
    static_assert(std::is_same<variadic::pop_back<char, int, float>::types, variadic::collection<char, int>>::value, "Colleciton extraction failed for variadic::pop_back");
}