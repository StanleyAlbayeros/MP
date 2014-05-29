#include "algorismosOrdenacion.h"

//***********************CERCA SI UN ELEMENT EXISTEIX********************

//sense requerir está ordenat
bool CercaSeqüencial(int v[MAX], int x)
{
   int i = 0;  
   bool trobat;

   trobat = false;
	
   while ((i < MAX) && (!trobat) )
	{
		trobat = (v[i] == x); //si x es = a algun valor del array s'acaba
	
		if ((!trobat))
			i = i+1;
    }
    return trobat;
}
//SENSE RECURSIVITAT
bool CercaBinaria (int v[MAX], int x)
{ 
	int primer, ultim, central;
	bool trobat;

	trobat = false;
	primer = 0;    /* Inicialment l’espai de cerca és tot el  vector */
	ultim = MAX;  		
	while ((primer < ultim) && !trobat)  /* Si no casos bàsics */
	{
		central = (primer + ultim) / 2;  	/* Element central */
		trobat = (v[central] == x); 		
		if (!trobat)
		{
			if (v[central] > x) 	/* x a l’esquerra de l’element central */
				ultim = central - 1;  
			else				/* x a la dreta de l’element central */
				primer = central + 1;  	 
		}
	}
	return trobat;
}
//RECURSIU
bool CercaBinaria (int v[MAX], int x, int primer, int ultim)
{
	bool trobat;
	int central;
	
   if (primer > ultim)
		trobat = false;
	else 
	{
		central = (primer + ultim) / 2;  	
	 	trobat = (v[central] == x);
	 	if (!trobat)
	 	{
			if (v[central] > x)
	       	trobat = CercaBinaria ( v, x, primer, central-1);
			else
		   		trobat = CercaBinaria ( v, x, central + 1, ultim); 
	 	}				        
	}
	return trobat;
}
//*********************************************************************************

//***********************ORDENACIÓ DEL ARRAY***********************************

//ORDENACIO PER INSERCIO!!!!!!!!!!!!

/* Busca la posició que ha d’ocupar x a la part ordenada de v, de 0 a PosMax */
int static BuscarPosicio(int v[MAX], int PosMax, int x)
{
  	int pos, i;
  	pos = 0;
  	while ((pos <= PosMax) && (v[pos] < x))
   	pos = pos + 1;
  	return pos;
}
/* Insereix x a v[pos], movent a la dreta la resta d’elements ordenats */
void static InserirOrdenat(int v[MAX], int pos, int PosMax, int x)
{
	for (int i=PosMax; i >= pos; i--) 
   	v[i+1] = v[i];
 	v[pos] = x;
}

void OrdenacioPerInsercio(int v[MAX])
{
	int index, PosM;
  	index = 1;				/* Suposem primer element ja ordenat */
  	while (index < MAX) 	/* Nº iteracions = nº elements -1 */
  	{
     	PosM = BuscarPosicio (v, index-1, v[index]); /* Busca on inserir */
     	InserirOrdenat (v, PosM, index-1, v[index]); /* Insereix element a Pos */
     	index = index + 1;		/* Incrementa índex elements ordenats */
  	}
}

//ORDENACIO PER SELECCIO!!!!!!!!!!!!!!!!!!!!!!!!1

int static BuscarMinim (int v[MAX], int index)
{
	int PosMin, i;
 	PosMin = index;       /* Hem de trobar el mínim a la dreta d’índex */
  	for (i=PosMin+1; i< MAX;i++) 
  		if (v[i] < v[PosMin]) 
			PosMin = i;
	return PosMin;
}

void OrdenacioPerSeleccio (int v[MAX])
{
	int index, PosMin, aux;
    
	index = 0;
 	while (index < MAX) 	/* Nº iteracions = nº elements – 1 */
  	{
	PosMin = BuscarMinim (v, index); /* Posició mínim a dreta d’index */
	aux = v[PosMin];	/* Intercanviar elements de PosMin i index */
	v[PosMin] = v[index];		
	v[index] = aux;
	index = index + 1;	/* Tenim un element més classificat */
	}
}

//BOMBOLLA!!!!!!!!!!!!!!!
void OrdenacioBombolla(int v[MAX])
{
	int i, index, aux;

	i = 0;
	bool ordenat = false;
  	while ((i < MAX) && !ordenat) 	/* Nº iteracions max = nº elements */
	{
		ordenat = true;	/* Marcador per saber si ja està ordenat */
		for (index=0; index < MAX - (i + 1); index++)
	{
		if (v[index] > v[index+1])
   	{
	 		aux = v[index];	/* Intercanviar si no estan en ordre */
	    	v[index] = v[index+1];	
	    	v[index+1] = aux;
			ordenat = false;	/* Marcar com a no ordenat encara */
		}
	}
	i++;	
	}
}



//QUICKSTART!!!!!!!!!!!!!!!!!!!!!!!!!
 
// Función para dividir el array y hacer los intercambios Utilizada en QUICKSORT
int static divide(int *array, int start, int end) {
    int left;
    int right;
    int pivot;
    int temp;
 
	//COLOCAMOS EL PIVOT EN EL PRIMER NUMERO, LEFT AL PRIMERO Y RIGHT AL ÚLTIMO
    pivot = array[start];
    left = start;
    right = end;
 
    // Mientras no se cruzen los índices
    while (left < right) {
		//disminuyes una posicion en el de la derecha
        while (array[right] > pivot) {
            right--;
        }
		//augmentas una posicion al array de la izquierda
        while ((left < right) && (array[left] <= pivot)) {
            left++;
        }
 
        // Si todavía no se cruzan los indices seguimos intercambiando
        if (left < right) {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
    }
 
    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = array[right];
    array[right] = array[start];
    array[start] = temp;
 
    // Right es la posicion intermedia del array
    return right;
}
// Función recursiva para hacer el ordenamiento
void quicksort(int *array, int start, int end)
{
    int pivot;
 
    if (start < end) {
        pivot = divide(array, start, end);
 
        // Ordeno la lista de los menores
        quicksort(array, start, pivot - 1);
 
        // Ordeno la lista de los mayores
        quicksort(array, pivot + 1, end);
    }
}

