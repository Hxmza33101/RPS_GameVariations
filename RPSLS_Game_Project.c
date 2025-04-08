#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gestNum = 5;
int numRounds = 7;

//Function that determines winner 

int determine_winner(int gesture_1, int gesture_2) {
    if (gesture_1 == 0) {
        if (gesture_2 == 1) return -1; // Paper beats Rock
        else if (gesture_2 == 2) return 1;  // Rock beats Scissors
        else if (gesture_2 == 3) return 1; // Rock beats Lizard
        else if (gesture_2 == 4) return -1;  // Spock beats Rock
        else if (gesture_2 == 0) return 0; // Tie
      }
      
      // Paper (1)
      else if (gesture_1 == 1) {
        if (gesture_2 == 0) return 1;  // Paper beats Rock
        else if (gesture_2 == 2) return -1; // Scissors beats Paper
        else if (gesture_2 == 3) return -1;  // Lizard beats Paper
        else if (gesture_2 == 4) return 1; // Paper beats Spock
        else if (gesture_2 == 1) return 0; // Tie
      }
      
      // Scissors (2)
      else if (gesture_1 == 2) {
        if (gesture_2 == 0) return -1; // Rock beats Scissors
        else if (gesture_2 == 1) return 1;  // Scissors beats Paper
        else if (gesture_2 == 3) return 1;  // Scissors beats Lizard
        else if (gesture_2 == 4) return -1; // Spock beats Scissors
        else if (gesture_2 == 2) return 0; // Tie
      }
      
      // Lizard (3)
      else if (gesture_1 == 3) {
        if (gesture_2 == 0) return 1;  // Rock beats Lizard
        else if (gesture_2 == 1) return -1; // Paper beats Lizard
        else if (gesture_2 == 2) return -1; // Scissors beats Lizard
        else if (gesture_2 == 4) return 1;  // Lizard beats Spock
        else if (gesture_2 == 3) return 0; // Tie
      }
      
      // Spock (4)
      else if (gesture_1 == 4) {
        if (gesture_2 == 0) return 1;  // Spock beats Rock
        else if (gesture_2 == 1) return -1;  // Paper beats Spock
        else if (gesture_2 == 2) return 1;  // Spock beats Scissors
        else if (gesture_2 == 3) return -1; // Lizard beats Spock
        else if (gesture_2 == 4) return 0; // Tie
      }

    return 0;
}

//Prints the winner
void show_winner(int winner) {
  if (winner == 1) printf("You win this round!\n");
  else if (winner == -1) printf("Computer wins this round!\n");
}

void hShow_winner(int Hwinner) {
    if (Hwinner == 1) printf("Player1 Wins!\n");
    else if (Hwinner == 0) printf("The game is a tie.\n");
    else if (Hwinner == -1) printf("Player2 Win s!\n");
}

void cShow_winner(int Cwinner) {
  if (Cwinner == 1) printf("Computer1 Wins!\n");
  else if (Cwinner == 0) printf("The game is a tie.\n");
  else if (Cwinner == -1) printf("Computer2 Wins!\n");
}

//Function that asks the user for inputs
int get_gesture() {
  int gesture;
  printf("Enter: \n0. for Rock \n1. Paper \n2. Scissors \n3. Lizard, \n4. Spock \nor type -1 to exit: ");
  if (scanf("%d", &gesture) != 1 || gesture < 0 || gesture >= gestNum) {
    return -1;
  }
  return gesture;
}

//Function that gets a random input, simulates computer choice, but is completely random
int get_Cgesture() { return rand() % gestNum;}

//Test case for all combinations of choices

// void test_determine_winner(int gesture2) {
//   printf("Testing all combinations for gesture2 = %d\n", gesture2);
//   printf("Rock vs gesture2: ");
//   int result = determine_winner(0, gesture2);
//   if ((gesture2 == 0 && result == 0) || (gesture2 == 1 && result == -1) || (gesture2 == 2 && result == 1))
//     printf("Passed\n");
//   else
//     printf("Failed\n");
//   printf("Paper vs gesture2: ");
//   result = determine_winner(1, gesture2);
//   if ((gesture2 == 0 && result == 1) || (gesture2 == 1 && result == 0) || (gesture2 == 2 && result == -1))
//     printf("Passed\n");
//   else
//     printf("Failed\n");
//   printf("Scissors vs gesture2: ");
//   result = determine_winner(2, gesture2);
//   if ((gesture2 == 0 && result == -1) || (gesture2 == 1 && result == 1) || (gesture2 == 2 && result == 0))
//     printf("Passed\n");
//   else
//     printf("Failed\n");
// }


char* get_gesture_name(int gesture) {
  switch (gesture) {
    case 0: return "0 (Rock)"; break;
    case 1: return "1 (Paper)"; break;
    case 2: return "2 (Scissors)"; break;
    case 3: return "3 (Lizard)"; break;
    case 4: return "4 (Spock)"; break;
    default: return "Invalid gesture"; break;
  }
}


void human_computer() {
  int human_score = 0, computer_score = 0;
  
  for (int i = 0; i <numRounds; i++) {
    int computer = get_Cgesture();
    int human = get_gesture();
    int result;
    char *output1 = get_gesture_name(computer);
    char *output2 = get_gesture_name(human);

    if (human == -1) {
      break;
    } else if (human < -1 || human > (gestNum-1)) {
      printf("Invalid Gesture\n");
      continue;
      i = i - 1;
    } else if (human == computer) {
      printf("\nRound %d:\n You chose: %s\n Computer chose: %s\n ", i + 1, output1, output2);
      printf("Its a Tie\n No Points awarded\n");
      i = i - 1;
    } else {
      printf("\nRound %d:\n You chose: %s\n Computer chose: %s\n ", i + 1, output1, output2);
      show_winner(determine_winner(human, computer));

      result = determine_winner(human, computer);
      if (result == 1) 
        human_score++;
      else if (result == -1)
        computer_score++;
    }

    
    printf("\n-Score: | You = %d | Computer = %d |-\n\n", human_score, computer_score);
  }
  printf("\n--- Final Score ---\nYou: %d | Computer: %d\n", human_score, computer_score);
if (human_score > computer_score) {
    printf("🙍 You won the game!🏆\n\n");
} else if (computer_score > human_score) {
    printf("💻 Computer won the game.🏆\n\n");
} else {
    printf("🤝 It's a draw!\n\n");
}
}

void computer_computer() {
  int comp1_score = 0, comp2_score = 0;

  for (int i = 0; i < numRounds; i++) {
    int computer1 = get_Cgesture();
    int computer2 = get_Cgesture();
    int result;

    char *output1 = get_gesture_name(computer1);
    char *output2 = get_gesture_name(computer2);

    if (computer1 == computer2) {
      printf("\nRound %d:\n Computer1 chose: %s\n Computer2 chose: %s\n ", i + 1, output1, output2);
      printf("Its a Tie\n No Points awarded\n");
      i = i - 1;
    } else {
      printf("\nRound %d:\n Computer1 chose: %s\n Computer2 chose: %s\n ", i + 1, output1, output2);
      cShow_winner(determine_winner(computer1, computer2));

      result = determine_winner(computer1, computer2);
      if (result == 1) 
        comp1_score++;
      else if (result == -1)
        comp2_score++;
    }
    printf("\n-Score: | Computer1 = %d | Computer2 = %d |-\n\n", comp1_score, comp2_score);
  }

  printf("\n--- Final Score ---\nYou: %d | Computer: %d\n", comp1_score, comp2_score);
  if (comp1_score > comp2_score) {
      printf("💻 Computer1 won the game!🏆\n\n");
  } else if (comp2_score > comp1_score) {
      printf("💻 Computer2 won the game.🏆\n\n");
  } else {
      printf("🤝 It's a draw!\n\n");
  }

}

void human_human() {
    int human1_score = 0, human2_score = 0;
    int result;
  
  for (int i = 0; i <numRounds; i++) {
        printf("Player One, ");
    int human1 = get_gesture();
    if (human1 == -1) {
      printf("🏳️ Player1 Forfeits!🏳️\n\n");
      break;
  }
        printf("\nPlayer Two, ");
    int human2 = get_gesture();
    if (human2 == -1) {
      printf("🏳️ Player2 Forfeits!🏳️\n\n");
      break;
    }
    if (human1 == -2) {
      break;
   }
      char *output1 = get_gesture_name(human1);
      char *output2 = get_gesture_name(human2);

    if (human1 < -1 || human1 > (gestNum-1)) {
        printf("Invalid Gesture\n");
        break;;
        i = i - 1;
    } else if (human2 < -1 || human2 > (gestNum-1)) {
        printf("Invalid Gesture\n");
        break;;
        i = i - 1;
    } else if (human1 == human2) {
        printf("\nRound %d:\n Player1 chose: %s\n Player2 chose: %s\n ", i + 1, output1, output2);
        printf("Its a Tie\n No Points awarded\n");
        i = i - 1;
    } else {
        printf("\nRound %d:\n Player1 chose: %s\n Player2 chose: %s\n ", i + 1, output1, output2);
        show_winner(determine_winner(human1, human2));

        result = determine_winner(human1, human2);
      if (result == 1) 
        human1_score++;
      else if (result == -1)
        human2_score++;
    }
    
    printf("\n-Score: | Player1 = %d | Player2 = %d |-\n\n", human1_score, human2_score);
  }
  printf("\n--- Final Score ---\nPlayer1: %d | Player2: %d\n", human1_score, human2_score);
if (human1_score > human2_score) {
    printf("🏆 Player1 won the game!🏆\n\n");
} else if (human2_score > human1_score) {
    printf("🏆 Player2 won the game.🏆\n\n");
} else {
    printf("🤝 It's a draw!\n\n");
} 
}

//The main code, runs the test code functions and has the functions for the game to run
int main() {
    
    srand(time(NULL)); 

//   printf("Testing when gesture2 is rock (0)\n");
//   test_determine_winner(0);
//   printf("\nTesting when gesture2 is paper (1)\n");
//   test_determine_winner(1);
//   printf("\nTesting when gesture2 is scissors (2)\n");
//   test_determine_winner(2);
//   srandom(time(NULL));

  // human_computer();
  // computer_computer();
  human_human();



  return 0;
}
