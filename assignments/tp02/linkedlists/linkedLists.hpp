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
stackErase(Node<T>* &stack)
{
	while (!stackEmpty(stack)) {
        pop(stack);
    }
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

template <typename T> void
stackPrint(Node<T>* stack)
{
	while (!stackEmpty(stack)) {
		std::cout << stack->data << std::endl;
		stack = stack->next;
	}
}

template <typename T> bool
linear_search(T key, Node<T>* statck, int (*criteria)(T, T))
{
	while (!stackEmpty(statck)) {
		if (criteria(statck->data, key) == 0)
			return true;
		statck = statck->next;
	}
	return false;
}

template <typename T> Node<T>*
search(T key, Node<T>* stack, int (*criteria)(T, T))
{
   while (!stackEmpty(stack) && criteria(key, stack->data) > 0) {
        stack = stack->next;
   }

   return !stackEmpty(stack) && criteria(key, stack->data) > 0 ? stack : nullptr;
}

template <typename T> void
insert(T value, Node<T>* &stack, int (*criteria)(T, T))
{
    Node<T>* e = new Node<T>;
    e->data = value;
    e->next = nullptr;

    Node<T>** ps = &stack;
    while(!stackEmpty(*ps) && criteria(e->data, (*ps)->data) >= 0) {
        ps = &((*ps)->next);
    }
    e->next = *ps;
    *ps = e;
}

template <typename T> Node<T>*
insert_unique(T key, Node<T>* &stack, int (*criteria)(T, T))
{
	Node<T>** ps = &stack;
	while (!stackEmpty(*ps) && criteria(key, (*ps)->data) > 0)
		ps = &((*ps)->next);
	if (!stackEmpty(*ps) && criteria(key, (*ps)->data) == 0) {
		return *ps;
	} else {
		Node<T>* e = new Node<T>;
		e->data = key;
		e->next = *ps;
		*ps = e;
		return e;
	}
}

template <typename T> Node<T>*
extract(T key, Node<T>* &stack, int (*criteria)(T, T))
{
	Node<T> *aux;
	Node<T> **ps = &stack;

	while (!stackEmpty(*ps) && criteria(key, (*ps)->data) > 0) {
		ps = &((*ps)->next);
    }

	if (!stackEmpty(*ps) && criteria(key, (*ps)->data) == 0) {
		aux = *ps;
		*ps= (*ps)->next;
		return aux;
	} else {
		return nullptr;
	}
}

template <typename T> bool
remove (T key, Node<T>* &stack, int (*criteria)(T, T))
{
	Node<T>* e = extract(key, stack, criteria);
	if (e) {
		delete e;
		return true;
	} else {
		return false;
	}
}

#endif // LINKEDLISTS_HPP_INCLUDED
