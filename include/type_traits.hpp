/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 21:31:02 by joupark           #+#    #+#             */
/*   Updated: 2022/06/18 21:48:57 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP
#define FT_NOEXCEPT throw()

namespace ft
{
	//integral_constant: 특정 자료형을 컴파일 도중에 각기 다른 자료형으로 만들 수 있다.
	//특히, bool형을 다른 자료형으로 사용하는 true_type, false_type이 주로 쓰인다.
	template <typename T, T v>
	struct integral_constant
	{
		typedef integral_constant<T, v> type;
		typedef T value_type;
		static const T value = v;
		operator value_type() const FT_NOEXCEPT { return value; }
	};
	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;

	//enable_if: 템플릿 특수화의 SFINE(Substitution Failure Is Not An Error)규칙을 사용한 구조체다.
	//컴파일 단계에서 분기를 나누기 위해서 사용한다. 
	template <bool, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T>
	{
	  typedef T type;
	};

	//remove_cv: const, volatile, const volatile 등 수식어 제거용
	template <typename T>
	struct _remove_cv
	{ typedef T type; };

	template <typename T>
	struct _remove_cv<const T>
	{ typedef T type; };

	template <typename T>
	struct _remove_cv<volatile T>
	{ typedef T type; };

	template <typename T>
	struct _remove_cv<const volatile T>
	{ typedef T type; };

	template <typename T>
	struct remove_cv
	{ typedef typename _remove_cv<T>::type type; };

	//is_integral: 정수형 자료형 체크
	template <typename T>
	struct _is_integral : public false_type {};
	template <>
	struct _is_integral<bool> : public true_type {};
	template <>
	struct _is_integral<char> : public true_type {};
	template <>
	struct _is_integral<unsigned char> : public true_type {};
	template <>
	struct _is_integral<signed char> : public true_type {};
	template <>
	struct _is_integral<wchar_t> : public true_type {};
	template <>
	struct _is_integral<short> : public true_type {};
	template <>
	struct _is_integral<unsigned short> : public true_type {};
	template <>
	struct _is_integral<int> : public true_type {};
	template <>
	struct _is_integral<unsigned int> : public true_type {};
	template <>
	struct _is_integral<long> : public true_type {};
	template <>
	struct _is_integral<unsigned long> : public true_type {};
	template <>
	struct _is_integral<long long> : public true_type {};
	template <>
	struct _is_integral<unsigned long long> : public true_type {};
	
	template <typename T>
	struct is_integral : public _is_integral<typename remove_cv<T>::type> {};

	//is_same: 두 매개변수가 같은지 확인
	template <typename T, typename U>
	struct is_same : public false_type {};

	template <typename T>
	struct is_same<T, T> : public true_type {};

	template <typename>
	struct void_t
	{ typedef void type; };	
}

#endif
