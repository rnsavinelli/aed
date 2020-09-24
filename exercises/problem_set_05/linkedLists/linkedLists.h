#ifndef LINKEDLISTS_H_INCLUDED
#define LINKEDLISTS_H_INCLUDED

template <typename T> struct Node {
	T data;
	Node<T>* next;
};

template <typename T> void push(Node<T>* &stack, T value);
template <typename T> T pop(Node<T>* &stack);

template <typename T> int stackEmpty(const Node<T>* stack);
template <typename T> void append(Node<T>*& stack, T value);

template <typename T> void stackPrint(Node<T>* stack);

#include "linkedLists.hpp"

#endif // LINKEDLISTS_H_INCLUDED
