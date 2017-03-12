//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>

#include <variadic/nested_type.hpp>

#include <sstream>
#include <string>
#include <type_traits>

namespace variadic_nested_type_test
{

    std::ostringstream out("");

    template <typename nestedType>
    class a
    {
        public:
            nestedType rec;

            template <typename T>
            T & operator ()(T & t)
            {
                t << "a" << ' ';
                return rec(t);
            };
    };

    template <typename nestedType>
    class b
    {
        public:
            nestedType rec;

            template <typename T>
            T & operator ()(T & t)
            {
                t << "b" << ' ';
                return rec(t);
            };
    };

    template <typename nestedType>
    class c
    {
        public:
            nestedType rec;

            template <typename T>
            T & operator ()(T & t)
            {
                t << "c" << ' ';
                return rec(t);
            };
    };

    class stop
    {
        public:
            template <typename T>
            T & operator ()(T & t)
            {
                t << "stop";
                return t;
            };
    };

} // namespace variadic_nested_type_test

BOOST_AUTO_TEST_CASE( variadic_nested_type )
{
    using namespace variadic_nested_type_test;

    {
        typedef variadic::nested_type<a, b, c>::type<stop> rtype;
        static_assert(std::is_same<rtype, a<b<c<stop>>>>::value, "variadic::nested_type should define simple nested type");

        out.str("");
        rtype robj;
        robj(out);
        BOOST_CHECK(out.str() == "a b c stop");
    }

    {
        typedef variadic::nested_type<a, b, c, c, b, a>::type<stop> rtype;
        static_assert(std::is_same<rtype, a<b<c<c<b<a<stop>>>>>>>::value, "variadic::nested_type should define simple nested type");

        out.str("");
        rtype robj;
        robj(out);
        BOOST_CHECK(out.str() == "a b c c b a stop");
    }

    {
        typedef variadic::nested_type<a>::type<stop> rtype;
        static_assert(std::is_same<rtype, a<stop>>::value, "variadic::nested_type should define simple nested type");

        out.str("");
        rtype robj;
        robj(out);
        BOOST_CHECK(out.str() == "a stop");
    }

    {
        typedef variadic::nested_type<>::type<stop> rtype;
        static_assert(std::is_same<rtype, stop>::value, "variadic::nested_type should define simple nested type");

        out.str("");
        rtype robj;
        robj(out);
        BOOST_CHECK(out.str() == "stop");
    }
}