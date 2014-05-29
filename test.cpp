#include "algorismosOrdenacion.h"
#include <iostream>

using namespace std;

//*******QUICKSORT*******
void TestQuicksort()
{
	
	int x[10] = {1,4,5,2,3,8,1,4,6,9};

	quicksort(x, 0, 9);

	 cout << "QUICKSORT: " << endl;
    for (int i = 0; i < 10; i++ ){
        cout << x[i] << "-";
    }
	cout << endl;

}
//*******CERCA BINARIA*** requereix que el array estigui ordenat*******
void testCercaBinaria()
{
	int x[10] = {0,1,2,3,4,5,6,7,8,9};
	 
	
	 cout  << "CERCA BINARIA: El valor esta?" << CercaBinaria(x, 8) <<endl;
	
}
//*******CERCA SEQUENCIAL*******
void testCercaSequencial()
{
	
	int y[10] = {2,4,7,1,8,9,2,1,3,7};
	int numBuscat = 5;
	
	 cout  << endl  << "CERCA SECUENCIAL: El valor esta?" << CercaSeqüencial(y, numBuscat) << endl;

}
void testOrdenacioInsercio()
{
	int x[10] = {1,4,5,3,6,2,1,4,6,5};
	OrdenacioPerInsercio(x);
	 cout << "ORDENACIO PER INSERCIO: " << endl;

    for (int i = 0; i < 10; i++ ){
        cout << x[i] << "-";
    }
	cout << endl;
}
void testOrdenacioSeleccio()
{
	int x[10] = {7,4,2,3,7,2,1,4,6,5};
	OrdenacioPerSeleccio(x);
	 cout << "ORDENACIO PER SELECCIO: " << endl;

    for (int i = 0; i < 10; i++ ){
        cout << x[i] << "-";
    }
	cout << endl;
}
void testOrdenacioBombolla()
{
		int x[10] = {7,4,9,3,8,2,1,4,7,5};
		OrdenacioBombolla(x);
	 cout << "ORDENACIO PER BOMBOLLA: " << endl;

    for (int i = 0; i < 10; i++ ){
        cout << x[i] << "-";
    }
	cout << endl;
}
int main()
{
	
	testCercaBinaria();
	testCercaSequencial();
	TestQuicksort();
	testOrdenacioInsercio();
	testOrdenacioSeleccio();
	testOrdenacioBombolla();
	

	system("PAUSE");
}

