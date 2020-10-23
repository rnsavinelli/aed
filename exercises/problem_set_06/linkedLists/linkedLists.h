#ifndef LINKEDLISTS_H_INCLUDED
#define LINKEDLISTS_H_INCLUDED

template <typename T> struct Node {
	T data;
	Node<T>* next = nullptr;
};

template <typename T> void push(Node<T>* &stack, T value);
template <typename T> T pop(Node<T>* &stack);
template <typename T> void stackErase(Node<T>* &stack);

template <typename T> int stackEmpty(const Node<T>* stack);
template <typename T> void append(Node<T>*& stack, T value);

template <typename T> void stackPrint(Node<T>* stack);

template <typename T> Node<T>* search(T key, Node<T>* stack, bool (*criteria)(T, T));
template <typename T> void insert(T value, Node<T>* &stack, bool (*criteria)(T, T));
template <typename T> Node<T>* extract(T key, Node<T>* &stack, bool (*criteria)(T, T));
template <typename T> bool remove (T key, Node<T>* &stack, bool (*criteria)(T, T));

#include "linkedLists.hpp"

#endif // LINKEDLISTS_H_INCLUDED
