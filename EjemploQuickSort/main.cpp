#include <QCoreApplication>

#include <iostream>
using namespace std;
#define ARRAY_SIZE 10 // Tamanio de mi matriz
void printArray(int* array, int n);
void quickSort(int* array, int inicio, int final);
int splitArray(int* array, int pivote, int inicio, int final);
void swap(int &a, int &b);

int main(void)
{
    int array[ARRAY_SIZE];
    for(int x=0; x<ARRAY_SIZE; x++)
    {
        cout<<"Introduzca un numero entero: ";
        cin>>array[x];
    }

    cout<<endl<<"La lista ingresada es: "<<endl;
    printArray(array, ARRAY_SIZE);
    quickSort(array, 0, ARRAY_SIZE-1);

    cout<<endl<<"La lista ordenada es: "<<endl;
    printArray(array, ARRAY_SIZE);

    cin.get();
    cin.get();

    return 0;
}

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void printArray(int *array, int n)
{
    for(int x=0; x<n; x++)
        cout<<array[x]<<'\t';
}

void quickSort(int *array, int inicio, int final)
{
    int pivote = array[inicio];
    int split;

    if(final > inicio)
    {
        split = splitArray(array, pivote, inicio, final);

        array[split] = pivote;
        quickSort(array, inicio, split-1);
        quickSort(array, split+1, final);
    }
}

int splitArray(int *array, int pivote, int inicio, int final)
{
    int izquierdo = inicio;
    int derecho = final;

    while(izquierdo < derecho)
    {
        while(pivote < array[derecho] && derecho > izquierdo)
            derecho--;

        swap(array[izquierdo], array[derecho]);

        while(pivote >= array[izquierdo] && izquierdo < derecho)
            izquierdo++;

        swap(array[derecho], array[izquierdo]);
    }

    return izquierdo;
}
