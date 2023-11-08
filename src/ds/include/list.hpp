/*	list.hpp
 *	A generic linked list data structure interface. Stores data of type T 
 *	in dynamically Node structures. The list is singly-linked and contains
 *	only the start node(root). The root doesn't represent the first data
 *	stored in the list, rather it's an extra node made to reduce code
 *	complexity. The first "data node" is the one after the root.
 */

#ifndef _IOSTREAM
#include <iostream>
#define _IOSTREAM
#endif

template <typename T>
class Node{
	public:
		T* data {NULL};
		Node* next {NULL};

		Node(T* data): data{data}
		{};
		~Node(){
			if(next != NULL) free(next);
			free(data);
		}

		bool operator==(Node& other){
			return (data == other.data);
		}
};
	
template <typename T>
class List{
	protected:
		Node<T>* root {NULL};

		void clearR(Node<T>* root);
	public:
		void add(T* data);
		void remove(int index);
		void clear();
		int size();
		T* get(int index);
		Node<T>* getAll();
};

template <typename T>
void List<T>::add(T* data){
	Node<T>* node = (Node<T>*) malloc(sizeof(Node<T>*));
	node->data = data;
	node->next = NULL;
	if(root == NULL) root = node;
	else{
		Node<T>* iter = root;
		while(iter->next) iter = iter->next;
		iter->next = node;
	}
}

template <typename T>
void List<T>::remove(int index){
	if(root == NULL) return;
	if(index == 0) root = root->next;

	struct Node<T>* iter = root;
	while(index){
		if(index == 1){
			Node<T>* removed = iter->next;
			iter->next = removed->next;
			free(removed);
			return;
		}
		iter = iter->next;
		index--;
	}
}

template <typename T>
void List<T>::clear(){
	this->clearR(root->next);
	root = NULL;
}

template <typename T>
void List<T>::clearR(Node<T>* root){
	if(root != NULL) free(root);
}

template <typename T>
int List<T>::size(){
	int size = 0;
	Node<T>* iter = root;
	while(iter){
		iter = iter->next;
		size++;
	}
	return size;
}

template <typename T>
T* List<T>::get(int index){
	Node<T>* iter = root;
	while(iter){
		if(index == 0) return iter->data;
		iter = iter->next;
		index--;
	}
	return NULL;
}

template <typename T>
Node<T>* List<T>::getAll() {return root;}
