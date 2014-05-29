const int MAX = 10;


//******ALGORISMES PER BUSCAR SI UN NUMERO ESTÁ EN EL ARRAY******

//Returna true si el numero está en el array o false  si no esta
bool CercaSeqüencial(int v[MAX], int x);


//buscar si un element existeix de forma NO RECURSIVA, REQUEREIX ESTÁ ORDENAT
bool CercaBinaria (int v[MAX], int x);
//Buscar si un element existeix de forma recursiva, REQUEREIX ESTÁ ORDENAT
bool CercaBinaria (int v[MAX], int x, int primer, int ultim);

//************************************************************

//A mida que arriben els elements, els inserim ordenats a la posició que els correspon
void OrdenacioPerInsercio(int v[MAX]);

//Seleccionar el més petit i posar-lo a la primera posició
//Seleccionar el segon més petit i posar-lo a la segona ...
void OrdenacioPerSeleccio (int v[MAX]);

//ordena per intercambi de posicions
void OrdenacioBombolla(int v[MAX]);

//Ordenación recursiva, generalmente mas eficaz
void quicksort(int *array, int start, int end);

