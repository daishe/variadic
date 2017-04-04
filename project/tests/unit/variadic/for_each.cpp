//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>

#include <variadic/for_each.hpp>
#include <variadic/for_each_type.hpp>

#include <sstream>
#include <string>

namespace variadic_for_each_test
{

    std::ostringstream out("");

    template <typename... Types>
    void check_zero()
    {
        variadic::for_each([](auto obj) {
            out << static_cast<double>(obj) << ' ';
        }, Types(0)...);
    }

    struct a
    { static constexpr int val = 3; };

    struct b
    { static constexpr char val = '4'; };

    struct c
    { static constexpr float val = 5; };


    struct callback_type
    {
        template <typename T>
        void operator ()()
        {
            out << T::val << ' ';
        };
    };

} // namespace variadic_for_each_test

BOOST_AUTO_TEST_CASE( variadic_for_each )
{
    using namespace variadic_for_each_test;

    {
        out.str("");
        uint16_t int16_v = 1;
        uint32_t int32_v = 2;
        uint64_t int64_v = 3;
        variadic::for_each(
            [](auto v) { out << v << ' '; },
            int16_v, int32_v, int64_v
        );
        BOOST_CHECK(out.str() == "1 2 3 ");

        out.str("");
        int16_v++;
        int32_v++;
        int64_v++;
        variadic::for_each(
            [](auto v) { out << v << ' '; },
            int16_v, int32_v, int64_v
        );
        BOOST_CHECK(out.str() == "2 3 4 ");

        out.str("");
        variadic::for_each(
            [](auto v) {
                v++;
                out << v << ' ';
            },
            int16_v, int32_v, int64_v
        );
        BOOST_CHECK(out.str() == "3 4 5 ");
    }

    {
        out.str("");
        check_zero<char, int, float>();
        BOOST_CHECK(out.str() == "0 0 0 ");
    }

    {
        out.str("");
        callback_type callback;
        variadic::for_each_type<a, b, c>(callback);
        BOOST_CHECK(out.str() == "3 4 5 ");
    }

    {
        out.str("");
        variadic::for_each(
            [](auto t) { out << decltype(t)::type::val << ' '; },
            variadic::type_frame<a>(),
            variadic::type_frame<b>(),
            variadic::type_frame<c>()
        );
        BOOST_CHECK(out.str() == "3 4 5 ");
    }
}
