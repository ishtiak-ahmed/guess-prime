#include <stdio.h>
#include <stdbool.h>
#include <math.h>  

bool isPrime(int a){
  int root = (int) sqrt(a);
  for(int i = 2; i < root; i++){
    if(a % i == 0){
      return false;
    }
  }
  return true;
}

void gameIntro(){
  printf("Welcome to PRIME number guessing game.\n");
  printf("I hope you already know what is a Prime number.\n\n");
  printf("Here is a quick reminder, \"Prime number is a positive integer number,\n");
  printf("which can only be divisible by 1 and the number itself.\n");
  printf("2, 3 are the first 2 prime number. But 4 is not a prime number.\n");
  printf("Because 4 can be divisible by 2.\n\n");
  printf("In this game, you have to guess 10 prime number between 2000 to 7000.\n");
  printf("If you guess 5+ prime number correctly, you win.\n");
  printf("\n");
  printf("Without any further ado, Let's start the game!\n\n");
}

void gameOutro(){
  printf("\nThanks for playing the game.\n");
  printf("This command line game is Build with C programming language\nby Ishtiak Ahmed (https://github.com/ishtiak-ahmed)\n");
}

void congratsWinner(int correctGuess){
  printf("\nCongratulations! You guessed %d prime number correctly of 10!\n", correctGuess);
  printf("\n");
}

void losingMessage(int correctGuess){
  printf("\nYou guessed %d correctly out of 10\nBetter luck next time\n", correctGuess);
}

int main(void){
  int totalGuess = 10, guessUsed = 0, correctGuess = 0;
  int guessedNumber[totalGuess];
  int n;
  bool alreadyGuessed = false;
  gameIntro();
  while(guessUsed < totalGuess){
    printf("Guess a Prime number: ");
    // scanf("%d", &n);
    if (scanf("%d", &n) != 1)
    {
      printf("This is not a number.\n");
      n = 0;
      continue;
    }
    if(n < 2000 || n > 7000){
      printf("%d is not in the range of 2000 to 7000\n", n);
      continue;
    }
    alreadyGuessed = false;
    for(int i = 0; i < guessUsed; i++){
      if(guessedNumber[i] == n){
        printf("You already guessed it. Enter another\n");
        alreadyGuessed = true;
        break;
      }
    }
    if(alreadyGuessed){
      continue;
    }
    if(!alreadyGuessed){
      guessedNumber[guessUsed] = n;
    }
    bool prime = isPrime(n);
    if(prime){
      printf("CORRECT! %d is a Prime number\n", n);
      correctGuess++;
    }else{
      printf("Incorrect! %d is not a Prime number\n", n);
    }
    guessUsed++;
  }
  if(correctGuess >= 5){
    congratsWinner(correctGuess);
  }else{
    losingMessage(correctGuess);
  }
  gameOutro();
}


/*
    Welcome to prime number guessing games
    I hope you already know what is a Prime number.
    Here is a reminder, "Prime number is a integer number which can only
    be divisible by 1 and the number itself. 2, 3 are the first 2 prime number.
    But 4 is not prime. Because 4 can be divisible by 2"

    In this you have to guess 10 prime number between 5000 to 7000.
    If you guess 5+ prime number correctly you win.

    Let's start the game.

    Congratulations! You guessed 8 prime number correctly of 10!
    Thanks for playing it.
    This command line game is Build by Ishtiak Ahmed (https://github.com/ishtiak-ahmed)
 */ 

/*
 * 1. Build a function to check prime number
 * 2. Set start and end range, guessUsed, totalGuess, correct guess, guessedNumber
 * 3. Take input from user,
 * 4. If it is not in the range, show message, else...
      Check if user already guessed it or not.
      If user already guessed it, show message.
      else store in guessedNumbers
 * 5. Check prime
 * 6. If it is a prime number, show correct message, increase correct count
 * 7. If not correct show wrong message
 * 8. Increase guess count
 * 9. If guessUsed is less than totalGuess start from 3 again
 * 10. If guessUsed is equal to toalGuess, show game result
 * 11. Show greetings text and final message and invite to play again
 */ 