#pragma once
#include "Lista.h"

template <class T>
class Sort{
public: 
	typedef typename Nodo<T> Iter;

	static void insertionSortAsc(Lista<T> A);
	static void bubleSort(Lista<T> lst);
	static void selectionSort(Lista<T> vec);

	static void quickSort(Lista<T> lst);

private:

	struct Iterador{
		T* valor;
		Nodo<T>* nd;
		int indice;
		Iterador(Nodo<T> *nod, T* valor = nullptr) :nd(nod), valor(nod->getInfo()), indice(0){}
		Iterador i(int i){
			indice = i;
			return *this;
		}
		void st(Nodo<T>* nod){
			nd = nod;
			valor = nod->getInfo();
		}

		Iterador swap(Iterador& ref){
			T* aux = this->valor;
			this->nd->setInfo(ref.nd->getInfo());
			

			ref.nd->setInfo(aux);

			ref.st(ref.nd);
			this->st(this->nd);
			return *this;
		}
		Iterador operator++(int k){
			this->nd = this->nd->getSig();
			valor = nd->getInfo();
			//indice++;
			return *this;
		}
		Iterador operator--(int k){
			this->nd = this->nd->getAnter();
			valor = nd->getInfo();
			//indice--;
			return *this;
		}

	};
	
	static void quickSortStep(Lista<T> lst, Iterador begin, Iterador fin);

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


template<class T>
inline void Sort<T>::quickSort(Lista<T> lst){
	if(lst.size() <= 1)return;
	quickSortStep(lst, Iterador(lst.root()), Iterador(lst.end()->getAnter()).i(lst.size()-1));
}

template<class T>
inline void Sort<T>::quickSortStep(Lista<T> lst, Iterador a, Iterador b){

	T pivot = *a.valor;
	Iterador r(b.nd);
	Iterador l(a.nd);
	r.i(b.indice);
	l.i(a.indice);
	int i=a.indice, j=b.indice;
	if(a.nd == b.nd) return;

	if(l.nd == lst.end() || r.nd == lst.root())return;

	while(i<j){

		while(*l.valor<=pivot && i<j){ 
			l++, i++;
		}

		while(*r.valor > pivot && r.nd!=l.nd){
			r--,j--;
		}


		if(i<j){ //swap

			l.swap(r);

		}
	}

	l.i(i);
	r.i(j);

	if(pivot > *r.valor){
		r++;
	}
	lst.agregar(r.nd, new T(*a.valor));
	a++;
	lst.borrar(a.nd->getAnter());

	//lst.agregar(l.nd, new T(*a.valor));
	//a++;
	//lst.borrar(a.nd->getAnter());
	//
	//lst.borrarIni();
	//cout << lst.toString();
	if(a.indice < j - 1){
		quickSortStep(lst, a, Iterador(r.nd->getAnter()).i(r.indice-1));
	}
	if(j + 1 < b.indice){
		quickSortStep(lst, Iterador(r.nd).i(r.indice), b);
	}

	
}
