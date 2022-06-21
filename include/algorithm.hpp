/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 21:04:22 by joupark           #+#    #+#             */
/*   Updated: 2022/06/18 21:37:22 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

namespace ft
{
	template <typename InputIterator1, typename InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while(first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1, ++first2;
		}
		return true;
	}
	//BinaryPredicate: 사용자가 제공한 매개변수를 표준 라이브러리로 사용할 수 있도록, 모아둔 집합
	template <typename InputIterator1, typename InputIterator2,
			 typename BinaryPredicate>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
			BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return false;
			++first1, ++first2;
		}
		return true;
	}
	//lexicographical_compare: 두 이터레이터를 받아와 container 요소를 비교한다.
	//만약, 두 번째 이터레이터가 더 큰 값을 가지고 있으면 참을,
	//모두 같거나 첫 번째 이터레이터가 더 큰 값을 가지게 되면 거짓을 반환한다.
	template <typename InputIterator1, typename InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if(first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1, ++first2;
		}
		return (first2 != last2);
	}
	template <typename InputIterator1, typename InputIterator2, typename Compare>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || Comp(*first2, *first1))
				return false;
			else if (Comp(*first1, *first2))
				return true;
			++first1, ++first2;
		}
		return (first2 != last2);
	}
	template <typename T>
	const T& min(const T& x, const T& y)
	{
		return (x < y) ? x : y;
	}
}

#endif
