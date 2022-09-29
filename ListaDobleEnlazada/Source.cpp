#include "Lista.h"
#include "Sort.h"

int main() {
	//pruebas
	Lista<int> lst, piko;
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
	cout << lst.toString();

	piko.agregarIni(new int(1));
	piko.agregarIni(new int(31));
	piko.agregarIni(new int(194));
	piko.agregarIni(new int(12));
	piko.agregarIni(new int(193));
	piko.agregarIni(new int(11));
	piko.agregarIni(new int(173));

	Sort<int>::insertionSortAsc(piko);
	cout << piko.toString();


	return 0;
}