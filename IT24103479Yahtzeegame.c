#include <stdio.h> //for predifined functions(printf,scanf)
#include <stdlib.h>//for random number generation
#include <time.h>  //Includes time functions, used for seeding random number generation
#include <string.h>// Reset the 'kept' and 'counts' arrays to zero using memset for the next player



void instructions();
// Function: instructions
// Purpose: Displays the rules and scoring instructions for the Yahtzee game.
// Parameters: None
// Returns: void (outputs the game rules and scoring instructions)


void fourthreekind(int dice[]);
// Function: fourthreekind
// Purpose: Calculates and displays the score for the "Three of a Kind" and "Four of a Kind" categories.
// Parameters:
//   - dice[]: Array representing the current dice rolls.
// Returns: void (displays the score in the scoreboard).


void countDice(int dice[], int kept[]);
// Function: countDice
// Purpose: Counts the occurrences of each dice value (1-6) and sums them up to display the score.
// Parameters:
//   - dice[]: Array representing the current dice rolls (5 dice).
//   - kept[]: Array representing the dice that the player has chosen to keep.
// Returns: void (displays the summed scores in the scoreboard).


void chance(int dice[]);
// Function: chance
// Purpose: Calculates and displays the score for the "Chance" category, which is the sum of all dice values.
// Parameters:
//   - dice[]: Array representing the current dice rolls (5 dice).
// Returns: void (displays the score for the Chance category in the scoreboard).



void fullhouse(int dice[]);
// Function: fullhouse
// Purpose: Calculates and displays the score for the "Full House" category.
// A "Full House" consists of a three-of-a-kind and a pair (e.g., 3, 3, 3, 5, 5).
// Parameters:
//   - dice[]: Array representing the current dice rolls (5 dice).
// Returns: void (displays the score for the Full House category in the scoreboard).


void largestraight(int dice[]);
// Function: largestraight
// Purpose: Calculate and displays the score for the "Large Straight" category (40 points if a valid sequence, 0 otherwise)
// Parameters:
//   - dice[]: Array representing the current dice rolls (5 dice).
// Returns: The score for the "Large Straight" category (either 40 or 0).



void smallstraight(int dice[]);
// Function: smallstraight
// Purpose: Calculates and displays the score for the "Small Straight" category.
// A "Small Straight" consists of four consecutive dice values (e.g., 1-2-3-4, 2-3-4-5, or 3-4-5-6).
// Parameters:
//   - dice[]: Array representing the current dice rolls (5 dice).
// Returns: void (displays the score for the Small Straight category).


void yahtzee(int dice[]);
// Function: yahtzee
// Purpose: Calculates and displays the score for the "Yahtzee" category.
// A "Yahtzee" occurs when all five dice have the same value.
// Parameters:
//   - dice[]: Array representing the current dice rolls (5 dice).
// Returns: void (displays the score for the Yahtzee category)


void dicerolls(int dice[],int kept[]);
// Function: dicerolls
// Purpose: Rolls the dice that haven't been "kept" by the player.
// Parameters:
//   - dice[]: Array representing the dice rolls (5 dice).
// Returns: void (updates the dice[] array with new values for the dice that were not kept).


void printdices(int dice[],int kept[]);
// Function: printdices
// Purpose: Displays the values of the dice rolls, excluding any dice that are "kept".
// Parameters:
//    - int dice[]: Array containing the values of the current dice roll (size 5).
//- int kept[]: Array that will store dice values that are kept for the next roll.
// Returns: void (outputs the dice values to the console).


int keepDice(int dice[], int kept[],int turn);
// Function: keepDice
// Purpose: Selects specific dice to keep for rerolls based on the current turn and updates the `kept` array.
// Parameters:
//    - int dice[]: Array containing the values of the current dice roll (size 5).
//    - int kept[]: Array that will store dice values that are kept for the next roll.
//    - int turns1: The current turn number, used to decide which dice should be kept.
// Returns: An integer indicating whether any dice were kept (1 if yes, 0 if no).


void scoreboard(int dice[],int kept[]);
// Function: scoreboard
// Purpose: Calculate and display scores for all categories in Yahtzee by calling appropriate functions.
// Parameters:
//   - dice[]: Array representing the current dice rolls (5 dice).
//   - kept[]: Array representing the dice that the player has chosen to keep (1 = kept, 0 = not kept).
// Returns: None (just displays the scores).

int scoreCategory(int dice[], int category);
// Function: scoreCategory
// Purpose: Calculates and returns the score for a specific category based on the dice values.
// Parameters:
//    - int dice[]: Array containing the values of the dice rolled (size 5).
//    - int category: The specific category for which to calculate the score.
// Returns: An integer representing the score for the specified category.


void findingwinner(int player1total, int player2total);
// Function: findingwinner
// Purpose: Determines and prints the winner of the game based on the total scores of both players.
// Parameters:
//    - int player1total: The total score of human.
//    - int player2total: The total score of computer.
// Returns: Nothing (void) - This function only outputs the result.



int computerKeepDice(int dice[], int kept[], int category, int categoriesUsed2[]);
// Function: computerKeepDice
// Purpose: Determines which dice the computer player should keep based on its strategy and the
//          current dice roll, category, and scored categories.
// Parameters:
//    - int dice[]: Array of rolled dice values (5 elements).
//    - int kept[]: Array where kept dice values will be stored (5 elements).
//    - int category: The current scoring category being targeted by the computer.
//    - int categoriesUsed2[]: Array indicating which scoring categories have already been used (13 elements).
// Returns: An integer flag (1 if any dice were kept, 0 otherwise).



int getBestCategory(int dice[], int categoriesUsed2[], int computerturn, int category);
// Function: getBestCategory
// Purpose: Determines the best scoring category for the computer player based on the current dice roll,
//          categories that have already been scored, and the turn number.
// Parameters:
//    - int dice[]: Array holding the values of the rolled dice (5 elements).
//    - int categoriesUsed2[]: Array indicating which categories have already been scored.
//    - int turn: The current turn number, used to prioritize high-value categories initially.
//    - int category: The current category being considered.
// Returns: The integer representing the best scoring category for the current turn.

void finalscoreboard(int scores1[],int scores2[],int player1total,int computerTotal);
// Function to display the final scoreboard
// Parameters:
// - scores1[]: Array holding individual category scores for human
// - scores2[]: Array holding individual category scores for the computer
// - player1total: Total score of human
// - computerTotal: Total score of the computer


int main() {
   // Declared and initialized variables for the Yahtzee game

int dice[5]; // Array to store the values of the dice rolled (5 dice in total)
int scores1[13] = {0};//Array to store computer scores for each of the 13 categories (used for calculating total scores)
int scores2[13] = {0}; // Array to store computer scores for each of the 13 categories (used for calculating total scores)
int categoriesUsed1[13] = {0}; // Array to track which categories have been chosen by the human player
int categoriesUsed2[13] = {0}; // Array to track which categories have been chosen by the computer
int category; // Variable to store the current category being scored
int player1total = 0, computerTotal = 0; // Total scores for the human player and the computer
int kept[5] = {0}; // Array to store dice that have been kept by the player or computer
int counts[7] = {0}; // Array to count occurrences of each die value (1-6)
int sum[7] = {0}; // Array to store the sum of each unique die value (1-6)
int ckeepDiceStatus = 0; // Flag to track if the computer keeps any dice (1 if kept, 0 otherwise)
int keepDiceStatus = 0; // Flag to track if the human player keeps any dice (1 if kept, 0 otherwise)
int chosenCategories[13] = {0}; // Array to store categories that have already been chosen by the human player
int chosenCount = 0; // Counter for how many categories the human player has chosen
int chosenCategories2[13] = {0}; // Array to store categories that have already been chosen by the computer
int chosenCount2 = 0; // Counter for how many categories the computer has chosen

// Initialize random seed for different dice rolls each time
srand(time(NULL)); // Seed the random number generator to ensure different dice rolls each time
     
    //display instructions of the game
    instructions();


/*-----Start the rounds (13 rounds total in Yahtzee)-------*/
for(int round=0;round<13;round++) {
    
// Display the round number  
    printf("\n");
    printf("--------round %d--------\n",round+1);
    printf("\n");// Space for separation
   
   
// human's turn (human player)
      memset(kept, 0, sizeof(kept));// Reset the kept dice array for human 
      memset(counts, 0, sizeof(counts)); // Reset counts array for human 
  


  /*----------Start human's turn----------*/
    for (int humanturn = 0; humanturn < 3; humanturn++) {
       
       
        
        printf("\n");

        printf("human\n");
        printf("\n");//for space
        printf("turn %d\n",humanturn+1);
        printf("\n");

        // Print the categories the player has already chosen
   if (chosenCount > 0) { //checking if a chategory has choosen,if has choosen those categories display
       
        printf("choosed categories: ");
       
        for (int i = 0; i < chosenCount; i++) {  
            printf("%d ", chosenCategories[i]);
        }
        printf("\n");
    }

   // Print the kept dice if any
    if(keepDiceStatus||humanturn==2) { //if dice has kept or when its 3rd turn kept dice display
     printf("Kept dice: ");//printing kept dices
    
    for (int i = 0; i < 5; i++) {
        if (kept[i]) { //in dice[] array there are both kept and not kept dice in it.in here kept dice are checked
            printf("%d ", dice[i]);
        }
    }
    }
    printf("\n");

        // Roll dice and print the result
        dicerolls(dice,kept);
        printdices(dice,kept); 
        
       // Print the scoreboard and update scores
       printf("\n");
       scoreboard(dice,kept);
         
      // Let the player choose which dice to keep
        keepDiceStatus = keepDice(dice, kept,humanturn);//keepdices status 
    
        
     // Print the kept dice after the player chooses(to make sure if the dice player wan to keep are kept)
        printf("Kept dice: ");
    
    for (int i = 0; i < 5; i++) {
        if (kept[i]) {
            printf("%d ", dice[i]);
        }
      }  
      printf("\n");
    
    


    // If the player hasn't chosen a category yet
      if(!keepDiceStatus) { //if not keeping a dice player might want to choose a category rightaway

     // Let the player select a category (1-13)
                                
        while (1) {
         
        
        printf("Select category (1-13) or 0 to move on to the next turn: ");//input
        scanf("%d", &category);//input

      // Validate the category selection 
        if (category > 13 || categoriesUsed1[category - 1]) { //player cant choose category once selected
            if(category!=0) { //'0' the input that beign used to skip selecting category to next turn(player cant move to the next round without choosing a category)
          printf("Invalid category, please choose again.\n"); }
         } else {
         break; // Valid category
         }
         
       if(category==0){ //if the input is zero move on to next turn or next round
           break;
       }
        }   
        if(category>0) { //category is selected move on to the next round
            break;
        }
            
        }
    } 
    // Add the selected category to the chosen categories(for printing category already has choosen)
    if (category > 0 && category <= 13 && !categoriesUsed1[category - 1]) {
        // Add chosen category to the array
        chosenCategories[chosenCount++] = category;//choosen count updated every time player chooses a category
    }
       
      // Print the score for the selected category and the total score
        scores1[category - 1] = scoreCategory(dice, category);//calling scorecategory to store scores for each round in the scores[] array(an input from the player taken for category)
        
        categoriesUsed1[category - 1] = 1; //marking category choosing so the player cant selet it in the next round
        player1total += scores1[category - 1]; //calculating total of human player(updates each round up to scores player has scored)
        
        printf("selected score:%d\n",scores1[category - 1]);//selected score
        printf("total score:%d",player1total);//total for each round


 // Reset kept dice and counts for the next player's turn (computer)  
 memset(kept, 0, sizeof(kept)); 
 memset(counts, 0, sizeof(counts));
 printf("\n");//for the space between player 1 dn computer
 printf("\n");//for space

 
   
   /*------------computer's turn----------*/

   for (int computerturn= 0; computerturn< 3; computerturn++) {
         
            printf("\n");
            printf("Computer's Turn\n");
            printf("\n");//for space
            printf("turn %d\n",computerturn+1);
            
           // Print the kept dice if any
             if(ckeepDiceStatus) {
                
                printf("Kept dice: ");
               for (int i = 0; i < 5; i++) {
                       if (kept[i]) {
                       printf("%d ", dice[i]);
                            }
                       }
                }
              printf("\n");   

           // Roll dice and print the result
            dicerolls(dice, kept);
            printdices(dice, kept);
            
            // Print the scoreboard for the computer
            printf("\n");
            scoreboard(dice, kept);

            // computer must choose a category in the third turn
            if(computerturn<2 ) {
            ckeepDiceStatus = computerKeepDice(dice,kept,category,categoriesUsed2);//computer keepdice status
            
            printf("Computer keeps the following dice: "); //displaying kept dices
                for (int j = 0; j < 5; j++) {
                    if (kept[j]) {
                        printf("%d ", dice[j]);
                    }
                }
                printf("\n");
               
            }  
             
    // Select a category for the computer if it's the final turn 
    int category=-1; 
   if (!ckeepDiceStatus) {
        category = getBestCategory(dice, categoriesUsed2,computerturn,category);
        printf("Computer selects category: %d\n", category);
  } 
 // If the computer hasn't chosen a category after 2 turns, pick one
  if(computerturn==2&&category==-1) { //computer must choose a category when its third turn
    category = getBestCategory(dice, categoriesUsed2,computerturn,category);
      printf("Computer selects category: %d\n", category);//printed selected category


      }
  

   

   // If a valid category was selected, calculate and update the score
    if (category > 0 && category <= 13) {

   // Add the category to the chosen categories
   chosenCategories2[chosenCount2++] = category;//chosen count updated each round when ategory is choosen

       // Print all categories chosen by the computer
        printf("Chosen categories: ");
        for (int i = 0; i < chosenCount2; i++) {
            printf("%d ", chosenCategories2[i]);//printing choosed category
        }
          printf("\n");



   // If the category is valid and hasn't been used before, score it
   if (!categoriesUsed2[category - 1]) {
        scores2[category - 1] = scoreCategory(dice, category); 
        categoriesUsed2[category - 1] = 1; // Mark category used
        computerTotal += scores2[category - 1];
        printf("Selected score: %d\n", scores2[category - 1]);
        printf("Total score: %d\n", computerTotal);
        break;// Exit the loop after scoring
    }
        
    }
}


    
 }     
        printf("\n");
        printf("\n");

        finalscoreboard(scores1,scores2,player1total,computerTotal);//displaying final score board

        printf("\n");
        printf("\n");
// After both players have completed their turns, determine and display the winner
    findingwinner(player1total,computerTotal);



return 0; // End of the main function
}






// Function to display the rules and scoring instructions of the game.
void instructions() {
    printf("\n");
    printf("\n");
    printf("1.Ones: Sum of all dice showing the number 1.\n"); // Category for Ones
    printf("2.Twos: Sum of all dice showing the number 2.\n"); // Category for twos
    printf("3.Threes: Sum of all dice showing the number 3.\n");//Category for threes
    printf("4.Fours: Sum of all dice showing the number 4.\n"); // Category for fours
    printf("5.Fives: Sum of all dice showing the number 5.\n"); // Category for fives
    printf("6.Sixes: Sum of all dice showing the number 6.\n"); // Category for sixes
    // Scoring based on dice combinations
    printf("7.Three of a Kind: Sum of all dice if at least three dice show the same number.\n");// 3 of a kind
    printf("8.Four of a Kind: Sum of all dice if at least four dice show the same number.\n");// 4 of a kind
    printf("9.Full House: 25 points if three of one number and two of another number.\n");// Full House

    printf("10.Small Straight: 30 points for four consecutive numbers (e.g., 1-2-3-4 or 2-3-4-5).\n");// Small Straight
    printf("11.Large Straight: 40 points for five consecutive numbers (e.g., 1-2-3-4-5 or 2-3-4-5-6).\n");//large straight
    printf("12.Yahtzee: 50 points for five of a kind.\n");//yahtzee
    printf("13.Chance: Sum of all dice (can be used for any combination).\n");//chance
    
    printf("\n");
    printf("\n");
    printf("\n");
}







//function to calculate and display scores for three of a kind and four of function in the scoreboard
void fourthreekind(int dice[]) {
    int counts[7] = {0}; //intializing count array to track occurences of each dice values
    int totalSum = 0;//initializing totalsum of dice values
    

    //counting the the occurence of each dice values and calculate total sum of all dice
    for (int dicenumber = 0; dicenumber< 5; dicenumber++) { 
     counts[dice[dicenumber]]++;
     totalSum += dice[dicenumber];
    }
    int fourOfAKindValue = 0; // Variable to store the score for Four of a Kind (0 if not applicable)
    int threeOfAKindValue = 0; // Variable to store the score for three of a Kind (0 if not applicable)

    // Check for Four of a Kind by finding any value that appears exactly 4 times
    for (int dicenumber = 1; dicenumber <= 6; dicenumber++) {
      if (counts[dicenumber]>= 4) { // If a value occurs four times, set Four of a Kind score
        fourOfAKindValue=totalSum; // Four of a Kind score is the sum of all dice
        break;
        }
    }

     // Check for Three of a Kind by finding any value that appears exactly 3 times
    for (int dicenumber = 1; dicenumber <= 6; dicenumber++) { 
        if (counts[dicenumber] >= 3) {// If a value occurs three times, set Three of a Kind score
          threeOfAKindValue=totalSum; // Three of a Kind score is the sum of all dice
          break;
        }
    } 
      // Display the scores for Four of a Kind and Three of a Kind
    printf("7. Four of a Kind   | %d\n", fourOfAKindValue > 0 ? fourOfAKindValue : 0);// Show Four of a Kind score or 0
    printf("8. Three of a Kind  | %d\n", threeOfAKindValue > 0 ? threeOfAKindValue : 0);// Show three of a Kind score or 0
}







//function to count and sum of occurence each dice values to display on the scoreboard
void countDice(int dice[], int kept[]) {
    int counts[7] = {0};   // Array to count occurrences of each die value (1-6)
    int sum[7] = {0}; // Array to store the sum of each unique die value (1-6)

      // Count occurrences and sum values in the dice[] array
    for (int dicenumber = 0; dicenumber < 5; dicenumber++) {
        if (dice[dicenumber] >= 1 && dice[dicenumber] <= 6) { 
            counts[dice[dicenumber]]++;      // Increment count for the die value                   
            sum[dice[dicenumber]] += dice[dicenumber];  // Add die value to corresponding sum
        }
    }

     // Include values in the kept[] array if not already counted in counts
    for (int keptdice = 0; keptdice < 5; keptdice++) {
        if (kept[keptdice] > 0 && counts[kept[keptdice]] == 0) {  // Check if not already counted
            counts[kept[keptdice]]++;
            sum[kept[keptdice]] += kept[keptdice];  // Add the kept value to its sum
        }           
        }
    

    // Display the results for each die value (1-6)
    for (int i = 1; i <= 6; i++) {
    printf("%d.  %d's             | %d\n",i, i, sum[i]); // Show sum of values for 1s, 2s, etc.
    }
}






// Function to calculate the score for the "Chance" category
void chance(int dice[]) {
    int total = 0;// Initialize the total score

    // Sum up all values in the dice[] array
    for (int dicenumber = 0; dicenumber< 5; dicenumber++) {
        total += dice[dicenumber]; // Add each die's value to the total
    
    }
    // Display the result for the Chance category
    printf("13. Chance          | %d\n", total); // Print the sum of all dice values
}






// Function to calculate the score for the "Full House" category in the scoreboard
void fullhouse(int dice[]) {
    int counts[7] = {0}; // Array to count occurrences of each dice value (1-6)
    int hasThree = 0, hasTwo = 0;// Flags to mark if there are three of a kind and two of a kind
    int total=0;
 
  // Count occurrences of each dice value in the dice array
    for (int dicenumber = 0; dicenumber < 5; dicenumber++) {
        counts[dice[dicenumber]]++;  // Increment the count for each dice value
    }

    
  // Check for a three of a kind and a pair
    for (int dicenumber = 1; dicenumber <= 6; dicenumber++) {
        if (counts[dicenumber] == 3) hasThree = 1;// Mark if there's a three of a kind
        if (counts[dicenumber] == 2) hasTwo = 1; // Mark if there's a pair
    }
  // Print the result for Full House category: 25 points if both conditions are met, otherwise 0
    printf("9. Full House       | %d\n", (hasThree && hasTwo) ? 25 : 0); 
}







// Function to calculate the score for the "Large Straight" category in the scoreboard
void largestraight(int dice[]) {
    int counts[7] = {0}; // Array to count occurrences of each dice value (1-6)

// Count occurrences of each dice value in the dice array
  for (int dicenumber = 0; dicenumber < 5; dicenumber++) {
        counts[dice[dicenumber]]++; // Increment count for each rolled dice value
     
}
// Check if there is a Large Straight combination (1-2-3-4-5 or 2-3-4-5-6)
    int hasLargeStraight = (counts[1] && counts[2] && counts[3] && counts[4] && counts[5]) ||
                           (counts[2] && counts[3] && counts[4] && counts[5] && counts[6]); //checks of there largstraight combinations
// Print the result for Large Straight category: 40 points if a large straight is found, otherwise 0
    printf("11. Large Straight  | %d\n", hasLargeStraight ? 40 : 0);
}






// Function to calculate the score for the "Small Straight" category in the scoreboard
void smallstraight(int dice[]) {
    int counts[7] = {0}; // Array to count occurrences of each dice value (1-6)
   
   // Count occurrences of each dice value in the dice array
   for (int dicenumber = 0; dicenumber < 5; dicenumber++) {
        counts[dice[dicenumber]]++; // Increment count for each rolled dice value
    
}
    // Check for Small Straight combinations:
    // - 1-2-3-4
    // - 2-3-4-5
    // - 3-4-5-6
    int hasSmallStraight = (counts[1] && counts[2] && counts[3] && counts[4]) ||
                           (counts[2] && counts[3] && counts[4] && counts[5]) ||
                           (counts[3] && counts[4] && counts[5] && counts[6]);//checks if there small straight combinations

   

   // Print the result for Small Straight category:
    // 30 points if a small straight is found, otherwise 0
    if(hasSmallStraight) {
    printf("10. Small Straight  | %d\n", 30 ); // Small Straight found, print 30 points
    } else {
      printf("10. Small Straight  | %d\n", 0);// No Small Straight, print 0 points
    }
}






// Function to calculate the score for the "Yahtzee" category in the scoreboard
void yahtzee(int dice[]) {
    int counts[7] = {0};// Array to count occurrences of each dice value (1-6)

// Count occurrences of each dice value in the dice array
    for (int dicenumber = 0; dicenumber < 5; dicenumber++) {
        counts[dice[dicenumber]]++;  // Increment count for the rolled dice value
    }

// Check for Yahtzee: if any value appears exactly 5 times, score 50 points
    for (int dicenumber = 1; dicenumber <= 6; dicenumber++) {
        if (counts[dicenumber] == 5) {  // If a value occurs 5 times, a Yahtzee is achieved
            printf("12. Yahtzee         | 50\n");  // Print 50 points for Yahtzee
            return; // Exit function as the Yahtzee score has been set
        }
    }
    // Print result if no Yahtzee is achieved
    printf("12. Yahtzee         | 0\n");// If no Yahtzee, print 0 points for the category

}






// Function to roll dice that haven't been "kept" by the player
void dicerolls(int dice[],int kept[]) {
    int counts[7] = {0};  // Array to keep track of dice value occurrences (optional in this context)       
    int sum[7] = {0};  // Array to sum dice values by number (optional in this context)

  // Loop through each die
    for(int dicenumber=0; dicenumber <5; dicenumber ++) {
        // Only roll dice that are not "kept" (where kept[dicenumber] is 0)
        if(!kept[dicenumber]) {
            dice[dicenumber]=rand()%6+1;// Generate random number between 1 and 6 for the die
        }
    }
}




// Function to print dice rolls, excluding dice that are "kept"
void printdices(int dice[],int kept[]) {

    printf("dice rolls:");// Print label for the dice roll results
      
      // Loop through each die
      for(int dicenumber=0; dicenumber <5; dicenumber++)  {
         // Only print dice that are not "kept" (where kept[dicenumber] is 0)
           if(!kept[dicenumber]) { 
            printf("%d ",dice[dicenumber]);// Print the value of each unkept die
        }
    }
}




// Function to keep specified dice for rerolls
int keepDice(int dice[], int kept[],int humanturn) {
    int input, numberToKeep;  // 'input' is the die value to keep, 'numberToKeep' is the count of dice to keep for that value
    int keepDiceFlag = 0; // Flag to indicate if any dice were kept

// Skip keeping dice if it’s the third turn (no option to keep)
     if (humanturn == 2) {
        return keepDiceFlag; // Return immediately if it's the final turn
    }
   
    while (1) {
 // Prompt player to enter the value of dice to keep
        printf("Enter the number you want to keep (1-6) or type 0 to move on to choosing categories:"); //input the numper of the dice tht want to be kept
        scanf("%d", &input);  // 0 is to exit keeping dices
        


// Exit keeping phase if player inputs 0
        if (input == 0) {
            break;      // Exit if the player does not want to keep dices

       } else if (input >= 1 && input <= 6 ) {  // Valid dice values are from 1 to 6
            
            printf("How many %d's do you want to keep? ", input);
            scanf("%d", &numberToKeep);

            for (int j = 0; j < 5 && numberToKeep > 0; j++) {
                
                if (dice[j] == input && kept[j] == 0) {  // Keep only if not already kept
                    
                    kept[j] = dice[j]; // Store actual die value in kept[]
                    numberToKeep--;   // Decrease count of dice to keep
                   keepDiceFlag = 1;  // Set flag to indicate dice have been kept
                } 
            }
        } else {
            printf("Invalid input! Please enter a number from 1 to 6 or 0 to move on.\n"); //if player input a invalid number
        }
        
    }
        return keepDiceFlag;   // Return flag to indicate whether dice were kept

}




// Function to display the scoreboard by calculating and printing scores for each category
void scoreboard(int dice[],int kept[]) {
        // Calling category functions to calculate and display scores:
      countDice(dice,kept);   // Score for Ones, Twos, Threes, Fours, Fives, Sixes
      fourthreekind(dice); // Scores for Three of a Kind and Four of a Kind
      fullhouse(dice); // Score for Full House
      smallstraight(dice);  // Score for Small Straight
      largestraight(dice);  // Score for Large Straight
      yahtzee(dice);    // Score for Yahtzee
      chance(dice);     // Score for Chance (sum of all dice values)
    
}



// Function to calculate and return the score for a specific category
int scoreCategory(int dice[], int category) {
    
   // Array to count the occurrences of each die value (1 to 6)
    int count[7] = {0}; 
    
     // Counting the occurrences of each dice value (from 1 to 6)
    for (int i = 0; i < 5; i++) {
        count[dice[i]]++; // Increment the count for the dice value
    }

    
// Handle the scoring for different categories
    switch (category) {
    int total=0; // To store the calculated score
    int hasThreeOfAKind = 0; // A flag to check if there are exactly three dice of the same value. It is set to 1 if found, and 0 if not.
    int hasTwoOfAKind = 0;  // A flag to check if there are exactly two dice of the same value. It is set to 1 if found, and 0 if not.
   
        case 1: return count[1]; //ones
        case 2: return count[2] * 2;//twos
        case 3: return count[3] * 3;//threes
        case 4: return count[4] * 4;//fours
        case 5: return count[5] * 5;//fives
        case 6: return count[6] * 6;//sixes
        
        // Scoring for three of a kind
        case 7:
               total = 0; // Initialize total for this case
              
              for (int i = 1; i <= 6; i++) {
               if (count[i] >= 4) { // Check for four or more
             
                   total = 0; // Reset total before summing all dice
              
              for (int j = 0; j < 5; j++) {
                total += dice[j]; // Sum all dice 
            }
            break; // No need to continue after finding a three of a kind
            }
           }
           
            return total; //returning the total
        
         // Scoring for three of a kind
         case 8: 
             total = 0; // Initialize total for this case(two times unnececsory)

             for (int i = 1; i <= 6; i++) {
                 if (count[i] >= 3) { // Check for three or more
           
             total = 0; // Reset total before summing all dice
            
            for (int j = 0; j < 5; j++) {
                total += dice[j]; // Sum all dice
            }
            break; // No need to continue after finding a three of a kind
        }
    }
    
    return total; //returning total
       

       //scores for fullhouse
        case 9:hasThreeOfAKind = 0;
               hasTwoOfAKind = 0;
    
    for (int i = 1; i <= 6; i++) {
        if (count[i] == 3) hasThreeOfAKind = 1; // Check if there are exactly three dice of the same value. If so, mark hasThreeOfAKind as 1.
        if (count[i] == 2) hasTwoOfAKind = 1; // Check if there are exactly two dice of the same value. If so, mark hasTwoOfAKind as 1.
        }
      return (hasThreeOfAKind && hasTwoOfAKind) ? 25 : 0;// If both conditions are true (3 of a kind and 2 of a kind), return 25 for a Full House. Otherwise, return 0.
        
        //scores for small straight
        case 10:
        // Check if there are at least one occurrence of each of the numbers 1, 2, 3, 4 (small straight), 
        // or the numbers 2, 3, 4, 5 (another possible small straight), 
        // or the numbers 3, 4, 5, 6 (third possible small straight).
         return (count[1] && count[2] && count[3] && count[4]) || 
                       (count[2] && count[3] && count[4] && count[5]) || 
                       (count[3] && count[4] && count[5] && count[6]) ? 30 : 0; // If any of the above conditions are true, return 30 (the score for small straight). 
                     // Otherwise, return 0 (no small straight found).

        //largestraight 
        case 11:
         // Check if there are at least one occurrence of each of the numbers 1, 2, 3, 4, 5 (first large straight),
        // or the numbers 2, 3, 4, 5, 6 (second large straight).
         return (count[1] && count[2] && count[3] && count[4] && count[5]) || 
                       (count[2] && count[3] && count[4] && count[5] && count[6]) ? 40 : 0;// If any of the above conditions are true, return 40 (the score for large straight).
                     // Otherwise, return 0 (no large straight found).

        //scores for yahtzee
        case 12: 
        // Check if any die value occurs exactly 5 times (Yahtzee requires all dice to be the same)
        
        for (int i = 1; i <= 6; i++) {
        if (count[i] == 5) { 
        return 50;  // If all 5 dice show the same number, it's a Yahtzee, return the score (50 points)
    }
}
return 0; // If no Yahtzee is found (no 5 identical dice), return 0
        
        // Chance
        case 13: 
        total = 0; // Initialize total for Chance case
        
       // Loop through each die to sum their values
        for (int i = 0; i < 5; i++) {
        total += dice[i]; // Add the value of each die to the total
        }
               return total; // Return the calculated total (sum of all dice values)
             
             // Invalid category
              default: return 0;
    }

}




// Function to determine and print the winner based on the total scores
void findingwinner(int player1total, int player2total) {
    // Printing the total score of Player 1
    printf("human = %d\n", player1total); 
    // Printing the total score of the computer (Player 2)
    printf("computer  = %d\n", player2total);
    printf("\n");

  // Comparing the scores of Player 1 and Player 2 (computer)
    if (player1total > player2total) {    
       // If Player 1's score is higher, Player 1 wins
        printf("human wins!\n");     
    } else if (player1total == player2total) {
        // If the scores are equal, it's a draw
        printf("It's a draw!\n");
    } else {
        // If Player 2's score is higher, the computer wins
        printf("computer wins!\n");
    }
}





// Function to determine which dice the computer should keep based on the current game state
int computerKeepDice(int dice[], int kept[], int category, int categoriesUsed2[]) {
    int ckeepDiceFlag = 0; // Flag to track if any dice were kept
    int counts[6] = {0}; // Array to store the count of each die value (1-6)
    int straightskeeping = 0; // Flag to indicate if the computer is keeping dice for straights
    int mostcountedkeeping = 0; // Flag to indicate if the computer is keeping the most frequent dice (Yahtzee)
    int fullhouse=0;// Flag to indicate if the computer is keeping dice for a Full House
 
 // Variables for Full House check
    int hasThreeOfAKind = 0, hasTwoOfAKind = 0;
    int valueThree = 0, valueTwo = 0;

     // Count occurrences of each dice value
        for (int i = 0; i < 5; i++) {
            counts[dice[i]-1]++; //beacause counts[6] intead of counts[7]
        }

  
       // Check for high-priority categories (Full House, Small Straight, Large Straight, Yahtzee)
  int highPriorityCategories[] = {9, 10, 11, 12}; // Indices for Full House, Small Straight, Large Straight, Yahtzee
     for (int j = 0; j < 4; j++) { // Loop through high-priority categories
    int category = highPriorityCategories[j];
    int score = scoreCategory(dice, category);
    if (score == 25 || score == 30 || score == 40 || score == 50) {
        if(!categoriesUsed2[category-1]) {
        return 0; // Stop keeping dice if the category is achievable and unused
    }
    }
    
}

// Check if both Small and Large Straight categories are already scored, so try for Full House if available
 if ((categoriesUsed2[9] && categoriesUsed2[10])&&!categoriesUsed2[8]&&!mostcountedkeeping) {
       
       fullhouse=1;//msrking that computer started to keep dices for full house
    
          // Check for a Full House pattern
        for (int i = 1; i <= 6; i++) {
            if (counts[i] == 3) {
                hasThreeOfAKind = 1;
                valueThree = i;// Store the value for Three of a Kind
            } else if (counts[i] == 2) {
                hasTwoOfAKind = 1;
                valueTwo = i;// Store the value for Two of a Kind
            }
        }

          // Keep dice if Full House pattern is found
        if (hasThreeOfAKind && hasTwoOfAKind) {
            for (int j = 0; j < 5; j++) {
                if (dice[j] == valueThree || dice[j] == valueTwo) {
                    kept[j] = dice[j]; // Keep this die
                    ckeepDiceFlag = 1;
                }
            }
        } else {
             // Keep dice with counts >= 2 to try forming a Full House
            for (int j = 0; j < 5; j++) {
                if (counts[dice[j]] >= 2) {
                    kept[j] = dice[j]; // Keep this die
                    ckeepDiceFlag = 1;
                }
            }
        }
    }




// Calculate the most frequently occurring dice value
int maxvalue = 0;
int maxdice = 0;

// Find the most frequently occurring dice value
for (int i = 0; i < 6; i++) { // Loop through counts for values 1 to 6
    if (counts[i] > maxvalue) { 
        maxvalue = counts[i];
        maxdice = i + 1; // Store the value of the most counted dice and Add 1 to match the actual dice value (1-6)
    }
}

    

    // Yahtzee Strategy: Keep dice with the most frequent value if Full House or Straight is not prioritized
    if (maxvalue>=3||categoriesUsed2[9]&&categoriesUsed2[10] &&!straightskeeping && !fullhouse) {
                        
            for (int i = 0; i < 5; i++) { 
                if (dice[i] == maxdice) {
                    kept[i] = dice[i]; // Keep this die
                        ckeepDiceFlag = 1; // Mark that at least one die was kept
                        mostcountedkeeping = 1; // Indicate that the computer is keeping the most frequent die
                    
                }
            }
        
    }

     // Check for available Small or Large Straight categories and keep relevant dice
    if ((!categoriesUsed2[9] ||!categoriesUsed2[10]) && !mostcountedkeeping && maxvalue<3) {  
     
        int hasOne = 0, hastwo = 0, hasthree = 0, hasfour = 0, hasfive = 0, hassix = 0;
        int uniqueKept[7] = {0}; // Array to keep track of which dice have been kept

        // Check if each dice value is present
        for (int i = 0; i < 5; i++) {
            if (dice[i] == 1) hasOne = 1;
            if (dice[i] == 2) hastwo = 1;
            if (dice[i] == 3) hasthree = 1;
            if (dice[i] == 4) hasfour = 1;
            if (dice[i] == 5) hasfive = 1;
            if (dice[i] == 6) hassix = 1;
        }

        // Check if there is a combination of dice for a Small Straight
        if ((hasOne && hastwo) || (hasOne && hasthree) || (hasOne && hasfour) || (hasOne && hasfive) || (hasOne && hassix) ||
            (hastwo && hasthree) || (hastwo && hasfour) || (hastwo && hasfive) || (hastwo && hassix) ||
            (hasthree && hasfour) || (hasthree && hasfive) || (hasthree && hassix) || (hasfour && hassix)) {
            
            // Keep the dice involved in the small straight
            for (int i = 0; i < 5; i++) {
                if (dice[i] == 1 || dice[i] == 2 || dice[i] == 3 || dice[i] == 4 || dice[i] == 5) {
                    if (!uniqueKept[dice[i]]) {
                        kept[i] = dice[i];  // Keep this die
                        ckeepDiceFlag = 1; // Mark that at least one die was kept
                        uniqueKept[dice[i]] = 1; // Prevent keeping the same die multiple times
                        straightskeeping = 1; // Mark that the computer is keeping dice for straights
                    }
                }
            }
        }
    }


    return ckeepDiceFlag; // Return whether any dice were kept
}





// Function to determine the best category for the computer to select based on scoring potential
int getBestCategory(int dice[], int categoriesUsed2[], int computerturn, int category) {
    int bestCategory = 0; // Default to indicate no valid category selected
    int highestScore = -1;// Initialize with -1 to ensure any score is higher(score could be equal to 0 sometimes)
  int score = scoreCategory(dice, category);
 
  
      // Loop through each category to evaluate scoring potential
    for (category = 1; category <= 13; category++) {
    
            
           int score = scoreCategory(dice, category);// Calculate score for current category
            
            // Check for high-priority categories (Full House, Small Straight, Large Straight, Yahtzee)
         if (score == 25 || score == 30 || score == 40 || score == 50) { 
                // Ensure the category hasn't been used
                if (!categoriesUsed2[category - 1]) {
                 // Update best category if it's the highest priority score found so far
                if (score > highestScore) {
                highestScore = score;
                bestCategory = category;  // Assign this category as the best option
                }
                }
            }
            
            
          //if high priority categories not found,choose the category who has the highest category
            if (score > highestScore) { // Ensure the category hasn't been used
                if (!categoriesUsed2[category - 1]) {
                highestScore = score; //assigning the score which is higher than the highest score to the highestscore
                bestCategory = category;// Return the best scoring category or 0 if none available
                }
            }
       
    }

 
 

    // If it's the third turn and no high-score category is found, pick any available category
    if (computerturn == 3 && bestCategory == 0) {
        for (category = 1; category <= 13; category++) {
            if (!categoriesUsed2[category - 1]) {
                return category; // Choose the first unused category
            }
        }
    }
  
    return bestCategory; // Returns highest-scoring category if found, or 0 if none available
   
}

//function to display final scoreboard(scores that human and computer slected and total)
 void finalscoreboard(int scores1[],int scores2[],int player1total,int computerTotal) {
    
    
    
printf("                    human        | computer \n");
printf("1.  1's            |   %d        |     %d     \n",scores1[0],scores2[0]);
printf("2.  2's            |   %d        |     %d     \n",scores1[1],scores2[1]);
printf("3.  3's            |   %d        |     %d     \n",scores1[2],scores2[2]);
printf("4.  4's            |   %d        |     %d     \n",scores1[3],scores2[3]);
printf("5.  5's            |   %d        |     %d     \n",scores1[4],scores2[4]);
printf("6.  6's            |   %d        |     %d     \n",scores1[5],scores2[5]);
printf("7. Four of a Kind  |   %d        |     %d     \n",scores1[6],scores2[6]);
printf("8. Three of a Kind |   %d        |     %d     \n",scores1[7],scores2[7]);
printf("9. Full House      |   %d        |     %d     \n",scores1[8],scores2[8]);
printf("10. Small Straight |   %d        |     %d     \n",scores1[9],scores2[9]);
printf("11. Large Straight |   %d        |     %d     \n",scores1[10],scores2[10]);
printf("12. Yahtzee        |   %d        |     %d     \n",scores1[11],scores2[11]);
printf("13. Chance         |   %d        |     %d      \n",scores1[12],scores2[13]);
printf("total              |   %d        |     %d      \n",player1total,computerTotal);
 }