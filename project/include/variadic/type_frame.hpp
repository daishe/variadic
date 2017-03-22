//               Copyright Marek Dalewski 2017
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#pragma once

namespace variadic
{

    ///
    /// \brief      Equivalent to given type
    ///
    /// \tparam     T     Equivalent type
    ///
    template <typename T>
    using no_frame = T;

    ///
    /// \brief      Simple handler for type
    ///
    /// Cheap to construct. Secure to create pointers of with pure syntax.
    ///
    /// \tparam     T     Underling type
    ///
    template <typename T>
    struct type_frame
    {
        ///
        /// \brief      Underling type
        ///
        typedef T type;
    };

    ///
    /// \brief      Shorthand for `variadic::type_frame`
    ///
    /// Simple handler for type. Cheap to construct. Secure to create pointers of with pure syntax.
    ///
    /// \tparam     T     Underling type
    ///
    /// \see variadic::type_frame
    ///
    template <typename T>
    using tf = type_frame<T>;

    ///
    /// \brief      Simple handler for templated type
    ///
    /// Cheap to construct. Secure to create pointers of with pure syntax.
    ///
    /// \tparam     T     Underling templated type
    ///
    template <template<typename...> typename T>
    struct templated_type_frame
    {
        ///
        /// \brief      Underling type
        ///
        /// \tparam     Types  Underling type template parameter
        ///
        template <typename... Types>
        using type = T<Types...>;
    };

    ///
    /// \brief      Shorthand for `variadic::templated_type_frame`
    ///
    /// Simple handler for templated type. Cheap to construct. Secure to create pointers of with pure syntax.
    ///
    /// \tparam     T     Underling templated type
    ///
    /// \see variadic::templated_type_frame
    ///
    template <template<typename...> typename T>
    using ttf = templated_type_frame<T>;

} // namespace variadic
