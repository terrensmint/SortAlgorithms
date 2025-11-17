#include "main.h"

// Динамическое выделение памяти под массив
int* create_array(int size){
    int* array = (int*)malloc(size * sizeof(int));
    if (array == NULL){
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    fill_array(array, size);
    return array;
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