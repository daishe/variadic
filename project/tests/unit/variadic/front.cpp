//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>

#include <variadic/front.hpp>

#include <type_traits>

BOOST_AUTO_TEST_CASE( variadic_front )
{
    static_assert(std::is_same<variadic::front<char>::type, char>::value, "1[/1]st item extraction failed for variadic::front");
    static_assert(std::is_same<variadic::front<char, int, float, double>::type, char>::value, "1st[/4] item extraction failed for variadic::front");

    static_assert(std::is_same<variadic::pop_front<char>::types, variadic::collection<>>::value, "Colleciton extraction failed for variadic::pop_front");
    static_assert(std::is_same<variadic::pop_front<char, int>::types::emplace<variadic::pop_front>::types, variadic::collection<>>::value, "Colleciton extraction failed for variadic::pop_front");
    static_assert(std::is_same<variadic::pop_front<char, int, float>::types, variadic::collection<int, float>>::value, "Colleciton extraction failed for variadic::pop_front");
}