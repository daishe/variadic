//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>

#include <variadic/collection.hpp>

#include <tuple>
#include <type_traits>

#include <variadic/type_frame.hpp>
#include <variadic/size.hpp>

namespace variadic_collection_test
{

    struct a
    {};

    struct b
    {};

    struct c
    {};

} // namespace variadic_collection_test

BOOST_AUTO_TEST_CASE( variadic_collection )
{
    using namespace variadic_collection_test;

    {
        static_assert(
            std::is_same<variadic::collection<>::types, variadic::collection<>>::value,
            "Empty collection self type not correctly mapped to the same empty collection"
        );
        static_assert(
            std::is_same<variadic::collection<a, b, c>::types, variadic::collection<a, b, c>>::value,
            "Collection self type not correctly mapped to the same collection"
        );
        static_assert(
            std::is_same<variadic::collection<a, b, c, c, b, a>::types, variadic::collection<a, b, c, c, b, a>>::value,
            "Collection self type not correctly mapped to the same collection"
        );
    }

    {
        static_assert(
            std::is_same<variadic::collection<>::emplace<std::tuple>, std::tuple<>>::value,
            "Empty collection not mapped to valid empty tuple"
        );
        static_assert(
            std::is_same<variadic::collection<a, b, c>::emplace<std::tuple>, std::tuple<a, b, c>>::value,
            "Collection not mapped to valid tuple"
        );
        static_assert(
            std::is_same<variadic::collection<a, b, c, c, b, a>::emplace<std::tuple>, std::tuple<a, b, c, c, b, a>>::value,
            "Collection not mapped to valid tuple"
        );
    }

    {
        static_assert(
            std::is_same<variadic::collection<>::wrap<variadic::tf>::emplace<std::tuple>, std::tuple<>>::value,
            "Not mapped to valid tuple after wrap in tf (variadic::type_frame)"
        );
        static_assert(
            std::is_same<variadic::collection<a, b, c>::wrap<variadic::tf>::emplace<std::tuple>, std::tuple<variadic::tf<a>, variadic::tf<b>, variadic::tf<c>>>::value,
            "Not mapped to valid tuple after wrap in tf (variadic::type_frame)"
        );
        static_assert(
            std::is_same<variadic::collection<a, b, c, c, b, a>::wrap<variadic::tf>::emplace<std::tuple>, std::tuple<variadic::tf<a>, variadic::tf<b>, variadic::tf<c>, variadic::tf<c>, variadic::tf<b>, variadic::tf<a>>>::value,
            "Not mapped to valid tuple after wrap in variadic::tf (variadic::type_frame)"
        );
    }

    {
        static_assert(
            std::is_same<variadic::collection<>::push_front<>::emplace<std::tuple>, std::tuple<>>::value,
            "Not mapped to valid tuple after push_front"
        );
        static_assert(
            std::is_same<variadic::collection<>::push_front<b>::emplace<std::tuple>, std::tuple<b>>::value,
            "Not mapped to valid tuple after push_front"
        );
        static_assert(
            std::is_same<variadic::collection<>::push_front<c, b, a>::emplace<std::tuple>, std::tuple<c, b, a>>::value,
            "Not mapped to valid tuple after push_front"
        );

        static_assert(
            std::is_same<variadic::collection<a, b, c>::push_front<>::emplace<std::tuple>, std::tuple<a, b, c>>::value,
            "Not mapped to valid tuple after push_front"
        );
        static_assert(
            std::is_same<variadic::collection<a, b, c>::push_front<b>::emplace<std::tuple>, std::tuple<b, a, b, c>>::value,
            "Not mapped to valid tuple after push_front"
        );
        static_assert(
            std::is_same<variadic::collection<a, b, c>::push_front<c, b, a>::emplace<std::tuple>, std::tuple<c, b, a, a, b, c>>::value,
            "Not mapped to valid tuple after push_front"
        );
    }

    {
        static_assert(
            std::is_same<variadic::collection<>::push_back<>::emplace<std::tuple>, std::tuple<>>::value,
            "Not mapped to valid tuple after push_back"
        );
        static_assert(
            std::is_same<variadic::collection<>::push_back<b>::emplace<std::tuple>, std::tuple<b>>::value,
            "Not mapped to valid tuple after push_back"
        );
        static_assert(
            std::is_same<variadic::collection<>::push_back<c, b, a>::emplace<std::tuple>, std::tuple<c, b, a>>::value,
            "Not mapped to valid tuple after push_back"
        );

        static_assert(
            std::is_same<variadic::collection<a, b, c>::push_back<>::emplace<std::tuple>, std::tuple<a, b, c>>::value,
            "Not mapped to valid tuple after push_back"
        );
        static_assert(
            std::is_same<variadic::collection<a, b, c>::push_back<b>::emplace<std::tuple>, std::tuple<a, b, c, b>>::value,
            "Not mapped to valid tuple after push_back"
        );
        static_assert(
            std::is_same<variadic::collection<a, b, c>::push_back<c, b, a>::emplace<std::tuple>, std::tuple<a, b, c, c, b, a>>::value,
            "Not mapped to valid tuple after push_back"
        );
    }

}