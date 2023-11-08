/*
 *	exlist.hpp
 *	A linked list data structure without duplicate members
 *	Depends on list.hpp List class, whose methods it overrides
 *	Duplicate exclusion depends on the == operand so make sure to define it on every
 *	custom data type you want to make an EXList for
 */

#ifndef _IOSTREAM
#include <iostream>
#define _IOSTREAM
#endif
#ifndef _LIST_HPP
#include "list.hpp"
#define _LIST_HPP
#endif

template <typename T>
class EXList : public List<T>{
	public:
		EXList(){}
		void add(T* data){
			Node<T>* node = (Node<T>*) malloc(sizeof(Node<T>));
			node->data = data;
			node->next = NULL;
			if(this->root == NULL) this->root = node;
			else{
				struct Node<T>* iter = this->root;
				while(iter->next){
					if(iter == node) {
						std::cout << "Duplicate" << std::endl;
						return;
					}
					iter = iter->next;
				}
				iter->next = node;
			}
		}
};

