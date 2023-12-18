#include <iostream>

using namespace std;

void quickSort_impl(int tab[], int left, int right) 
{ 
    int i = left, j = right;
    int tmp;
    int pivot = tab[(left + right) / 2];
  
    while (i <= j) {
        while (tab[i] < pivot)
            i++;
        while (tab[j] > pivot)
            j--;
        if (i <= j) {
            tmp = tab[i];
            tab[i] = tab[j];
            tab[j] = tmp;
            i++;
            j--;
        }
    };
  
    if (left < j)
        quickSort_impl(tab, left, j);
    if (i < right)
        quickSort_impl(tab, i, right);
}

void quickSort(int tab[], int size) 
{ 
    quickSort_impl(tab, 0, size - 1); 
} 