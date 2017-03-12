//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>

#include <variadic/type_frame.hpp>

#include <type_traits>

namespace variadic_type_frame_test
{

    struct s0
    {};

    template <typename T>
    struct s1
    {};

    template <typename T, typename Y>
    struct s2
    {};

    template <typename T, typename Y, typename U>
    struct s3
    {};

    template <typename... Types>
    struct sn
    {};

} // namespace variadic_type_frame_test

BOOST_AUTO_TEST_CASE( variadic_type_frame )
{
    using namespace variadic_type_frame_test;

    {
        static_assert(std::is_same<variadic::type_frame<int>::type, int>::value, "Underlying type extraction failed for variadic::type_frame");
        static_assert(std::is_same<variadic::type_frame<s0>::type,   s0>::value, "Underlying type extraction failed for variadic::type_frame");
    }

    {
        static_assert(std::is_same<variadic::templated_type_frame<s1>::type<int>, s1<int>>::value, "Underlying type extraction failed for variadic::templated_type_frame");
        static_assert(std::is_same<variadic::templated_type_frame<s1>::type<s0>,  s1<s0>>::value,  "Underlying type extraction failed for variadic::templated_type_frame");

        static_assert(std::is_same<variadic::templated_type_frame<s2>::type<int, char>,         s2<int, char>>::value,         "Underlying type extraction failed for variadic::templated_type_frame");
        static_assert(std::is_same<variadic::templated_type_frame<s2>::type<s0, s0>,            s2<s0, s0>>::value,            "Underlying type extraction failed for variadic::templated_type_frame");
        static_assert(std::is_same<variadic::templated_type_frame<s2>::type<s1<int>, s1<char>>, s2<s1<int>, s1<char>>>::value, "Underlying type extraction failed for variadic::templated_type_frame");
        static_assert(std::is_same<variadic::templated_type_frame<s2>::type<s1<s0>, s1<s0>>,    s2<s1<s0>, s1<s0>>>::value,    "Underlying type extraction failed for variadic::templated_type_frame");

        static_assert(std::is_same<variadic::templated_type_frame<s3>::type<int, short, char>,             s3<int, short, char>>::value,             "Underlying type extraction failed for variadic::templated_type_frame");
        static_assert(std::is_same<variadic::templated_type_frame<s3>::type<s0, s0, s0>,                   s3<s0, s0, s0>>::value,                   "Underlying type extraction failed for variadic::templated_type_frame");
        static_assert(std::is_same<variadic::templated_type_frame<s3>::type<s1<int>, s1<short>, s1<char>>, s3<s1<int>, s1<short>, s1<char>>>::value, "Underlying type extraction failed for variadic::templated_type_frame");
        static_assert(std::is_same<variadic::templated_type_frame<s3>::type<s1<s0>, s1<s0>, s1<s0>>,       s3<s1<s0>, s1<s0>, s1<s0>>>::value,       "Underlying type extraction failed for variadic::templated_type_frame");
    }

    {
        static_assert(std::is_same<variadic::templated_type_frame<sn>::type<int>, sn<int>>::value, "Underlying type extraction failed for variadic::templated_type_frame");
        static_assert(std::is_same<variadic::templated_type_frame<sn>::type<s0>,  sn<s0>>::value,  "Underlying type extraction failed for variadic::templated_type_frame");

        static_assert(std::is_same<variadic::templated_type_frame<sn>::type<int, char>,         sn<int, char>>::value,         "Underlying type extraction failed for variadic::templated_type_frame");
        static_assert(std::is_same<variadic::templated_type_frame<sn>::type<s0, s0>,            sn<s0, s0>>::value,            "Underlying type extraction failed for variadic::templated_type_frame");
        static_assert(std::is_same<variadic::templated_type_frame<sn>::type<s1<int>, s1<char>>, sn<s1<int>, s1<char>>>::value, "Underlying type extraction failed for variadic::templated_type_frame");
        static_assert(std::is_same<variadic::templated_type_frame<sn>::type<s1<s0>, s1<s0>>,    sn<s1<s0>, s1<s0>>>::value,    "Underlying type extraction failed for variadic::templated_type_frame");
        static_assert(std::is_same<variadic::templated_type_frame<sn>::type<sn<int>, sn<char>>, sn<sn<int>, sn<char>>>::value, "Underlying type extraction failed for variadic::templated_type_frame");
        static_assert(std::is_same<variadic::templated_type_frame<sn>::type<sn<s0>, sn<s0>>,    sn<sn<s0>, sn<s0>>>::value,    "Underlying type extraction failed for variadic::templated_type_frame");

        static_assert(std::is_same<variadic::templated_type_frame<sn>::type<int, short, char>,             sn<int, short, char>>::value,             "Underlying type extraction failed for variadic::templated_type_frame");
        static_assert(std::is_same<variadic::templated_type_frame<sn>::type<s0, s0, s0>,                   sn<s0, s0, s0>>::value,                   "Underlying type extraction failed for variadic::templated_type_frame");
        static_assert(std::is_same<variadic::templated_type_frame<sn>::type<s1<int>, s1<short>, s1<char>>, sn<s1<int>, s1<short>, s1<char>>>::value, "Underlying type extraction failed for variadic::templated_type_frame");
        static_assert(std::is_same<variadic::templated_type_frame<sn>::type<s1<s0>, s1<s0>, s1<s0>>,       sn<s1<s0>, s1<s0>, s1<s0>>>::value,       "Underlying type extraction failed for variadic::templated_type_frame");
        static_assert(std::is_same<variadic::templated_type_frame<sn>::type<sn<int>, sn<short>, sn<char>>, sn<sn<int>, sn<short>, sn<char>>>::value, "Underlying type extraction failed for variadic::templated_type_frame");
        static_assert(std::is_same<variadic::templated_type_frame<sn>::type<sn<s0>, sn<s0>, sn<s0>>,       sn<sn<s0>, sn<s0>, sn<s0>>>::value,       "Underlying type extraction failed for variadic::templated_type_frame");
    }
}