/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:06:12 by kmeixner          #+#    #+#             */
/*   Updated: 2022/09/11 19:32:21 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

template<bool, class T = void>
struct enable_if {};

template<class T>
struct enable_if<true, T>
{
	typedef T type;
};


template <class T, T v>
struct integral_constant {
  //static constexpr T value = v; can I just replace that with const?
  static const T value = v;
  typedef T value_type;
  typedef integral_constant<T,v> type;
 // constexpr operator T() { return v; } //wat dat?
};

typedef integral_constant<bool,true> true_type;
typedef integral_constant<bool,false> false_type;

template <class T> struct is_integral : false_type {};

template <> struct is_integral<bool> : true_type {};
template <> struct is_integral<char> : true_type {};
template <> struct is_integral<char16_t> : true_type {};
template <> struct is_integral<char32_t> : true_type {};
template <> struct is_integral<wchar_t> : true_type {};
template <> struct is_integral<signed char> : true_type {};
template <> struct is_integral<short int> : true_type {};
template <> struct is_integral<int> : true_type {};
template <> struct is_integral<long int> : true_type {};
template <> struct is_integral<long long int> : true_type {};
template <> struct is_integral<unsigned char> : true_type {};
template <> struct is_integral<unsigned short int> : true_type {};
template <> struct is_integral<unsigned int> : true_type {};
template <> struct is_integral<unsigned long int> : true_type {};
template <> struct is_integral<unsigned long long int> : true_type {};
#endif