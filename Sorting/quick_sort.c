#include "stdio.h"

void _quickSort(int *array, int first, int last){
    if (first < last) {
        int left = first;
        int right = last;
        int middle = array[(left + right) / 2];
        do {
            while (array[left] < middle){
                left++;
            }
            while (array[right] > middle){
                right--;
            }
            if (left <= right){
                int tmp = array[left];
                array[left] = array[right];
                array[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        _quickSort(array, first, right);
        _quickSort(array, left, last);
    }
}

void quickSort(int* array, int size){
    _quickSort(array, 0, size - 1);
}

void print_array(int* array, int size){
    printf("array:");
    for (int i = 0; i < size; ++i){
        printf(" %d", array[i]);
    }
    printf("\n");
}

int main() {
    int n = 5;
    int a[5] = {4, 2, 1, 9, 3}; 
    quickSort(a, n);
    print_array(a, n);
}
