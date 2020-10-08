#include <stdio.h>
#include <stdlib.h>

int get_positive_number(void);
int nearest_sqrt(int num);

int main(void)
{
    int n = get_positive_number();
    printf("Nearst Sqrt: %d\n", nearest_sqrt(n));
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


int nearest_sqrt(int num)
{
    int i = 1, nearest_sqrt = 1;
    while (1) {
        if (abs(num - nearest_sqrt) >= abs(num - (i*i))) {
            nearest_sqrt = i*i;
            i++;
        } else {
            break;
        }
    }
    return nearest_sqrt;
}