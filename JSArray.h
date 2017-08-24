#include <string>
#include <iostream>

template <class T>
class Array
{
public:
	Array();
	Array<T>* next;
	Array<T>* prev;
	int pos;
	T data;
};

template<class T>
Array<T>::Array() {
	next = prev = NULL;
	pos = -1;
}



template <class T>
class JSArray
{
public:
	JSArray();
	~JSArray();
	int size = 0;
	T elem;
	int push(const T& elem); // Append elem
	T pop(); // Remove last
	/* TO DO */
	// int unshift(const T& elem);
	// T shift(const T& elem); // Remove beginning
	// JSArray concat(JSArray); // Appends new JSArray to old one
	// std::string join();
	// std::string join(std::string);
	void slice(int, int); // starts at the third item (index of 2) and finishes at the fourth (the item with index 4 is not included)
	T get(int);
	bool isEmpty();
	void print();
private:
	Array<T>* tail;
	Array<T>* head;
	int position;
};


template <class T>
JSArray<T>::JSArray() {
	size = 0;
	elem;
	tail = new Array<T>();
	position = tail->pos;
}

template<class T>
JSArray<T>::~JSArray() {
	delete tail;
	delete head;
}

template<class T>
int JSArray<T>::push(const T& elem) {
	if(tail->pos != -1) {
		Array<T>* temp = new Array<T>();
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	tail->data = elem;
	tail->pos = size;
	size += 1;
	if(tail->pos == 0)
		head = tail;
	else if(tail->pos == 1)
		head->next = tail;
	if(tail->pos >= 1)
		std::cout << "Atleast once " << head->next->data << std::endl;
		std::cout << "Array " << tail->data << std::endl;
	return tail->pos;
}

template<class T>
T JSArray<T>::pop() {
	if (tail->pos == -1)
		return NULL;
	Array<T>* current;
	current = tail;
	T destroyedData = tail->data;
	tail = current->prev;
	delete current;
	size -= 1;
	return destroyedData;
}

template<class T>
void JSArray<T>::slice(int start, int end) {
	
}

template<class T>
T JSArray<T>::get(int position) {
	if(position >= size)
		return NULL;
	Array<T>* temp;
	temp = tail;
	for (int i = 0; i < size; ++i)
	{
		if(position == temp->pos)
			return temp->data;
		temp = temp->prev;
	}
}

template<class T>
bool JSArray<T>::isEmpty() {
	return (size == 0);
}

template<class T>
void JSArray<T>::print() {
	Array<T>* temp;
	temp = head;
	for (int i = size; i > 0; --i)
	{
		std::cout << "temp->data " << temp->data << std::endl;
		if(temp->next != NULL)
			temp = temp->next;
		else
			break;
	}
	return;
}
