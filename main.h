#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N1 10
#define N2 1000
#define N3 10000
#define N4 100000

// массивы
int* create_array(int size);
void fill_array(int *arr, int size);
void print_array(int *arr, int size);
void free_array(int *arr);

// сортировка
void swap(int *a, int *b, unsigned int *swap_count);  // функция для обмена элементов местами

void bubble_sort(int *arr, int size, unsigned int *swap_count);   // сортировка пузырьком
void selection_sort(int *arr, int size, unsigned int *swap_count);    // сортировка выбором

void quicksort_main(int *arr, int size, unsigned int *swap_count);    // Обертка быстрой сортировки для первого вызова
void quicksort(int *arr, int low, int high, unsigned int *swap_count);     // быстрая сортировка
int partition(int *arr, int low, int high, unsigned int *swap_count);      // функция разделения массива
int choose_pivot(int *arr, int low, int high, unsigned int *swap_count);   // функция выбора опорного элемента

#endif
