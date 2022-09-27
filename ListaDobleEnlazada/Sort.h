#pragma once
#include "Lista.h"
template <class T>
class Sort{
public: 
	typedef typename Nodo<T> Iter;
	static void inserccionSortAsc(Lista<T> A);
	//static void bubleSort(Lista<T> lst);

};

template <class T>
inline void Sort<T>::inserccionSortAsc(Lista<T> A){
	Iter* actual = A.root()->getSig();
	

	for (int i = 1, n=A.size(); i < n; i++) {
		
		Iter* jota = actual->getAnter();

		while ((jota != A.root() && actual != A.end()) && (*jota->getInfo() > *actual->getInfo())) {
			jota = jota->getAnter();

		} 
		actual = A.swap(jota, actual)->getSig();
		//A[j + 1] = cur; //lugar correcto de cur
	}
}
//
//template <class T>
//inline void Sort<T>::bubleSort(Lista<T> vec)
//{
//	for (int i = 0; i < n; i++) {
//		for (int j = 1; j < n - i; j++) {
//			int prec = vec[j - 1];
//			int succ = vec[j];
//			if (prec > succ) {
//				int tmp = vec[j - 1];
//				vec[j - 1] = vec[j];
//				vec[j] = tmp;
//			}
//		}
//	}
//}


