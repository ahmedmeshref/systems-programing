#include <stdio.h>
#include <math.h>

int get_positive_number(void);
int fact (int num);


int main (void)
{
    int num = get_positive_number();
    printf("%d! = %d\n", num, fact(num));
    return 0;
}


int get_positive_number (void)
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
        if (num >= 0) {
            break;
        } else {
            printf("Error, please enter a positive number.\n");
        }
    }
    return num;
}


int fact (int num)
{
    if (num <= 1) return 1;
    return num * fact(num - 1);
}