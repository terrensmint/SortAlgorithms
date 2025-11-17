#include "main.h"

// перестановка
void swap(int *a, int *b, unsigned int *swap_count){
    int temp = *a;
    *a = *b;
    *b = temp;
    (*swap_count)++;    // подсчет количества перестановок
}

// сортировка пузырьком
void bubble_sort(int *arr, int size, unsigned int *swap_count){
    *swap_count = 0;    // обнуляем счетчик перестановок
    for (int j = 0; j < size-1; j++){
        int isSorted = 0;   // флаг для проверки, были ли перестановки в массиве
        for (int i = 0; i < size-1-j; i++){
            if (arr[i] > arr[i+1]){     // если текущий элемент больше следующего - меняем местами
                swap(&arr[i], &arr[i+1], swap_count);
                isSorted = 1;   // меняем флаг - перестановки были
            }
        }
        if (!isSorted) break;   // если перестановок не было, массив уже отсортирован - выход из цикла
    }
}

// сортировка выбором
void selection_sort(int *arr, int size, unsigned int *swap_count){
    *swap_count = 0;    // обнуляем счетчик перестановок
    for (int i = 0; i < size - 1; i++){
        int min_index = i;  // пусть индекс текущего элемента будет индексом минимального элемента
        for (int j = i+1; j < size; j++){
                if (arr[j] < arr[min_index]) min_index = j;     // сравниваем текущий элемент с остальными. Если найден меньший элемент - меняем индекс минимального
        }
        if (min_index != i){    // если меньший элемент найден, меняем его с текущим местами
            swap(&arr[i], &arr[min_index], swap_count);
        }
    }
}

// функция выбора опорного элемента как медианы
int choose_pivot(int *arr, int low, int high, unsigned int *swap_count){
    int middle = (low + high) / 2;  // медиана
    if (arr[middle] < arr[low]) swap(&arr[middle], &arr[low], swap_count);
    if (arr[high] < arr[low]) swap(&arr[high], &arr[low], swap_count);
    if (arr[middle] < arr[high]) swap(&arr[middle], &arr[high], swap_count);

    return arr[high];   // опорный элемент
}

// функция разделения  массива (по Хоару)
int partition(int *arr, int low, int high, unsigned int *swap_count){
    int pivot = choose_pivot(arr, low, high, swap_count);  // выбираем опорный элемент
    int i = low-1;
    int j = high+1;

    while (1){

        // Двигаем указатель i вправо, пока не найдем элемент больше опорного
        do {i++;} while (arr[i] < pivot);
        // Двигаем указатель j влево, пока не найдем элемент меньше опорного
        do {j--;} while (arr[j] > pivot);

        // Если указатели пересеклись или встретились - разделение завершено
        if (i >= j){
            // Возвращаем j - индекс, разделяющий массив на две части
            return j;
        }
        swap(&arr[i], &arr[j], swap_count);
    }

    /* Ломуто
    // элементы, меньшие опорного, помещаются перед ним, а большие или равные — после
    for (int j = low; j < high; j++){
        if (arr[j] <= pivot){
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
    */
}

// быстрая сортировка
void quicksort(int *arr, int low, int high, unsigned int *swap_count){
    if (low < high){
        int p_index = partition(arr, low, high, swap_count);
        quicksort(arr, low, p_index, swap_count);
        quicksort(arr, p_index+1, high, swap_count);
    }
}

// Обертка для быстрой сортировки для первого вызова
void quicksort_main(int *arr, int size, unsigned int *swap_count) {
    *swap_count = 0;    // обнуляем счетчик перестановок
    quicksort(arr, 0, size-1, swap_count);
}