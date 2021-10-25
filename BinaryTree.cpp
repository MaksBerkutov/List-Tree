#include<iostream>
using namespace std;
template<typename T>
class BinaryDerevo {
	int size = 0;
	template<typename T>
	class Date {
		//friend BinaryDerevo;
		Date* pLeft;
		Date* pRight;
		T Data;
	public:
		Date(T dat, Date* pL = nullptr, Date* pR = nullptr) {
			pLeft = pL; pRight = pR; Data = dat;
		}
	};
	Date<T>* pHead;
	void printMove(Date<T>* tmp, int probel = 0) {
		if (tmp == nullptr) return;
		else {
			printMove(tmp->pLeft, ++probel); for (int i = 0; i < probel; ++i) cout << " ";
			cout << tmp->Data << endl; probel--;
		}
		printMove(tmp->pRight, ++probel);
	}
	void push(Date<T>** tmp, T dat) {
		if ((*tmp) == nullptr) { *tmp = new Date<T>(dat); return; }
		if ((*tmp)->Data > dat) { push(&(*tmp)->pRight, dat); return; }
		else if ((*tmp)->Data < dat) { push(&(*tmp)->pLeft, dat); return; }
		else { push(&(*tmp)->pRight, dat); return; }
	}
	T& sc(Date<T>** tmp, T dat) {
		if (tmp == nullptr) { return (*tmp)->Data; }
		else if ((*tmp)->Data == dat)return(*tmp)->Data;
		if ((*tmp)->Data > dat) { return sc(&(*tmp)->pRight, dat); }
		else if ((*tmp)->Data < dat) { return sc(&(*tmp)->pLeft, dat); }
	}

public:
	BinaryDerevo() {
		pHead = nullptr;
	}
	BinaryDerevo(T data) {
		pHead = new Date<T>(data);
		size++;
	}
	void setElement(T dat) {
		push(&pHead, dat);
	}
	void print() { printMove(pHead); }
	void check() {
		cout << pHead->Data;
		if (pHead->pLeft == nullptr) cout << "Lnull ";
		if (pHead->pRight == nullptr) cout << "Rnull ";
	}
	void Diag() { cout << pHead->Data << "L|" << pHead->pLeft->Data << "R|" << pHead->pRight->Data << endl; }
	T& scearth(T s) {return sc(&pHead, s);}
	T max() {
		Date<T>* tmp = pHead;T res = NULL;
		while (tmp != nullptr) {
			res = tmp->Data;tmp = tmp->pLeft;
		}
		return res;
	}
	T min() {
		Date<T>* tmp = pHead;T res = NULL;
		while (tmp != nullptr) {
			res = tmp->Data;tmp = tmp->pRight;
		}
		return res;
	}

};