#include "main.h"

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// сортировка пузырьком
void bubble_sort(int *arr, int size){
    for (int j = 0; j < size-1; j++){
        int isSorted = 0;   // флаг для проверки, были ли перестановки в массиве
        for (int i = 0; i < size-1; i++){
            if (arr[i] > arr[i+1]){     // если текущий элемент больше следующего - меняем местами
                swap(&arr[i], &arr[i+1]);
                isSorted = 1;   // меняем флаг - перестановки были
            }
        }
        if (!isSorted) break;   // если перестановок не было, массив уже отсортирован - выход из цикла
    }
}

// сортировка выбором
void selection_sort(int *arr, int size){
    for (int i = 0; i < size - 1; i++){
        int min_index = i;  // пусть индекс текущего элемента будет индексом минимального элемента
        for (int j = i+1; j < size; j++){
                if (arr[j] < arr[min_index]) min_index = j;     // сравниваем текущий элемент с остальными. Если найден меньший элемент - меняем индекс минимального
        }
        if (min_index != i){    // если меньший элемент найден, меняем его с текущим местами
            swap(&arr[i], &arr[min_index]);
        }
    }
}



// функция разделения  массива
int partition(int *arr, int low, int high){
    int pivot = arr[high];  // выбираем опорный элемент
    int i = low;

    // элементы, меньшие опорного, помещаются перед ним, а большие или равные — после
    for (int j = low; j < high; j++){
        if (arr[j] <= pivot){
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

// быстрая сортировка
void quicksort(int *arr, int low, int high){
    if (low < high){
        int p_index = partition(arr, low, high);
        quicksort(arr, low, p_index-1);
        quicksort(arr, p_index+1, high);
    }
}