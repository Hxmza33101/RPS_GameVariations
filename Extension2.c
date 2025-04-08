#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Change this to decide the number of gestures
int N_G = 7;
int ROUNDS = 3;

// Global array for gesture names
char *gestures[] = {"rock", "paper", "scissors", "fire", "water", "sponge", "air"};

// Function to determine the winner
int determine_winner(int player1, int player2) {
    int k = N_G / 2; // Number of gestures each beats

    if (player1 == player2) return 0; // Tie
    return ((player2 - player1 + N_G) % N_G <= k) ? 1 : -1;
}

void announce_final_winner(int score1, int score2, char *player1, char *player2) {
    printf("\nFinal Score: %s = %d | %s = %d\n", player1, score1, player2, score2);
    if (score1 > score2) {
        printf("%s Wins!\n", player1);
    } else if (score2 > score1) {
        printf("%s Wins!\n", player2);
    } else {
        printf("The game is a tie!\n");
    }
}

int get_Cgesture() {
    return rand() % N_G;
}

void human_computer() {
    int human, computer;
    int human_score = 0, computer_score = 0;

    while (1) {
        printf("Enter your gesture (0=rock, 1=paper, 2=scissors, 3=fire, 4=water, 5=sponge, 6=air or type -1 to exit): ");
        scanf("%d", &human);
        if (human == -1) break;

        computer = get_Cgesture();
        printf("You chose: %s vs Computer chose: %s\n", gestures[human], gestures[computer]);

        int result = determine_winner(human, computer);
        if (result == 1) {
            printf("You win this round!\n");
            human_score++;
        } else if (result == -1) {
            printf("Computer wins this round!\n");
            computer_score++;
        } else {
            printf("It's a tie!\n");
        }

        printf("Score: You = %d | Computer = %d\n", human_score, computer_score);
    }
}


void computer_computer() {
    int comp1_score = 0, comp2_score = 0;

    for (int i = 0; i < ROUNDS; i++) { // Example: 10 rounds
        int comp1 = get_Cgesture();
        int comp2 = get_Cgesture();
        
        printf("Computer 1 chose: %s vs Computer 2 chose: %s\n", gestures[comp1], gestures[comp2]);

        int result = determine_winner(comp1, comp2);
        if (result == 1) {
            printf("Computer 1 wins this round!\n");
            comp1_score++;
        } else if (result == -1) {
            printf("Computer 2 wins this round!\n");
            comp2_score++;
        } else {
            printf("It's a tie!\n");
        }

        printf("Score: Computer 1 = %d | Computer 2 = %d\n", comp1_score, comp2_score);
    }
}

void human_human() {
    int human1_score = 0, human2_score = 0;

    for (int i = 0; i < ROUNDS; i++) {
        int human1, human2;
        printf("Human 1: Enter your gesture (0=rock, 1=paper, 2=scissors, 3=fire, 4=water, 5=sponge, 6=air): ");
        scanf("%d", &human1);

        printf("Human 2: Enter your gesture (0=rock, 1=paper, 2=scissors, 3=fire, 4=water, 5=sponge, 6=air): ");
        scanf("%d", &human2);

        printf("%s vs %s\n", gestures[human1], gestures[human2]);

        int result = determine_winner(human1, human2);
        if (result == 1) {
            printf("Human 1 wins this round!\n");
            human1_score++;
        } else if (result == -1) {
            printf("Human 2 wins this round!\n");
            human2_score++;
        } else {
            printf("It's a tie!\n");
        }

        printf("Score Human 1 = %d | Human 2 = %d\n", human1_score, human2_score);
    }

    announce_final_winner(human1_score, human2_score, "Human 1", "Human 2");
}

int main() {
    srand(time(NULL));
    
    // human_computer();
    human_human();
    // computer_computer();
    
    return 0;
}
