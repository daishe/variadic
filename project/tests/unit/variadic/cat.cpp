//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>

#include <variadic/cat.hpp>

#include <tuple>
#include <type_traits>

BOOST_AUTO_TEST_CASE( variadic_cat )
{
    typedef variadic::collection<> c0;
    typedef std::tuple<> t0;
    typedef variadic::collection<char, int, int> c1;
    typedef std::tuple<char, int, int> t1;


    {
        static_assert(std::is_same<variadic::pack_cat<>::types, variadic::collection<>>::value, "Invalid merge of packs for variadic::pack_cat");

        static_assert(std::is_same<variadic::pack_cat<c0>::types, variadic::collection<>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t0>::types, variadic::collection<>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c1>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t1>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");

        static_assert(std::is_same<variadic::pack_cat<c0, c0>::types, variadic::collection<>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c0, t0>::types, variadic::collection<>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c0, c1>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c0, t1>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t0, c0>::types, variadic::collection<>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t0, t0>::types, variadic::collection<>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t0, c1>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t0, t1>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c1, c0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c1, t0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c1, c1>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c1, t1>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t1, c0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t1, t0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t1, c1>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t1, t1>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");

        static_assert(std::is_same<variadic::pack_cat<c0, c0, c0>::types, variadic::collection<>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c0, c0, t0>::types, variadic::collection<>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c0, c0, c1>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c0, c0, t1>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c0, t0, c0>::types, variadic::collection<>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c0, t0, t0>::types, variadic::collection<>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c0, t0, c1>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c0, t0, t1>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c0, c1, c0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c0, c1, t0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c0, c1, c1>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c0, c1, t1>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c0, t1, c0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c0, t1, t0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c0, t1, c1>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c0, t1, t1>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t0, c0, c0>::types, variadic::collection<>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t0, c0, t0>::types, variadic::collection<>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t0, c0, c1>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t0, c0, t1>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t0, t0, c0>::types, variadic::collection<>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t0, t0, t0>::types, variadic::collection<>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t0, t0, c1>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t0, t0, t1>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t0, c1, c0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t0, c1, t0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t0, c1, c1>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t0, c1, t1>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t0, t1, c0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t0, t1, t0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t0, t1, c1>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t0, t1, t1>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c1, c0, c0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c1, c0, t0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c1, c0, c1>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c1, c0, t1>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c1, t0, c0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c1, t0, t0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c1, t0, c1>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c1, t0, t1>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c1, c1, c0>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c1, c1, t0>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c1, c1, c1>::types, variadic::collection<char, int, int, char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c1, c1, t1>::types, variadic::collection<char, int, int, char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c1, t1, c0>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c1, t1, t0>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c1, t1, c1>::types, variadic::collection<char, int, int, char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<c1, t1, t1>::types, variadic::collection<char, int, int, char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t1, c0, c0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t1, c0, t0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t1, c0, c1>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t1, c0, t1>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t1, t0, c0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t1, t0, t0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t1, t0, c1>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t1, t0, t1>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t1, c1, c0>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t1, c1, t0>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t1, c1, c1>::types, variadic::collection<char, int, int, char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t1, c1, t1>::types, variadic::collection<char, int, int, char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t1, t1, c0>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t1, t1, t0>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t1, t1, c1>::types, variadic::collection<char, int, int, char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
        static_assert(std::is_same<variadic::pack_cat<t1, t1, t1>::types, variadic::collection<char, int, int, char, int, int, char, int, int>>::value, "Invalid merge of packs for variadic::pack_cat");
    }

    {
        static_assert(std::is_same<variadic::cat<>::types, variadic::collection<>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<>::with<>::types, variadic::collection<>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<>::with<char, int, int>::types, variadic::collection<char, int, int>>::value, "Invalid merge of types for variadic::cat");

        static_assert(std::is_same<variadic::cat<>::with_pack<>::types, variadic::collection<>>::value, "Invalid merge of types for variadic::cat");

        static_assert(std::is_same<variadic::cat<>::with_pack<c0>::types, variadic::collection<>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<>::with_pack<t0>::types, variadic::collection<>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<>::with_pack<c1>::types, variadic::collection<char, int, int>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<>::with_pack<t1>::types, variadic::collection<char, int, int>>::value, "Invalid merge of types for variadic::cat");

        static_assert(std::is_same<variadic::cat<>::with_pack<c0, c0>::types, variadic::collection<>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<>::with_pack<c0, t0>::types, variadic::collection<>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<>::with_pack<c0, c1>::types, variadic::collection<char, int, int>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<>::with_pack<c0, t1>::types, variadic::collection<char, int, int>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<>::with_pack<t0, c0>::types, variadic::collection<>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<>::with_pack<t0, t0>::types, variadic::collection<>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<>::with_pack<t0, c1>::types, variadic::collection<char, int, int>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<>::with_pack<t0, t1>::types, variadic::collection<char, int, int>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<>::with_pack<c1, c0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<>::with_pack<c1, t0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<>::with_pack<c1, c1>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<>::with_pack<c1, t1>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<>::with_pack<t1, c0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<>::with_pack<t1, t0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<>::with_pack<t1, c1>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<>::with_pack<t1, t1>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of types for variadic::cat");

        static_assert(std::is_same<variadic::cat<float, double>::types, variadic::collection<float, double>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<float, double>::with<char, int, int>::types, variadic::collection<float, double, char, int, int>>::value, "Invalid merge of types for variadic::cat");

        static_assert(std::is_same<variadic::cat<float, double>::with_pack<c0>::types, variadic::collection<float, double>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<float, double>::with_pack<t0>::types, variadic::collection<float, double>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<float, double>::with_pack<c1>::types, variadic::collection<float, double, char, int, int>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<float, double>::with_pack<t1>::types, variadic::collection<float, double, char, int, int>>::value, "Invalid merge of types for variadic::cat");

        static_assert(std::is_same<variadic::cat<float, double>::with_pack<c0, c0>::types, variadic::collection<float, double>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<float, double>::with_pack<c0, t0>::types, variadic::collection<float, double>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<float, double>::with_pack<c0, c1>::types, variadic::collection<float, double, char, int, int>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<float, double>::with_pack<c0, t1>::types, variadic::collection<float, double, char, int, int>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<float, double>::with_pack<t0, c0>::types, variadic::collection<float, double>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<float, double>::with_pack<t0, t0>::types, variadic::collection<float, double>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<float, double>::with_pack<t0, c1>::types, variadic::collection<float, double, char, int, int>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<float, double>::with_pack<t0, t1>::types, variadic::collection<float, double, char, int, int>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<float, double>::with_pack<c1, c0>::types, variadic::collection<float, double, char, int, int>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<float, double>::with_pack<c1, t0>::types, variadic::collection<float, double, char, int, int>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<float, double>::with_pack<c1, c1>::types, variadic::collection<float, double, char, int, int, char, int, int>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<float, double>::with_pack<c1, t1>::types, variadic::collection<float, double, char, int, int, char, int, int>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<float, double>::with_pack<t1, c0>::types, variadic::collection<float, double, char, int, int>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<float, double>::with_pack<t1, t0>::types, variadic::collection<float, double, char, int, int>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<float, double>::with_pack<t1, c1>::types, variadic::collection<float, double, char, int, int, char, int, int>>::value, "Invalid merge of types for variadic::cat");
        static_assert(std::is_same<variadic::cat<float, double>::with_pack<t1, t1>::types, variadic::collection<float, double, char, int, int, char, int, int>>::value, "Invalid merge of types for variadic::cat");
    }
}