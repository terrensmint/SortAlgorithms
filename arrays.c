#include "main.h"

// Динамическое выделение памяти под массив
int* create_array(int size){
    return (int*)malloc(size * sizeof(int));
}

// Заполнение массива рандомными целыми числами
void fill_array(int *arr, int size){
    for (int i = 0; i < size; i++){
        arr[i] = rand();
    }
}

// Вывод массива
void print_array(int *arr, int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Освобождение памяти
void free_array(int *arr){
    free(arr);
}