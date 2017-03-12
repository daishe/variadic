//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>

#include <variadic/collection.hpp>

#include <array>
#include <sstream>
#include <string>
#include <type_traits>

#include <boost/variant.hpp>

#include <variadic/extract.hpp>

namespace variadic_collection_test
{

    std::ostringstream out("");

    struct a
    {
        typedef int16_t type;
        typedef int value;

        template <typename T>
        void operator ()(T & t)
        {
            t << "a" << ' ';
        };
    };

    struct b
    {
        typedef int32_t type;
        typedef float value;

        template <typename T>
        void operator ()(T & t)
        {
            t << "b" << ' ';
        };
    };

    struct c
    {
        typedef int64_t type;
        typedef double value;

        template <typename T>
        void operator ()(T & t)
        {
            t << "c" << ' ';
        };
    };

} // namespace variadic_collection_test

BOOST_AUTO_TEST_CASE( variadic_collection )
{
    using namespace variadic_collection_test;

    typedef variadic::collection<a, b, c> base_collection;
    typedef base_collection::emplace<boost::variant> base_variant;

    typedef base_collection::wrap<variadic::extract::type> type_collection;
    typedef type_collection::emplace<boost::variant> type_variant;

    typedef base_collection::wrap<variadic::extract::value> value_collection;
    typedef value_collection::emplace<boost::variant> value_variant;

    {
        static_assert(
            std::is_same<
                base_variant,
                boost::variant<a, b, c>
            >::value,
            "Not mapped to valid variant"
        );
        static_assert(
            std::is_same<
                type_variant,
                boost::variant<int16_t, int32_t, int64_t>
            >::value,
            "Not mapped to valid variant of T::type"
        );
        static_assert(
            std::is_same<
                value_variant,
                boost::variant<int, float, double>
            >::value,
            "Not mapped to valid variant of T::value"
        );
    }

    {
        static_assert(
            std::is_same<
                base_collection::push_front<b>::emplace<boost::variant>,
                boost::variant<b, a, b, c>
            >::value,
            "Not mapped to valid variant after push_front"
        );
        static_assert(
            std::is_same<
                type_collection::push_front<int8_t>::emplace<boost::variant>,
                boost::variant<int8_t, int16_t, int32_t, int64_t>
            >::value,
            "Not mapped to valid variant of T::type after push_front"
        );
        static_assert(
            std::is_same<
                value_collection::push_front<char>::emplace<boost::variant>,
                boost::variant<char, int, float, double>
            >::value,
            "Not mapped to valid variant of T::value after push_front"
        );
    }

    {
        static_assert(
            std::is_same<
                base_collection::push_back<b>::emplace<boost::variant>,
                boost::variant<a, b, c, b>
            >::value,
            "Not mapped to valid variant after push_back"
        );
        static_assert(
            std::is_same<
                type_collection::push_back<int8_t>::emplace<boost::variant>,
                boost::variant<int16_t, int32_t, int64_t, int8_t>
            >::value,
            "Not mapped to valid variant of T::type after push_back"
        );
        static_assert(
            std::is_same<
                value_collection::push_back<char>::emplace<boost::variant>,
                boost::variant<int, float, double, char>
            >::value,
            "Not mapped to valid variant of T::value after push_back"
        );
    }

    {
        out.str("");
        std::array<base_variant, 3> variant = {a(), b(), c()};
        for (auto & v : variant) {
            boost::apply_visitor(
                [&](auto & t) {
                    t(out);
                },
                v
            );
        }
        BOOST_CHECK(out.str() == "a b c ");
    }

}