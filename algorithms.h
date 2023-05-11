#include <iostream>
#include <cstdlib>
#include <cstring>

bool checkSorted(int *, int);
void merge(int *, int, int, int);
void swap(int *, int *);
void heapify(int *, int, int);
bool verificare(char *);
void afisare(int *, int);

void bubbleSort(int *, int);
void selectionSort(int *, int);
void insertionSort(int *, int, int);

void mergeSort(int *, int, int);
void quickSort(int *, int, int);
void heapSort(int *, int);
void shellSort(int *, int);
void timSort(int *, int);

void countingSort(int *, int);
void radixSort(int *, int);



void afisare(int *arr, int len){
    int i;
    for(i = 0; i < len - 1; i++)
        std::cout << *(arr + i) << ", ";
    std::cout << *(arr + i) << "\n";
}

bool checkSorted(int *arr, int len){
    for(int i = 0; i < len - 1; i++)
        if(*(arr + i) > *(arr + i + 1))
            return false;
    return true;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int *arr, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;

    int *L = new int[n1];
    int *M = new int[n2];

    for (int i = 0; i < n1; i++)
        *(L + i) = *(arr + p + i);
    for (int j = 0; j < n2; j++)
        *(M + j) = *(arr + q + 1 + j);

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2){
        if (*(L + i) <= *(M + j)){
            *(arr + k) = *(L + i);
            i++;
        }
        else{
            *(arr + k) = *(M + j);
            j++;
        }
        k++;
    }

    while (i < n1){
        *(arr + k) = *(L + i);
        i++;
        k++;
    }

    while (j < n2){
        *(arr + k) = *(M + j);
        j++;
        k++;
    }

    delete [] L;
    delete [] M;
}

void heapify(int *arr, int len, int pos)
{
    int largest = pos;
    int l = 2 * pos + 1;
    int r = 2 * pos + 2;
 
    if (l < len && *(arr + l) > *(arr + largest))
        largest = l;
 
    if (r < len && *(arr + r) > *(arr + largest))
        largest = r;
 
    if (largest != pos) {
        swap(arr + pos, arr + largest);
        heapify(arr, len, largest);
    }
}

bool verificare(char *cuv){
    if(!strcmp(cuv, "bubble"))
        return true;
    if(!strcmp(cuv, "insert"))
        return true;
    if(!strcmp(cuv, "select"))
        return true;
    if(!strcmp(cuv, "merge"))
        return true;
    if(!strcmp(cuv, "quick"))
        return true;
    if(!strcmp(cuv, "heap"))
        return true;
    if(!strcmp(cuv, "shell"))
        return true;
    if(!strcmp(cuv, "tim"))
        return true;
    if(!strcmp(cuv, "count"))
        return true;
    if(!strcmp(cuv, "radix"))
        return true;
    return false;
}


void bubbleSort(int *arr, int len){
    for (int step = 0; step < len - 1; ++step)
        for (int i = 0; i < len - step - 1; ++i)
        if (*(arr + i) > *(arr + i + 1))
            swap(arr + i, arr + i + 1);
}

void insertionSort(int *arr, int l, int r) {
   int key, i, j;
   for(i = l + 1; i < r + 1; i++) {
      key = *(arr + i);
      j = i;
      while(j > l && *(arr + j - 1) > key) {
         arr[j] = *(arr + j - 1);
         j--;
      }
      *(arr + j) = key;
   }
}

void selectionSort(int *arr, int len){
    int min_idx;

    for (int i = 0; i < len - 1; i++){
        min_idx = i;
        for (int j = i + 1; j < len; j++)
          if (*(arr + j) < *(arr + min_idx))
              min_idx = j;

        if(min_idx != i)
            swap(arr + min_idx, arr + i);
    }
}

void shellSort(int *arr, int len){
    int gap = 1;
    int in, out, value;

    while(gap < len / 3)
        gap = gap * 3 + 1;

    while(gap > 0){
        for(out = gap; out < len; out++){
            value = *(arr + out);
            in = out;
            while(in > gap - 1 && *(arr + in - gap) > value){
                *(arr + in) = *(arr + in - gap);
                in -= gap;
            }
            *(arr + in) = value;
        }
        gap = (gap - 1) / 3;
    }
}


void mergeSort(int *arr, int l, int r){
    if (l < r){
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void quickSort(int *arr, int l, int r){
	if(l < r){
		int m = (l + r) / 2;

		int aux = *(arr + l);
		*(arr + l) = *(arr + m);
		*(arr + m) = aux;

		int i = l , j = r, d = 0;
		while(i < j){
			if(*(arr + i) > *(arr + j)){
				swap(arr + i, arr + j);
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		quickSort(arr, l , i - 1);
		quickSort(arr, i + 1 , r);
	}
}

void heapSort(int *arr, int len){
    for (int i = len / 2 - 1; i >= 0; i--)
        heapify(arr, len, i);
 
    for (int i = len - 1; i > 0; i--){
        swap(arr, arr + i);
        heapify(arr, i, 0);
    }
}

void timSort(int *arr, int len){  
    for (int i = 0; i < len; i += 32)
        if(i + 32 - 1 <= len - 1)
            insertionSort(arr, i, i + 32 - 1);
        else
            insertionSort(arr, i, len - 1);

    int left, mid, right;
    for (int size = 32; size < len; size *= 2){  
        for (left = 0; left < len; left += 2 * size){  
            mid = left + size - 1;

            if(left + 2 * size - 1 <= len - 1)
                right = left + 2 * size - 1;
            else
                right = len - 1;
            
            if(mid < right)
                merge(arr, left, mid, right);  
        }  
    }  
}  


void countingSort(int *arr, int len){
    int *output = new int[len + 1];

    int max = *(arr);
    for(int i = 1; i < len; i++)
        if(*(arr + i) > max)
            max = *(arr + i);

    int *count = new int[max + 1];
    
    for (int i = 0; i <= max; ++i){
        *(count + i) = 0;
    }

    for (int i = 0; i < len; i++){
        (*(count + *(arr + i)))++;
    }

    for(int i = 1; i <= max; i++)
        *(count + i) += *(count + i - 1);
    
    for (int i = len - 1; i >= 0; i--){
        *(output + *(count + *(arr + i)) - 1) = *(arr + i);
        (*(count + *(arr + i)))--;
    }

    for(int i = 0; i < len; i++)
        *(arr + i) = *(output + i);

    delete [] count;
    delete [] output;
}

void countingSortRadix(int *arr, int len, int place){
    int *output = new int[len + 1];
    int count[10] = {0};
    
    for (int i = 0; i < len; i++)
        (*(count + ((*(arr + i) / place) % 10)))++;
    
    for (int i = 1; i < 10; i++)  
        *(count + i) += *(count + i - 1);  
    
    for (int i = len - 1; i >= 0; i--) {  
        *(output + *(count + ((*(arr + i) / place) % 10)) - 1) = *(arr + i);  
        (*(count + ((*(arr + i) / place) % 10)))--;  
    }  
    
    for (int i = 0; i < len; i++)  
        *(arr + i) = *(output + i);
    
    delete [] output;
}

void radixSort(int *arr, int len){
    int max = *(arr);
    for(int i = 1; i < len; i++)
        if(*(arr + i) > max)
            max = *(arr + i);

    for (int place = 1; max / place > 0; place *= 10)
        countingSortRadix(arr, len, place);
}
