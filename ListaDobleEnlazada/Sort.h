#pragma once
#include "Lista.h"
#include <list>

template <class T>
class Sort{
public: 
	typedef typename Nodo<T> Iter;

	static void insertionSortAsc(Lista<T> A);
	static void bubleSort(Lista<T> lst);
	static void selectionSort(Lista<T> vec);
	static void mergeSort(Lista<T>& S);
	static void merge(Lista<T>& S1, Lista<T>& S2, Lista<T>& S);

};

template <class T>
inline void Sort<T>::insertionSortAsc(Lista<T> A){
	Iter* actual = A.root()->getSig();

	for (int i = 1, n=A.size(); i < n; i++) {
		Iter* jota = actual->getAnter();

		while ((actual != A.end()) && (*jota->getInfo() > *jota->getSig()->getInfo())){

			A.swap(jota, jota->getSig());
			if(jota == A.root()){
				break;
			}

			jota = jota->getAnter();
		} 

		actual = actual->getSig();

	}
}

template <class T>
inline void Sort<T>::bubleSort(Lista<T> vec){
	Iter* scc;
	Iter* jota;

	for (int i = 0,n=vec.size(); i < n; i++){		
		 jota = vec.root()->getSig();

		for (int j = 1; j < n - i; j++, jota=jota->getSig()) {

			scc = jota->getAnter();

			if (*scc->getInfo() > *scc->getSig()->getInfo()){
				jota=vec.swap(scc, scc->getSig());

			}
		}

	}
}


template <class T>
void Sort<T>::selectionSort(Lista<T> vec){
	Iter* idei = vec.root();
	Iter* jota=nullptr;

	Iter* minVal = jota;

	
	for (int i = 0, n=vec.size(); idei != vec.end()->getAnter(); i++, idei=idei->getSig()) {
		//valor minimo en el vec sin orden
		minVal = idei;

		jota = idei->getSig();
		for (int j = i + 1,n = vec.size(); j < n; j++) {
			

			if (*jota->getInfo() < *minVal->getInfo()) {
				minVal = jota;

			}
			jota = jota->getSig();
		}
		idei = vec.swap(minVal, idei);
	}
}


template <class T>
void Sort<T>::mergeSort(Lista<T>& S){
	//typedef typename list<int>::iterator itor; //secuencia de elementos
	int n = S.size();
	if (n <= 1) return;
	Lista<T> S1, S2;

	//itor p = S.begin();

	Iter *p = S.root();
	for (int i = 0; i < n / 2; i++) {
		S1.agregarFinal(p->getSig()->getInfo());
		p = p->getSig();
	}
		//S1.push_back(*p++);
	for (int i = n / 2; i < n; i++){
		S2.agregarFinal(p->getSig()->getInfo());
		p = p->getSig();
	}

	//S.clear();
	mergeSort(S1);
	mergeSort(S2);
	merge(S1, S2, S);
}

template <class T>
void Sort<T>::merge(Lista<T>& S1, Lista<T>& S2, Lista<T>& S)
{
	typedef typename list<int>::iterator itor;
	//itor p1 = S1.begin();
	//itor p2 = S2.begin();

	Iter *p1 = S1.root();
	Iter *p2 = S2.root();

	while (p1 != S1.end() && p2 != S2.end()) {
		if (*p1->getInfo() < *p2->getInfo()) {
			S.agregarFinal(p1->getSig()->getInfo());
			p1 = p1->getSig();
		}
		else {
			p2=p2->getSig();
			S.agregarFinal(p2->getSig()->getInfo());
		}
		

	}while (p1 != S1.end()) {
		S.agregarFinal(p1->getSig()->getInfo());
		p1 = p1->getSig();

	}
	while (p2 != S2.end()) {
		S.agregarFinal(p2->getSig()->getInfo());
		p1 = p1->getSig();

	}
}