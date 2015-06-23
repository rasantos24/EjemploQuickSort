#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "quicksort.cpp"
#include <time.h>

using namespace std;

int main()
{
    int const MAX = 100;
    int arraySize;

    clock_t start_time;
    clock_t final_time;
    double total_time;
    start_time = clock();

    cout << "Ingresa tamanyo: " << endl;
    cin >> arraySize;

    int a[arraySize];

    // Para que el rand no genere siempre los mismos números, utilizando la hora del sistema
    srand(time(0));

    // Para generar enteros aleatorios usamos rand()
    for (int i = 0; i < arraySize; i++) {
        a[i] = rand() % MAX;
    }

    cout << "Array antes de ordenarse: " << endl;
    for (int i = 0; i < arraySize; i++) {
        cout << a[i] << " ";
    }

    cout << endl << endl;

    quicksort(a, 0, arraySize - 1);

    final_time = clock();
    total_time = ((double)(final_time - start_time)) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecución : %lf segundos \n", total_time);

    cout << "Array ordenado " << endl;
    for (int i = 0; i < arraySize; i++ ){
        cout << a[i] << "-";
    }

    cout << endl << endl;

    return 0;
}
