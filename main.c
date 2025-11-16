#include "main.h"

int main(){

    int arrs_sizes[] = {N1, N2, N3, N4};    // размеры массивов
    double bubble_time[4] = {0};            // значения времени выполнения сортировки пузырьком массивов разной длины
    double selection_time[4] = {0};         // значения времени сортировка выбором
    double quick_time[4] = {0};             // значения времени быстрая сортировка

    for (int j = 0; j < 3; j++){    // j - текущий вид сортировки
        for (int i = 0; i < 4; i++){    // i - указатель на текущий размер массива
            int* arr = create_array(arrs_sizes[i]);
            clock_t start = clock();    // время на момент начала сортировки
            
            // выбираем алгоритм сортировки исходя из значения j
            switch (j){
                case 0: bubble_sort(arr, arrs_sizes[i]); break;
                case 1: selection_sort(arr, arrs_sizes[i]); break;
                case 2: quicksort(arr, 0, arrs_sizes[i]-1); break;
            }
            clock_t end = clock();  // время на момент конца сортировки
            
            // записываем затраченое время на сортировку в соответствующий массив
            switch (j){
                case 0: bubble_time[i] = (double)(end - start) / CLOCKS_PER_SEC; break;
                case 1: selection_time[i] = (double)(end - start) / CLOCKS_PER_SEC; break;
                case 2: quick_time[i] = (double)(end - start) / CLOCKS_PER_SEC; break;
            }

            // вывод текущего прогресса сортировки в рамках одного алгоритма
            printf("Sorting (%d/4)...\n", i+1);
            free_array(arr);
        }

        // выводим, сколько алгоритмов успешно отработали
        printf("Success (%d/3)\n", j+1);
        printf("\n");
    }

    printf("============== ВРЕМЯ  СОРТИРОВКИ ==============\n");
    printf("| Размер  | Пузырьком | Выбором   | Быстрая  |\n");
    printf("|---------|-----------|-----------|----------|\n");
    printf("| %-7d | %.8lf | %.8lf | %.8lf |\n", N1, bubble_time[0], selection_time[0], quick_time[0]);
    printf("| %-7d | %.8lf | %.8lf | %.8lf |\n", N2, bubble_time[1], selection_time[1], quick_time[1]);
    printf("| %-7d | %.8lf | %.8lf | %.8lf |\n", N3, bubble_time[2], selection_time[2], quick_time[2]);
    printf("| %-7d | %.8lf | %.8lf | %.8lf |\n", N4, bubble_time[3], selection_time[3], quick_time[3]);
    printf("===============================================\n");

    return 0;
}