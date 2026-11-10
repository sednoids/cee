#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define true 1

char getUserChoice(int optionNumber) {

    switch (optionNumber) {
        case 1:
            return 'r';
        case 2: 
            return 'p';
        case 3:
            return 's';
    }
}

char getComputerChoice() {

    srand(time(NULL)); // seeding, we want to get random values

    int computerChoice = rand() % 3 + 1;

    switch (computerChoice) {
        case 1:
            return 'r';
        case 2:
            return 'p';
        case 3:
            return 's';
    }
}

char getState(int userOption) {

    char userChoice = getUserChoice(userOption);
    char computerChoice = getComputerChoice();

    if (userChoice == computerChoice) return 'D';
    
    if (userChoice == 'r' && computerChoice == 's') return 'U';
    if (userChoice == 'p' && computerChoice == 'r') return 'U';
    if (userChoice == 's' && computerChoice == 'p') return 'U';

    if (userChoice == 'r' && computerChoice == 'p') return 'C';
    if (userChoice == 'p' && computerChoice == 's') return 'C';
    if (userChoice == 's' && computerChoice == 'r') return 'C';
}

void finalMessage(int userChoice) {

    char state = getState(userChoice);

    switch (state) {
        case 'U':
            printf("User wins!\n");
            break;
        case 'C':
            printf("Computer wins!\n");
            break;   
        case 'D':
            printf("A draw!\n");
            break;
    }
}

int main() {

    int userChoice;
    printf("Enter (1) for rock, (2) for paper, and (3) for scissors: ");
    scanf("%d", &userChoice);

    char user = getUserChoice(userChoice);
    char computer = getComputerChoice();

    printf("User chooses: %c\nComputer chooses: %c\n\n", user, computer);
    finalMessage(userChoice);
}