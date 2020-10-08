#include <stdio.h>
#include <math.h>


int buildPyramid (int start, int end, int MAX_LENGTH, int max_stars);
int get_odd_number (void);

int main(void)
{
    int max_line_len = get_odd_number();
    int max_stars = (max_line_len / 2) + 1;
    buildPyramid(1, max_stars, max_line_len, max_stars);
    buildPyramid(max_stars, 1, max_line_len, max_stars);
    return 0;
}

int buildPyramid (int start, int end, int max_line_len, int max_stars)
{
    for (int i = start; start < end ? i <= end : i >= end; start < end ? i++ : i--) {
        int start_space = max_stars - i;
        int no_stars = i;
        char line[max_line_len];
        // fill in the array with empty chars
        for (int k = 0; k < max_line_len; k++) line[k] = ' ';
        // fill in the array with required n stars
        while (no_stars > 0) {
            line[start_space] = '*';
            no_stars -= 1;
            start_space += 2;
        }
        printf("%s\n", line);
    }
    return 0;
}

int get_odd_number (void)
{
    int num;
    int result;

    while (1) {
        printf("Line width (Odd Number): ");
        result = scanf("%d", &num);
        if (result == 0) {
            // find the new line to recieve new input
            while(fgetc(stdin) != '\n');
        }
        if (num % 2 == 1){
            break;
        } else {
            printf("Error, please enter an odd number.\n");
        }
    }
    return num;
}