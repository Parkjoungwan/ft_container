/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:41:38 by joupark           #+#    #+#             */
/*   Updated: 2022/06/20 14:46:05 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"
#define FT_NOEXCEPT throw()

namespace ft
{
	//stack: 대부분의 기능이 vector에서 가져온다. 일부, push, pop의 기능이 제한된다.
	template <typename _T, typename _Container = vector<_T> >
	class stack
	{
		public:
			typedef _Container container_type;
			typedef typename container_type::value_type value_type;
			typedef typename container_type::size_type size_type;

		protected:
			container_type c;

		public:
			// constructor
			explicit stack(const container_type& __c = container_type()) : c(__c) {}

			// member function
			bool empty() const { return c.empty(); }
			size_type size() const { return c.size(); }
			value_type& top() { return c.back(); }
			const value_type& top() const { return c.back(); }
			void push(const value_type& val) { return c.push_back(val); }
			void pop() { c.pop_back(); }

			// relational operator
			// Use friend to compare protected member variable
			template <typename T, typename C>
			friend bool operator==(const stack<T, C>& lhs, const stack<T, C>& rhs);
			template <typename T, typename C>
			friend bool operator<(const stack<T, C>& lhs, const stack<T, C>& rhs);
	};

	//operators
	template <typename T, typename C>
	inline bool operator==(const stack<T, C>& lhs, const stack<T, C>& rhs)
	{ return lhs.c == rhs.c; }

	template <typename T, typename C>
	inline bool operator!=(const stack<T, C>& lhs, const stack<T, C>& rhs)
	{ return !(lhs == rhs); }

	template <typename T, typename C>
	inline bool operator<(const stack<T, C>& lhs, const stack<T, C>& rhs)
	{ return lhs.c < rhs.c; }

	template <typename T, typename C>
	inline bool operator<=(const stack<T, C>& lhs, const stack<T, C>& rhs)
	{ return !(rhs < lhs); }

	template <typename T, typename C>
	inline bool operator>(const stack<T, C>& lhs, const stack<T, C>& rhs)
	{ return rhs < lhs; }

	template <typename T, typename C>
	inline bool operator>=(const stack<T, C>& lhs, const stack<T, C>& rhs)
	{ return !(lhs < rhs); }
} //end of ft
#endif
