#ifndef LINKEDLISTS_H_INCLUDED
#define LINKEDLISTS_H_INCLUDED

template <typename T> struct Node {
	T data;
	Node<T>* next = nullptr;
};

template <typename T> void push(Node<T>* &stack, T key);
template <typename T> void append(Node<T>*& stack, T key);
template <typename T> T pop(Node<T>* &stack);
template <typename T> void stackErase(Node<T>* &stack);

template <typename T> bool stackEmpty(const Node<T>* stack);

template <typename T> void stackPrint(Node<T>* stack);

template <typename T> bool linear_search(T key, Node<T>* statck, int (*criteria)(T, T));
template <typename T> Node<T>* search(T key, Node<T>* stack, int (*criteria)(T, T));
template <typename T> void insert(T key, Node<T>* &stack, int (*criteria)(T, T));
template <typename T> Node<T>* insert_unique(T key, Node<T>* &stack, int (*criteria)(T, T));

template <typename T> Node<T>* extract(T key, Node<T>* &stack, int (*criteria)(T, T));
template <typename T> bool remove (T key, Node<T>* &stack, int (*criteria)(T, T));

#include "linkedlists.hpp"

#endif // LINKEDLISTS_H_INCLUDED
