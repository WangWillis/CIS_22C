#ifndef BTNODE_H
#define BTNODE_H

#include <stdlib.h>

template <class T>
class BTNode;

template <class T>
class BTNode{
	private:
		//dont want to have a node with random data
		BTNode(); // Default constructor
		T data;//Templitized data for any type that wants to be added into the tree.
		BTNode* left; //Left child
		BTNode* right;//Right child
		int height;// the height of the tree
		void del(T const &);// deletion
		void del(T* const &); // deletion of a pointer
	public:
		BTNode(const T);// default constructor
		~BTNode();//Deconstructor
		T getData() const;//Returns the data
		BTNode<T>* getLeft(); //Returns the left child
		BTNode<T>* getRight(); //Returns the right child
        int getHeight() const; //Returns the height
        void setHeight(const int); //Sets the height
        void setData(const T); //sets the data
		void setLeft(BTNode*); // sets the left child
		void setRight(BTNode*); // sets the right child 
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
