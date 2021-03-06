/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lib.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:31:29 by joupark           #+#    #+#             */
/*   Updated: 2022/06/22 14:45:27 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <stdlib.h>


#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {}
		MutantStack(const MutantStack<T>& src) {*this = src;}
		MutantStack<T>& operator=(const MutantStack<T>& rhs)
		{
			this->c = rhs.c;
			return *this;
		}
		~MutantStack() {}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
};

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "You should insert seed!! ./container [seed]" << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);
	std::cout << "seed num: "<< seed << std::endl;

	std::vector<std::string> vector_str;
	std::vector<int> vector_int;
	std::stack<int> stack_int;
	std::vector<Buffer> vector_buffer;
	std::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	std::map<int, int> map_int;
	std::set<int> set_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	std::vector<Buffer>().swap(vector_buffer);

	try {
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Vector check end." << std::endl;
	}

	for (int i = 0; i < 1000; ++i)
	{
		map_int.insert(std::make_pair(rand() % 1000, rand() % 1000));
	}

	int sum = 0;
	for (int i = 0; i < 1000; i++)
	{
		int access = rand() % 1000;
		sum += map_int[access];
	}
	std::cout << "map elements sum: " << sum << std::endl;

	{ std::map<int, int> copy = map_int; }

	for (int i = 0; i < COUNT; ++i)
	{
		set_int.insert(rand());
	}

	{ std::set<int> copy = set_int; }

	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++) iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin();
			it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	return (0);
}
