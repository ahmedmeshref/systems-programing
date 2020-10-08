#include <stdio.h>

const int size = 10;

void get_min_max(int nums[], int *min, int *max);

int main(void)
{
    int nums[size], result;
    for (int i = 0; i < size; i++){
        // nums[i] = get_int("Number: ");
        printf("Number: ");
        result = scanf("%d", &nums[i]);
        if (result == 0) {
            // find the new line to recieve new input
            while(fgetc(stdin) != '\n');
            printf("Error, numbers only!\n");
        }
    }
    int min_val, max_val;
    get_min_max(nums, &min_val, &max_val);
    printf("Min: %i\nMax: %i\n", min_val, max_val);

}


void get_min_max(int nums[], int *min, int *max)
{
    *min = *max= nums[0];
    for (int i = 1; i < size; i++){
        if (nums[i] < *min) *min = nums[i];
        if (nums[i] > *max) *max = nums[i];
    }
}

