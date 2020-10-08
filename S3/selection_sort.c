#include <stdio.h>

int* selection_sort(int arr[]);

int main(void) 
{
    int arr[5] = {6, 3, 7, 2, 1};
    int* sorted_arr = selection_sort(arr);
    for (int i = 0; i < 5; i++){
        printf("%d, ", sorted_arr[i]);
    }
    printf("\n");
    return 0;
}

int* selection_sort(int arr[])
{
    for (int i = 0; i < 5; i++){
        // find min number 
        int min_pos = i;
        for (int j = i + 1; j < 5; j++){
            if (arr[min_pos] > arr[j]) min_pos = j;
        }
        int temp = arr[i];
        printf("%d, %d\n", i, min_pos);
        arr[i] = arr[min_pos];
        arr[min_pos] = temp; 
    }
    return arr;
}
