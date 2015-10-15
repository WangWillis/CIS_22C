#ifndef LIST_H
#define LIST_H

template <class T>
struct Data{
	T data;
	Data* next;
};

template <class T>
class List{
	private:
		Data<T>* head;
	public:
		List();
		List(T data);
		~List();
		T getHeadData();
		void addFront(T data);
		void delFront();
};
#endif