
#include "Lista.h"
#include "Sort.h"

int main() {
	Lista<int> lst;
	lst.agregarFinal(new int(4));
	lst.agregarFinal(new int(3));
	lst.agregarFinal(new int(7));
	lst.agregarFinal(new int(1));
	lst.agregarFinal(new int(48));

	lst.agregarFinal(new int(9));
	lst.agregarFinal(new int(6));
	lst.agregarFinal(new int(7));
	lst.agregarFinal(new int(1));
	lst.agregarFinal(new int(-1));

	Sort<int>::bubleSort(lst);

	//Sort<int>::insertionSortAsc(lst);


	return 0;
}