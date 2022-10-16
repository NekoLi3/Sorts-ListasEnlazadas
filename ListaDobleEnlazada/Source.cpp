#include "Lista.h"
#include "Sort.h"

int main(){
	Lista<int> idk;
	idk.agregarFinal(new int(7));
	idk.agregarFinal(new int(3));
	idk.agregarFinal(new int(20));
	idk.agregarFinal(new int(100));
	idk.agregarFinal(new int(-20));
	idk.agregarFinal(new int(34));
	idk.agregarFinal(new int(34));
	idk.agregarFinal(new int(14));
	idk.agregarFinal(new int(3));
	idk.agregarFinal(new int(152));

	Sort<int>::quickSort(idk);
	cout << idk.toString();

	return 0;
}