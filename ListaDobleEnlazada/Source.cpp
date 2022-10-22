#include "Lista.h"
#include "Sort.h"

int main(){
	Lista<int> idk;
	idk.agregarFinal(new int(8));
	idk.agregarFinal(new int(10));
	idk.agregarFinal(new int(9));
	idk.agregarFinal(new int(28));
	idk.agregarFinal(new int(30));
	idk.agregarFinal(new int(49));
	idk.agregarFinal(new int(28));
	idk.agregarFinal(new int(150));
	idk.agregarFinal(new int(966));

	Sort<int>::quickSort(idk);
	cout << idk.toString();

	return 0;
}