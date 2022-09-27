
#include "Lista.h"
#include "Sort.h"

int main() {
	Lista<int> lst;
	lst.agregarFinal(new int(4));
	lst.agregarFinal(new int(3));
	lst.agregarFinal(new int(7));
	lst.agregarFinal(new int(1));
	lst.agregarFinal(new int(9));
	lst.agregarFinal(new int(6));

	Sort<int>::inserccionSortAsc(lst);


	return 0;
}