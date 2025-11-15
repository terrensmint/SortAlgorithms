#include "main.h"

int main(){
    int* arr1 = create_array(N1);
    fill_array(arr1, N1);
    int* arr2 = create_array(N1);
    fill_array(arr2, N1);
    int* arr3 = create_array(N1);
    fill_array(arr3, N1);

    printf("\n");
    print_array(arr1, N1);
    bubble_sort(arr1, N1);
    print_array(arr1, N1);
    printf("\n");

    print_array(arr2, N1);
    selection_sort(arr2, N1);
    print_array(arr2, N1);
    printf("\n");

    print_array(arr3, N1);
    quicksort(arr3, 0, N1);
    print_array(arr3, N1);
    printf("\n");

    return 0;
}