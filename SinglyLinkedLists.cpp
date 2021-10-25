#include<iostream>
using namespace std;
template<typename T>
class Structs {
	template<typename T>
	class Dates {
		T data;
		Dates* pNext;
	public:
		Dates(T Val = T(), Dates* p = nullptr) {
			this->data = Val;this->pNext = p;
		}
	};
	Dates<T>* pHead;
	Dates<T>* pEnd;
	int size = 0;
public:
	Structs() {
		pHead = nullptr;
		pEnd = nullptr;
	}
	Structs(T val) {
		pHead = new Dates<T>(val, pHead);
		pEnd = pHead;
		size++;
	}
	void push_front(T val) {
		if (pHead == nullptr) {
			pHead = new Dates<T>(val, pHead);
			pEnd = pHead;
			size++;
		}
		else {
			if (pHead == pEnd) {
				pEnd = pHead;
			}
			pHead = new Dates<T>(val, pHead);
			size++;
		}
	}
	void addItem(T val, int index) {
		if (index == 0) {
			push_front(val);
			return;
		}
		else if (index == size - 1) {
			push_back(val);
			return;
		}
		else if (index >= 0 && index < size) {
			Dates<T>* tmp = this->pHead;
			for (int i = 0; i < size; i++) {
				if (i < index - 1) tmp = tmp->pNext;
				else if (i == (index - 1)) {
					Dates<T>* x = tmp;
					Dates<T>* y = tmp->pNext;
					tmp = new Dates<T>(val);
					x->pNext = tmp; tmp->pNext = y;
					//delete[]x; delete[]y;
					break;
				}
			}
			size++;
		}
	}
	int editAll(T old, T _new) {
		int count = -1;
		Dates<T>* tmp = this->pHead;
		while (tmp->pNext != nullptr) {
			if (tmp->data == old) { tmp->data = _new; count++; }
			tmp = tmp->pNext;
		}
		if (tmp->data == old) { tmp->data = _new; count++; }
		return count;
	}
	int sceartchVariable(T old) {
		for (int i = 0; i < size; i++) {
			if (operator[](i) == old) { return i; }
		}
	}
	void dellItem(int index) {
		if (index == 0) {
			pop_front();
			return;
		}
		else if (index == size - 1) {
			pop_end();
			return;
		}
		else if (index >= 0 && index < size) {
			Dates<T>* tmp = this->pHead;
			for (int i = 0; i < size; i++) {
				if (i < index - 1) tmp = tmp->pNext;
				else if (i == (index - 1)) {
					Dates<T>* y = tmp->pNext;
					tmp->pNext = y->pNext;
					//delete[]x; delete[]y;
					break;

				}
			}
			size--;
		}
	}
	void push_back(T val) {
		if (pHead == nullptr) {
			push_front(val);
		}
		else {
			pEnd->pNext = new Dates<T>(val);
			pEnd = pEnd->pNext;
			size++;
		}
	}
	T& pop_front() {
		if (pHead != nullptr) {
			T tmp = pHead->data;
			pHead = pHead->pNext;
			size--;
			return tmp;
		}
	}
	T& pop_end() {
		if (pHead != nullptr) {
			pEnd = this->pHead;
			T tmps = pEnd->data;
			if (pEnd->pNext != nullptr) {
				while (pEnd->pNext != nullptr) {
					if (pEnd->pNext->pNext == nullptr) {
						break;
					}
					pEnd = pEnd->pNext;
				}
				pEnd->pNext = nullptr;
				size--;
				return tmps;
			}
			else {
				pEnd = pHead;
				return pEnd->data;
			}
		}
	}
	T& operator[](int ind) {
		if (ind >= 0 && ind < size) {
			Dates<T>* tmp = this->pHead;
			for (int i = 0; i < size; i++) {
				if (i != ind) {
					tmp = tmp->pNext;
				}
				else {
					return tmp->data;
				}
			}
		}
	}
	int getSize() { return size; }
	friend ostream& operator<<(ostream& os, Structs& ls)
	{
		for (int i = 0; i < ls.size; i++) {
			os << ls[i] << endl;
		}
		return os;
	}


};
