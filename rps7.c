#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ROUNDS = 3;

//Function that determines winner 
int determine_winner(int gesture_1, int gesture_2) {
    if (gesture_1 == 0) {  // Rock
        if (gesture_2 == 1) return -1;  // Paper covers Rock
        else if (gesture_2 == 2) return 1;  // Rock crushes Scissors
        else if (gesture_2 == 3) return 1;  // Rock pounds Fire
        else if (gesture_2 == 4) return -1;  // Rock gets eroded by Water
        else if (gesture_2 == 5) return 1;  // Rock erodes Sponge
        else if (gesture_2 == 6) return -1;  // Rock gets eroded by Air
        else if (gesture_2 == 0) return 0;  // Rock vs Rock (tie)
    } 
    else if (gesture_1 == 1) {  // Paper
        if (gesture_2 == 0) return 1;  // Paper covers Rock
        else if (gesture_2 == 2) return -1;  // Scissors cut Paper
        else if (gesture_2 == 3) return -1;  // Paper gets burnt by Fire
        else if (gesture_2 == 4) return 1;  // Paper absorbs Water
        else if (gesture_2 == 5) return -1;  // Paper gets soaked by Sponge
        else if (gesture_2 == 6) return 1; // Paper fans Air
        else if (gesture_2 == 1) return 0;  // Paper vs Paper (tie)
    } 
    else if (gesture_1 == 2) {  // Scissors
        if (gesture_2 == 0) return -1;  // Rock crushes Scissors
        else if (gesture_2 == 1) return 1;  // Scissors cut Paper
        else if (gesture_2 == 3) return -1;  // Scissors gets melted by Fire
        else if (gesture_2 == 4) return -1;  // Scissors rust in Water
        else if (gesture_2 == 5) return 1;  // Scissors slice Sponge
        else if (gesture_2 == 6) return 1; // Scissors swish through Air
        else if (gesture_2 == 2) return 0;  // Scissors vs Scissors (tie)
    }
    else if (gesture_1 == 3) {  // Fire
        if (gesture_2 == 0) return -1;  // Rock pounds Fire
        else if (gesture_2 == 1) return 1;  // Fire burns Paper
        else if (gesture_2 == 2) return 1;  // Fire melts Scissors
        else if (gesture_2 == 4) return -1;  // Water puts our Fire
        else if (gesture_2 == 5) return 1;  // Fire burns Sponge
        else if (gesture_2 == 6) return -1;  // Air blows out Fire
        else if (gesture_2 == 3) return 0;  // Fire vs Fire (tie)
    } 
    else if (gesture_1 == 4) {  // Water
        if (gesture_2 == 0) return 1;  // Water erodes Rock
        else if (gesture_2 == 1) return -1;  // Paper floats on Water
        else if (gesture_2 == 2) return 1;  // Water rusts Scissors
        else if (gesture_2 == 3) return 1;  // Fire evaporates Water
        else if (gesture_2 == 5) return -1;  // Water gets soaked up by Sponge
        else if (gesture_2 == 6) return -1; // Water gets evaporated by Air
        else if (gesture_2 == 4) return 0;  // Water vs Water (tie)
    } 
    else if (gesture_1 == 5) {  // Sponge
        if (gesture_2 == 0) return -1;  // Rock erodes Sponge
        else if (gesture_2 == 1) return 1;  // Paper absorbs Sponge
        else if (gesture_2 == 2) return -1;  // Scissors slice Sponge
        else if (gesture_2 == 3) return -1;  // Sponge absorbs Fire
        else if (gesture_2 == 4) return 1;  // Sponge soaks Water
        else if (gesture_2 == 6) return 1; // Sponge uses Air Pockets
        else if (gesture_2 == 5) return 0;  // Sponge vs Sponge (tie)
    } 
    else if (gesture_1 == 6) {  // Air
        if (gesture_2 == 0) return 1;  // Air erodes Rock
        else if (gesture_2 == 1) return -1;  // Air blows Paper
        else if (gesture_2 == 2) return -1;  // Scissors swish through Air
        else if (gesture_2 == 3) return 1;  // Air blows out Fire
        else if (gesture_2 == 4) return 1;  // Air evaporates Water
        else if (gesture_2 == 5) return -1;  // Sponge uses Air Pockets
        else if (gesture_2 == 6) return 0;  // Air vs Air (tie)
    }

    return 0;  // If it's a tie
}

//Prints the winner
void show_winner(int winner) {
  if (winner == 1)
    printf("You win!\n");
  else if (winner == 0)
    printf("The game is a tie.\n");
  else if (winner == -1)
    printf("Computer wins!\n");
}

void hShow_winner(int Hwinner) {
    if (Hwinner == 1)
      printf("Player1 Wins!\n");
    else if (Hwinner == 0)
      printf("The game is a tie.\n");
    else if (Hwinner == -1)
      printf("Player2 Wins!\n");
}

//Function that asks the user for inputs
int get_gesture() {
  int gesture;
  printf("Enter 0 for Rock, 1 for Paper, 2 for Scissors, 3 for Fire, 4 for Water, 5 for Sponge, 6 for Air: ");
  scanf("%d", &gesture);
  return gesture;
}

//Function that gets a random input, simulates computer choice, but is completely random
int get_Cgesture() {
  return rand() % 7;
}

char* get_gesture_name(int gesture) {
  switch (gesture) {
    case 0: return "0 (Rock)"; break;
    case 1: return "1 (Paper)"; break;
    case 2: return "2 (Scissors)"; break;
    case 3: return "3 (Fire)"; break;
    case 4: return "4 (Water)"; break;
    case 5: return "5 (Sponge)"; break;
    case 6: return "6 (Air)"; break;
    default: return "Invalid gesture"; break;
  }
}


void human_computer() {
  for (int i = 0; i < ROUNDS; i++) {
    int computer = get_Cgesture();
    int human = get_gesture();

    if (human == -1) {
      printf("Invalid Gesture\n");
      continue;
    }

    char *output1 = get_gesture_name(computer);
    char *output2 = get_gesture_name(human);

    printf("Round %d:\n Computer chose: %s\n You chose: %s\n", i + 1, output1, output2);
    show_winner(determine_winner(computer, human));
    printf("\n");
  }
}

void computer_computer() {
  for (int i = 0; i < ROUNDS; i++) {
    int computer1 = get_Cgesture();
    int computer2 = get_Cgesture();

    char *output1 = get_gesture_name(computer1);
    char *output2 = get_gesture_name(computer2);

    printf("Round %d:\n Computer 1 chose: %s\n Computer 2 chose: %s\n", i + 1, output1, output2);
    show_winner(determine_winner(computer1, computer2));
    printf("\n");
  }
}

void human_human() {
  for (int i = 0; i < ROUNDS; i++) {
    printf("Round %d:\nPlayer 1's turn:\n", i + 1);
    int human1 = get_gesture();
    if (human1 == -1) {
      printf("Invalid Gesture\n");
      continue;
    }

    printf("Player 2's turn:\n");
    int human2 = get_gesture();
    if (human2 == -1) {
      printf("Invalid Gesture\n");
      continue;
    }

    char *output1 = get_gesture_name(human1);
    char *output2 = get_gesture_name(human2);

    printf(" Player 1 chose: %s\n Player 2 chose: %s\n", output1, output2);
    hShow_winner(determine_winner(human1, human2));
    printf("\n");
  }
}

//The main code, runs the test code functions and has the functions for the game to run
int main() {
    
    srand(time(NULL)); 

human_computer();
// computer_computer();
// human_human();



  return 0;
}
