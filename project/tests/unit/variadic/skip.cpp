//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>

#include <variadic/skip.hpp>

#include <type_traits>

BOOST_AUTO_TEST_CASE( variadic_skip )
{
    static_assert(std::is_same<variadic::skip<0>::front<>, variadic::collection<>>::value, "Invalid skip of colleciotn item(s) for variadic::skip::front");

    static_assert(std::is_same<variadic::skip<0>::front<char>, variadic::collection<char>>::value, "Invalid skip of colleciotn item(s) for variadic::skip::front");
    static_assert(std::is_same<variadic::skip<1>::front<char>, variadic::collection<>>::value, "Invalid skip of colleciotn item(s) for variadic::skip::front");

    static_assert(std::is_same<variadic::skip<0>::front<char, int, float, int, double>, variadic::collection<char, int, float, int, double>>::value,   "Invalid skip of colleciotn item(s) for variadic::skip::front");
    static_assert(std::is_same<variadic::skip<1>::front<char, int, float, int, double>, variadic::collection<int, float, int, double>>::value,    "Invalid skip of colleciotn item(s) for variadic::skip::front");
    static_assert(std::is_same<variadic::skip<2>::front<char, int, float, int, double>, variadic::collection<float, int, double>>::value,  "Invalid skip of colleciotn item(s) for variadic::skip::front");
    static_assert(std::is_same<variadic::skip<3>::front<char, int, float, int, double>, variadic::collection<int, double>>::value,    "Invalid skip of colleciotn item(s) for variadic::skip::front");
    static_assert(std::is_same<variadic::skip<4>::front<char, int, float, int, double>, variadic::collection<double>>::value, "Invalid skip of colleciotn item(s) for variadic::skip::front");
    static_assert(std::is_same<variadic::skip<5>::front<char, int, float, int, double>, variadic::collection<>>::value, "Invalid skip of colleciotn item(s) for variadic::skip::front");

    static_assert(std::is_same<variadic::skip<0>::back<>, variadic::collection<>>::value, "Invalid skip of colleciotn item(s) for variadic::skip::back");

    static_assert(std::is_same<variadic::skip<0>::back<char>, variadic::collection<char>>::value, "Invalid skip of colleciotn item(s) for variadic::skip::back");
    static_assert(std::is_same<variadic::skip<1>::back<char>, variadic::collection<>>::value, "Invalid skip of colleciotn item(s) for variadic::skip::back");

    static_assert(std::is_same<variadic::skip<0>::back<char, int, float, int, double>, variadic::collection<char, int, float, int, double>>::value,   "Invalid skip of colleciotn item(s) for variadic::skip::back");
    static_assert(std::is_same<variadic::skip<1>::back<char, int, float, int, double>, variadic::collection<char, int, float, int>>::value,    "Invalid skip of colleciotn item(s) for variadic::skip::back");
    static_assert(std::is_same<variadic::skip<2>::back<char, int, float, int, double>, variadic::collection<char, int, float>>::value,  "Invalid skip of colleciotn item(s) for variadic::skip::back");
    static_assert(std::is_same<variadic::skip<3>::back<char, int, float, int, double>, variadic::collection<char, int>>::value,    "Invalid skip of colleciotn item(s) for variadic::skip::back");
    static_assert(std::is_same<variadic::skip<4>::back<char, int, float, int, double>, variadic::collection<char>>::value, "Invalid skip of colleciotn item(s) for variadic::skip::back");
    static_assert(std::is_same<variadic::skip<5>::back<char, int, float, int, double>, variadic::collection<>>::value, "Invalid skip of colleciotn item(s) for variadic::skip::back");
}