#ifndef BTNODE_H
#define BTNODE_H

#include <stdlib.h>

template <class T>
class BTNode;

template <class T>
class BTNode{
	private:
		//dont want to have a node with random data
		BTNode();
		T data;
		BTNode* left;
		BTNode* right;
		int height;
		void del(T const &);
		void del(T* const &);
	public:
		BTNode(const T);
		~BTNode();
		T getData() const;
		BTNode<T>* getLeft();
		BTNode<T>* getRight();
        int getHeight() const;
        void setHeight(const int);
        void setData(const T);
		void setLeft(BTNode*);
		void setRight(BTNode*);
};

template <class T>
BTNode<T>::BTNode(const T info) : left(NULL), right(NULL), height(1){
	data = info;
}

template <class T>
BTNode<T>::~BTNode(){
	del(data);
}

template <class T>
void BTNode<T>::del(T const &) {}

template <class T>
void BTNode<T>::del(T* const & p) {delete p;}

template <class T>
int BTNode<T>::getHeight() const{
	return height;
}

template <class T>
void BTNode<T>::setHeight(const int len){
	height = len;
}

template <class T>
T BTNode<T>::getData() const{
	return data;
}

template <class T>
BTNode<T>* BTNode<T>::getLeft(){
	return left;
}

template <class T>
BTNode<T>* BTNode<T>::getRight(){
	return right;
}

template <class T>
void BTNode<T>::setData(const T info){
	data = info;
}

template <class T>
void BTNode<T>::setLeft(BTNode<T>* temp){
	left = temp;
}

template <class T>
void BTNode<T>::setRight(BTNode<T>* temp){
	right = temp;
}

// template <class T>
// bool BTNode<T>::find(T data) {
//     if(data == this->data)
//         return true;
//     else if(data < this->data) {
//         if(left == NULL)
//             return false;
//         else
//             return left->find(data);
//     }else{
//         if(right == NULL)
//             return false;
//         else
//         	return right->find(data);
//     }
// }

#endif
