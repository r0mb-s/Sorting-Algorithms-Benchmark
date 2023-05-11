# Sorting-Algorithms-Benchmark

Pentru a folosi programul, compilați fișierul main.cpp, iar apoi dintr-o linie de comandă rulați executabilul
main cu următorii parametri:

Primul argument reprezintă algoritmul pe care doriți să îl testați și se vor folosi cuvintele cheie: "bubble" (Bubble Sort), "insert" (Insertion Sort), "select" (Selection Sort), "quick" (QuickSort), "merge" (Merge Sort), "heap" (Heap Sort), "shell" (Shell Sort), "tim" (Tim Sort), "count" (Counting Sort), "radix" (Radix Sort)

Al doilea argument reprezintă lungimea listei. Aceasta se va introduce ca un numă natural $n$, unde lungimea listei va fi $10^n$

Al treilea argument reprezintă numărul de liste. Aceasta se va introduce ca un numă natural $n$, unde lungimea listei va fi $10^n$.

Al patrulea argument reprezintă intervalul elementelor din listă. Dacă valoarea trecută este $0$, atunci intervalul va fi constanta RAND_MAX

Al cincelea argument va specifica dacă lista random generată va fi: crescătoare ($1$), descrecătoare ($-1$) sau random ($0$)

Astfel, o comanda valida ar fi:

main merge 9 2 999 -1
care va sorta $10^2$ liste descrescătoare de $10^9$ elemente din intervalul $[0, 999]$ folosind Merge Sort

sau

main bubble 2 0 1 0
care va sorta $10^0$ liste random de $10^1$ elemente din intervalul $[0, 2^{32}]$ folosind Bubble Sort
