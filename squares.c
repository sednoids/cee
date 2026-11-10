#include <stdio.h>

int main() {
    int length = 0;

    printf("Enter length of square: ");
    scanf("%d", &length);

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if (j == length - 1) {
                printf("*\n");
            } else {
                printf("*");
            }
        }
        
    }

}
