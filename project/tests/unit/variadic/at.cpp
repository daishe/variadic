//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//        (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>

#include <variadic/at.hpp>

#include <type_traits>

#include <variadic/size_type.hpp>

namespace variadic_at_test
{

    template <size_t Value>
    using t = variadic::size_type<Value>;

} // namespace variadic_at_test

BOOST_AUTO_TEST_CASE( variadic_at )
{
    using namespace variadic_at_test;

    static_assert(std::is_same<variadic::at<0, char>::type, char>::value, "1[/1]st item (begin and end) extraction failed for variadic::at");

    static_assert(std::is_same<variadic::at<0, char, int, float, int, double>::type, char>::value,   "1st[/5] item (begin) extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at<1, char, int, float, int, double>::type, int>::value,    "2nd[/5] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at<2, char, int, float, int, double>::type, float>::value,  "3rd[/5] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at<3, char, int, float, int, double>::type, int>::value,    "4th[/5] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at<4, char, int, float, int, double>::type, double>::value, "5th[/5] item (end) extraction failed for variadic::at");

    static_assert(std::is_same<variadic::at< 0, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t< 0>>::value, "1st[/30] item (begin) extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at< 1, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t< 1>>::value, "2nd[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at< 2, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t< 2>>::value, "3rd[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at< 3, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t< 3>>::value, "4th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at< 4, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t< 4>>::value, "5th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at< 5, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t< 5>>::value, "6th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at< 6, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t< 6>>::value, "7th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at< 7, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t< 7>>::value, "8th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at< 8, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t< 8>>::value, "9th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at< 9, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t< 9>>::value, "10th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at<10, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t<10>>::value, "11th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at<11, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t<11>>::value, "12th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at<12, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t<12>>::value, "13th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at<13, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t<13>>::value, "14th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at<14, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t<14>>::value, "15th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at<15, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t<15>>::value, "16th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at<16, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t<16>>::value, "17th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at<17, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t<17>>::value, "18th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at<18, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t<18>>::value, "19th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at<19, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t<19>>::value, "20th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at<20, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t<20>>::value, "21th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at<21, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t<21>>::value, "22th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at<22, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t<22>>::value, "23th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at<23, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t<23>>::value, "24th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at<24, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t<24>>::value, "25th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at<25, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t<25>>::value, "26th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at<26, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t<26>>::value, "27th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at<27, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t<27>>::value, "28th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at<28, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t<28>>::value, "29th[/30] item extraction failed for variadic::at");
    static_assert(std::is_same<variadic::at<29, t<0>, t<1>, t<2>, t<3>, t<4>, t<5>, t<6>, t<7>, t<8>, t<9>, t<10>, t<11>, t<12>, t<13>, t<14>, t<15>, t<16>, t<17>, t<18>, t<19>, t<20>, t<21>, t<22>, t<23>, t<24>, t<25>, t<26>, t<27>, t<28>, t<29>>::type, t<29>>::value, "30th[/30] item (end) extraction failed for variadic::at");
}