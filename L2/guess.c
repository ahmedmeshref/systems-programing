#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int gen_rand_num(int lower, int upper);
int guess_game (int rand_num, int attempts);
int get_number (void);

int main(void)
{
    // generate a random number
    int min = 0, max = 500, attempts = 10;
    int rand_num = gen_rand_num(min, max);
    guess_game(rand_num, attempts);
    return 0;
}

int gen_rand_num(int lower, int upper)
{
    // seed the rand fun
    srand(time(NULL));
    // Todo: Randomize negative vals!
    return rand() % (upper - lower);
}

int guess_game (int num, int attempts)
{
    int guessed_num;
    for (int i = 1; i <= attempts; i++){
        guessed_num = get_number();
        if (num == guessed_num) {
            printf("Congratulations, you made it in %d attempts.\n", i);
            return 0;
        } else if (num > guessed_num) {
            printf("Attempt %d: Your number is too low.\n", i);
        } else {
            printf("Attempt %d: Your number is too high.\n", i);
        }
    }
    printf("Game over, you used all %d attempts. Actual number is %d.\n", attempts, num);
    return 0;
}


int get_number (void)
{
    int num;
    int result;

    while (1) {
        printf("Number: ");
        result = scanf("%d", &num);
        if (result == 0) {
            // find the new line to recieve new input
            while(fgetc(stdin) != '\n');
            printf("Error, please enter a number.\n");
        } else {
            break;
        }
    }
    return num;
}