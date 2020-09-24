#ifndef LINKEDLISTS_HPP_INCLUDED
#define LINKEDLISTS_HPP_INCLUDED

#include <cassert>

template <typename T> void 
push(Node<T>* &stack, T value)
{
	Node<T>* e = new Node<T>;
	e->data = value;
	e->next = stack;
	stack = e;
}

template <typename T> int
stackEmpty(const Node<T>* stack)
{
	return (stack == nullptr);
}

template <typename T> T 
pop(Node<T>* &stack)
{
	assert(!stackEmpty(stack));
	
	T ret = stack->data;
	Node<T>* s = stack;
	stack = stack->next;
	delete s;
	return ret;
}

template <typename T> void 
append(Node<T>* &stack, T value)
{
	Node<T>* e = new Node<T>;
	e->data = value;
	e->next = nullptr;
	
	if (stackEmpty(stack)) {
		stack = e;
	} else {
		Node<T>* s = stack;
		while (s->next != nullptr)
			s = s->next;
		s->next = e;
	}
}

template <typename T> void stackPrint(Node<T>* stack)
{
	while (!stackEmpty(stack)) {
		std::cout << stack->data << std::endl;
		stack = stack->next;
	}
}

#endif // LINKEDLISTS_HPP_INCLUDED
