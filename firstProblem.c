#include <stdio.h>

int main() {
    float femurLength = 0.0;
    float tibiaLength = 0.0;


    scanf("%f", &femurLength);
    scanf("%f", &tibiaLength);

    float femurLengthLowerBound = (((2.38 * femurLength) + 61.41) - 3.27);
    float femurLengthUpperBound = (((2.38 * femurLength) + 61.41) + 3.27);

    float tibiaLengthLowerBound = (((2.52 * tibiaLength) + 78.2) - 3.37);
    float tibiaLengthUpperBound = (((2.52 * tibiaLength) + 78.2) + 3.37);



    printf("Femur length: %f\n", femurLength);
    printf("Femur length lower bound: %f\n", femurLengthLowerBound);
    printf("Femur length upper bound: %f\n", femurLengthUpperBound);
    printf("Tibia length: %f\n", tibiaLength);
    printf("Tibia length lower bound: %f\n", tibiaLengthLowerBound);
    printf("Tibia length upper bound: %f\n", tibiaLengthUpperBound);
}