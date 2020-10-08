#include <stdio.h>
#include <stdlib.h>


int get_positive_number(void);


int main(void)
{
    int n, odd_sum = 0, even_sum = 0;
    n = get_positive_number();
    // how to return two values in C function and what are prototypes?
    for (int i = 0; i <= n; i++){
        if (i % 2 == 0) {
            even_sum += i;
        } else {
            odd_sum += i;
        }
    }
    printf("Odd Sum = %d\n", odd_sum);
    printf("Even Sum = %d\n", even_sum);
    printf("Absolute Diff = %d\n", abs(odd_sum - even_sum));
    printf("1/3 of even sum = %f\n", (float) even_sum / 3.0);
    printf("1/5 of odd sum = %f\n", (float) odd_sum / 5.0);
}

int get_positive_number(void)
{
    int num;
    int result;

    while (1) {
        printf("Positive Number: ");
        result = scanf("%d", &num);
        if (result == 0) {
            // find the new line to recieve new input
            while(fgetc(stdin) != '\n');
        }
        if (num > 0) {
            break;
        } else {
            printf("Error, please enter a positive number.\n");
        }
    }
    return num;
}
