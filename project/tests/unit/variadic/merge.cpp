//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>

#include <variadic/merge.hpp>

#include <type_traits>

BOOST_AUTO_TEST_CASE( variadic_merge )
{
    typedef variadic::collection<char, int, int> c0;
    typedef variadic::collection<float, double> c1;
    typedef variadic::collection<> c2;

    {
        static_assert(std::is_same<variadic::merge<>, variadic::collection<>>::value, "Invalid merge of collections for variadic::merge");

        static_assert(std::is_same<variadic::merge<c0>, variadic::collection<char, int, int>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c1>, variadic::collection<float, double>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c2>, variadic::collection<>>::value, "Invalid merge of collections for variadic::merge");

        static_assert(std::is_same<variadic::merge<c0, c0>, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c0, c1>, variadic::collection<char, int, int, float, double>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c0, c2>, variadic::collection<char, int, int>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c1, c0>, variadic::collection<float, double, char, int, int>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c1, c1>, variadic::collection<float, double, float, double>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c1, c2>, variadic::collection<float, double>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c2, c0>, variadic::collection<char, int, int>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c2, c1>, variadic::collection<float, double>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c2, c2>, variadic::collection<>>::value, "Invalid merge of collections for variadic::merge");

        static_assert(std::is_same<variadic::merge<c0, c0, c0>, variadic::collection<char, int, int, char, int, int, char, int, int>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c0, c0, c1>, variadic::collection<char, int, int, char, int, int, float, double>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c0, c0, c2>, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c0, c1, c0>, variadic::collection<char, int, int, float, double, char, int, int>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c0, c1, c1>, variadic::collection<char, int, int, float, double, float, double>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c0, c1, c2>, variadic::collection<char, int, int, float, double>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c0, c2, c0>, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c0, c2, c1>, variadic::collection<char, int, int, float, double>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c0, c2, c2>, variadic::collection<char, int, int>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c1, c0, c0>, variadic::collection<float, double, char, int, int, char, int, int>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c1, c0, c1>, variadic::collection<float, double, char, int, int, float, double>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c1, c0, c2>, variadic::collection<float, double, char, int, int>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c1, c1, c0>, variadic::collection<float, double, float, double, char, int, int>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c1, c1, c1>, variadic::collection<float, double, float, double, float, double>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c1, c1, c2>, variadic::collection<float, double, float, double>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c1, c2, c0>, variadic::collection<float, double, char, int, int>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c1, c2, c1>, variadic::collection<float, double, float, double>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c1, c2, c2>, variadic::collection<float, double>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c2, c0, c0>, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c2, c0, c1>, variadic::collection<char, int, int, float, double>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c2, c0, c2>, variadic::collection<char, int, int>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c2, c1, c0>, variadic::collection<float, double, char, int, int>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c2, c1, c1>, variadic::collection<float, double, float, double>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c2, c1, c2>, variadic::collection<float, double>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c2, c2, c0>, variadic::collection<char, int, int>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c2, c2, c1>, variadic::collection<float, double>>::value, "Invalid merge of collections for variadic::merge");
        static_assert(std::is_same<variadic::merge<c2, c2, c2>, variadic::collection<>>::value, "Invalid merge of collections for variadic::merge");
    }

    {
        static_assert(std::is_same<variadic::merge_types<>::types, variadic::collection<>>::value, "Invalid merge of types for variadic::merge_types");
        static_assert(std::is_same<variadic::merge_types<>::with<>::types, variadic::collection<>>::value, "Invalid merge of types for variadic::merge_types");
        static_assert(std::is_same<variadic::merge_types<>::with<char, int, int>::types, variadic::collection<char, int, int>>::value, "Invalid merge of types for variadic::merge_types");

        static_assert(std::is_same<variadic::merge_types<>::with_collection<>::types, variadic::collection<>>::value, "Invalid merge of types for variadic::merge_types");

        static_assert(std::is_same<variadic::merge_types<>::with_collection<c0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of types for variadic::merge_types");
        static_assert(std::is_same<variadic::merge_types<>::with_collection<c1>::types, variadic::collection<float, double>>::value, "Invalid merge of types for variadic::merge_types");
        static_assert(std::is_same<variadic::merge_types<>::with_collection<c2>::types, variadic::collection<>>::value, "Invalid merge of types for variadic::merge_types");

        static_assert(std::is_same<variadic::merge_types<>::with_collection<c0, c0>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of types for variadic::merge_types");
        static_assert(std::is_same<variadic::merge_types<>::with_collection<c0, c1>::types, variadic::collection<char, int, int, float, double>>::value, "Invalid merge of types for variadic::merge_types");
        static_assert(std::is_same<variadic::merge_types<>::with_collection<c0, c2>::types, variadic::collection<char, int, int>>::value, "Invalid merge of types for variadic::merge_types");
        static_assert(std::is_same<variadic::merge_types<>::with_collection<c1, c0>::types, variadic::collection<float, double, char, int, int>>::value, "Invalid merge of types for variadic::merge_types");
        static_assert(std::is_same<variadic::merge_types<>::with_collection<c1, c1>::types, variadic::collection<float, double, float, double>>::value, "Invalid merge of types for variadic::merge_types");
        static_assert(std::is_same<variadic::merge_types<>::with_collection<c1, c2>::types, variadic::collection<float, double>>::value, "Invalid merge of types for variadic::merge_types");
        static_assert(std::is_same<variadic::merge_types<>::with_collection<c2, c0>::types, variadic::collection<char, int, int>>::value, "Invalid merge of types for variadic::merge_types");
        static_assert(std::is_same<variadic::merge_types<>::with_collection<c2, c1>::types, variadic::collection<float, double>>::value, "Invalid merge of types for variadic::merge_types");
        static_assert(std::is_same<variadic::merge_types<>::with_collection<c2, c2>::types, variadic::collection<>>::value, "Invalid merge of types for variadic::merge_types");

        static_assert(std::is_same<variadic::merge_types<char, int, int>::types, variadic::collection<char, int, int>>::value, "Invalid merge of types for variadic::merge_types");
        static_assert(std::is_same<variadic::merge_types<char, int, int>::with<float, double>::types, variadic::collection<char, int, int, float, double>>::value, "Invalid merge of types for variadic::merge_types");

        static_assert(std::is_same<variadic::merge_types<char, int, int>::with_collection<c0>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of types for variadic::merge_types");
        static_assert(std::is_same<variadic::merge_types<char, int, int>::with_collection<c1>::types, variadic::collection<char, int, int, float, double>>::value, "Invalid merge of types for variadic::merge_types");
        static_assert(std::is_same<variadic::merge_types<char, int, int>::with_collection<c2>::types, variadic::collection<char, int, int>>::value, "Invalid merge of types for variadic::merge_types");

        static_assert(std::is_same<variadic::merge_types<char, int, int>::with_collection<c0, c0>::types, variadic::collection<char, int, int, char, int, int, char, int, int>>::value, "Invalid merge of types for variadic::merge_types");
        static_assert(std::is_same<variadic::merge_types<char, int, int>::with_collection<c0, c1>::types, variadic::collection<char, int, int, char, int, int, float, double>>::value, "Invalid merge of types for variadic::merge_types");
        static_assert(std::is_same<variadic::merge_types<char, int, int>::with_collection<c0, c2>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of types for variadic::merge_types");
        static_assert(std::is_same<variadic::merge_types<char, int, int>::with_collection<c1, c0>::types, variadic::collection<char, int, int, float, double, char, int, int>>::value, "Invalid merge of types for variadic::merge_types");
        static_assert(std::is_same<variadic::merge_types<char, int, int>::with_collection<c1, c1>::types, variadic::collection<char, int, int, float, double, float, double>>::value, "Invalid merge of types for variadic::merge_types");
        static_assert(std::is_same<variadic::merge_types<char, int, int>::with_collection<c1, c2>::types, variadic::collection<char, int, int, float, double>>::value, "Invalid merge of types for variadic::merge_types");
        static_assert(std::is_same<variadic::merge_types<char, int, int>::with_collection<c2, c0>::types, variadic::collection<char, int, int, char, int, int>>::value, "Invalid merge of types for variadic::merge_types");
        static_assert(std::is_same<variadic::merge_types<char, int, int>::with_collection<c2, c1>::types, variadic::collection<char, int, int, float, double>>::value, "Invalid merge of types for variadic::merge_types");
        static_assert(std::is_same<variadic::merge_types<char, int, int>::with_collection<c2, c2>::types, variadic::collection<char, int, int>>::value, "Invalid merge of types for variadic::merge_types");
    }
}