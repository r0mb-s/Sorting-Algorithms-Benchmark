#include <chrono>
#include <cmath>
#include <assert.h>
#include "algoritmi.h"

int main(int argc, char **argv)
{
    assert(argc == 6);
    
    srand(time(0));
    
    
    char *optiune = *(argv + 1);
    assert(verificare(optiune));

    int p1 = atoi(*(argv + 2));
    assert(p1  > 0);
    int nrElementeLista = pow(10, p1);

    int p2 = atoi(*(argv + 3));
    assert(p2 >= 0);
    int nrParcurgeri = pow(10, p2);

    int interval = atoi(*(argv + 4));
    if(interval == 0)
        interval = RAND_MAX;

    int tipListe = atoi(*(argv + 5));
    assert(tipListe == -1 || tipListe == 0 || tipListe == 1);

    std::cout << "\n" << optiune << " sort 10^" << p1 << " ( x10^" << p2 << " )\n\nloading ( % ): ";
    fflush(stdout);

    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point endTime;

    double total;
    int loading = 5;
    for(int p = 1; p <= nrParcurgeri; p++){

        int *lista = new int[nrElementeLista];
        if(lista != nullptr)
            for(int i = 0; i < nrElementeLista; i ++)
                *(lista + i) = rand() % interval;

        if(tipListe == 1 || tipListe == -1){
            timSort(lista, nrElementeLista);
            if(tipListe == -1)
                for(int i = 0; i < nrElementeLista / 2; i++)
                    swap(lista + i, lista + nrElementeLista - 1 - i);
        }

        // afisare(lista, nrElementeLista);

        if(!strcmp(optiune, "bubble")){
            startTime = std::chrono::steady_clock::now();
            bubbleSort(lista, nrElementeLista);
            endTime = std::chrono::steady_clock::now();
        }
        else if(!strcmp(optiune, "insert")){
            startTime = std::chrono::steady_clock::now();
            insertionSort(lista, 0, nrElementeLista - 1);
            endTime = std::chrono::steady_clock::now();
        }
        else if(!strcmp(optiune, "select")){
            startTime = std::chrono::steady_clock::now();
            selectionSort(lista, nrElementeLista);
            endTime = std::chrono::steady_clock::now();
        }
        else if(!strcmp(optiune, "merge")){
            startTime = std::chrono::steady_clock::now();
            mergeSort(lista, 0, nrElementeLista - 1);
            endTime = std::chrono::steady_clock::now();
        }
        else if(!strcmp(optiune, "quick")){
            startTime = std::chrono::steady_clock::now();
            quickSort(lista, 0, nrElementeLista - 1);
            endTime = std::chrono::steady_clock::now();
        }
        else if(!strcmp(optiune, "heap")){
            startTime = std::chrono::steady_clock::now();
            heapSort(lista, nrElementeLista);
            endTime = std::chrono::steady_clock::now();
        }
        else if(!strcmp(optiune, "shell")){
            startTime = std::chrono::steady_clock::now();
            shellSort(lista, nrElementeLista);
            endTime = std::chrono::steady_clock::now();
        }
        else if(!strcmp(optiune, "tim")){
            startTime = std::chrono::steady_clock::now();
            timSort(lista, nrElementeLista);
            endTime = std::chrono::steady_clock::now();
        }
        else if(!strcmp(optiune, "count")){
            startTime = std::chrono::steady_clock::now();
            countingSort(lista, nrElementeLista);
            endTime = std::chrono::steady_clock::now();
        }
        else if(!strcmp(optiune, "radix")){
            startTime = std::chrono::steady_clock::now();
            radixSort(lista, nrElementeLista);
            endTime = std::chrono::steady_clock::now();
        }

        if(checkSorted(lista, nrElementeLista) == true){
            auto duration = (std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count()) / pow(10, 9);
            total += duration;
        }
        else{
            std::cout << "Lista cu numarul " << p << " sortata incorect!!!\n";
            afisare(lista, nrElementeLista);
            return 0;
        }

        delete [] lista;

        double procent = p / (double) nrParcurgeri * 100;
        if(procent - loading < 1 && procent - loading >= 0){
            std::cout << loading << " ";
            loading += 5;
        }
        else if(procent == 2 * loading){
            std::cout << 2 * loading << " ";
            loading += 5;
        }
        
        fflush(stdout);
    }

    std::cout << "\n" << total / nrParcurgeri << " [s]" << "\n\n";

    return 0;
}
