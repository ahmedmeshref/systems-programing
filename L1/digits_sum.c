#include <stdio.h>
#include <math.h>

// prototypes
int get_positive_number(void);
int sum_of_digits(int num);

int main(void)
{
    // get positive number
    int n = get_positive_number();
    printf("Digits Sum = %d\n", sum_of_digits(n));
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

int sum_of_digits(int num){
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num = floor(num / 10);
    }
    return sum;
}
