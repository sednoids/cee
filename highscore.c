#include <stdio.h>
#define true 1


void highscoreTable(int* array) {
    printf("----- HIGH SCORE TABLE -----\n");

    for (int i = 0; i < 10; i++) {
        printf("%d - %d\n", i + 1, array[i]);
    }
}

int minimumValue(int* array) {
    int minimum = array[0];

    for (int i = 1; i < 10; i++) {
        if (array[i] <= minimum) {
            minimum = array[i];
        }
    }
    return minimum;
}

int maximumValue(int* array) {
    int maximum = array[0];

    for (int i = 1; i < 10; i++) {
        if (array[i] >= maximum) {
            maximum = array[i];
        }
    }
    return maximum;
}

int* sortArray(int* highscore) {
    int temp;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (highscore[j] < highscore[j + 1]) {
                temp = highscore[j];
                highscore[j] = highscore[j + 1];
                highscore[j + 1] = temp;
            }
        }
    }
    return highscore;
}

int main() {

    int highscore[10];
    int score;

    while (true) {
        printf("Enter a score: ");
        scanf("%d", &score);

        if (score < 0) {
            printf("Please enter a non-negative number.\n");
            continue;
        }

        for (int i = 0; i < 10; i++) {
            if (i == 9 && highscore[9] != 0) {
                if (highscore[9] >= score) {
                    printf("\nERROR: All slots full.\n\n");
                } else {
                    highscore[9] = score;
                }
                break;
            } else if (highscore[i] == 0) {
                highscore[i] = score;
                break;
            }
        }
        int* sortedHighScore = sortArray(highscore);
        highscoreTable(sortedHighScore);
        printf("Minimum value: %d\n", minimumValue(highscore));
        printf("Maximum value: %d\n", maximumValue(highscore));
    }

    return 0;
}
