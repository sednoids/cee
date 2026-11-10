#include <stdio.h>

int factorial(int n) {
    if (n < 2) {
        return 1;
    }

    return n * factorial(n-1);
}

int main() {
    int rows = 0;

    printf("Enter how many rows you want: ");
    scanf("%d", &rows);

    int res = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < i + 1; j++) {
            res = factorial(i)/(factorial(j) * factorial(i - j));
            if ((j == i && i != rows - 1) || (j == i && i == rows - 1)) {
                printf("%d\n ", res);
            } else {
                printf("%d ", res);
            }

        }
    }
}