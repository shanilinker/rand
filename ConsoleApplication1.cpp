// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <time.h>
enum levelsMenu { EASY = 1, MODERATE = 2, HARD = 3, CRAZY = 4 };
#define MAX_RANGE 6
#define MIN_RANGE 1
const


void OpeningOfTheGame()
{
    printf("Welcome to MAGSHIMIM CODE - BREAKER !!!\n\n");// opening message
    printf("A secret password was chosen to protect the credit card of Pancratius,\n");
    printf("the descendant of Antiochus.\n");
    printf("Your mission is to stop Pancratius by revealing his secret password.\n\n");

    printf("The rules are as follows:\n");//rules
    printf(" 1. In each round you try to guess the secret password(4 distinct digits)\n");//(1)
    printf(" 2. After every guess you'll receive two hints about the password \n");//(2)
    printf("    HITS : The number of digits in your guess which were exactly right.\n");
    printf("    MISSES: The number of digits in your guess which belongs to \n");
    printf("            the password but were miss - placed.\n");
    printf("3. If you'll fail to guess the password after a certain number of rounds\n");//(3)
    printf("    Pancratius will buy all the gifts for Hanukkah!!!\n\n");

}

int  gameMenu()
{
    int level = 0;

    printf("Please choose the game level:\n");
    printf("1 - Easy (20 rounds)\n");
    printf("2 - Moderate (15 rounds)\n");
    printf("3 - Hard (10 rounds)\n");
    printf("4 - Crazy (random number of rounds 5-25)\n");
    printf("Make a choice: ");
    scanf("%d", &level);
    return level;
}
int makeRandomSecretCode()
{
    int firstDigitRandNum = 0;
    int secondDigitRandNum = 0;
    int thirdDigitRandNum = 0;
    int fourtDigitRandNum = 0;
    int randomCode = 0;
    do
    {
        firstDigitRandNum = rand() % (MAX_RANGE - MIN_RANGE + 1) + MIN_RANGE;
        secondDigitRandNum = rand() % (MAX_RANGE - MIN_RANGE + 1) + MIN_RANGE;
        thirdDigitRandNum = rand() % (MAX_RANGE - MIN_RANGE + 1) + MIN_RANGE;
        fourtDigitRandNum = rand() % (MAX_RANGE - MIN_RANGE + 1) + MIN_RANGE;

    } while (firstDigitRandNum == secondDigitRandNum || firstDigitRandNum == thirdDigitRandNum || firstDigitRandNum == fourtDigitRandNum || secondDigitRandNum == thirdDigitRandNum || secondDigitRandNum == fourtDigitRandNum || thirdDigitRandNum == fourtDigitRandNum);

    randomCode = (firstDigitRandNum * 1000) + (secondDigitRandNum * 100) + (thirdDigitRandNum * 10) + thirdDigitRandNum;
    return randomCode;
}

int checksHowManHitsThereAre(int guess, int randomSecret)
{

    int counter = 0;
    int checkingTheUnityDigitInGuess = guess % 10; // Checking the units digit in the number the user guessed
    int checksTheTensDigitInGuess = (guess % 100) / 10; // Checking the tens digit in the number the user guessed
    int checksTheHundredsDigitInGuess = (guess / 100) % 10; // Checking the hundreds digit in the number the user guessed
    int checkingTheThousandsDigitInGuess = guess / 1000; // Checking the thousands digit in the number the user guessed

    int checkingTheUnityDigitInRandomSecret = randomSecret % 10; // Checking the units digit in  randomSecret
    int checksTheTensDigitInRandomSecret = (randomSecret % 100) / 10; // Checking the tens digit in  randomSecret
    int checksTheHundredsDigitInRandomSecret = (randomSecret / 100) % 10; // Checking the hundreds digit in  randomSecret
    int checkingTheThousandsDigitInRandomSecret = randomSecret / 1000; // Checking the thousands digit in  randomSecret

    if (checkingTheUnityDigitInGuess == checkingTheUnityDigitInRandomSecret)
    {
        counter++;
    }

    if (checksTheTensDigitInGuess == checksTheTensDigitInRandomSecret)
    {
        counter++;
    }

    if (checksTheHundredsDigitInGuess == checksTheHundredsDigitInRandomSecret)
    {
        counter++;
    }

    if (checkingTheThousandsDigitInGuess == checkingTheThousandsDigitInRandomSecret)
    {
        counter++;
    }

    return counter;

}
int checksHowManMISSESThereAre(int guess, int randomSecret)
{
    int  count = 0;
    int checkingTheUnityDigitInGuess = guess % 10; // Checking the units digit in the number the user guessed
    int checksTheTensDigitInGuess = (guess % 100) / 10; // Checking the tens digit in the number the user guessed
    int checksTheHundredsDigitInGuess = (guess / 100) % 10; // Checking the hundreds digit in the number the user guessed
    int checkingTheThousandsDigitInGuess = guess / 1000; // Checking the thousands digit in the number the user guessed

    int checkingTheUnityDigitInRandomSecret = randomSecret % 10; // Checking the units digit in  randomSecret
    int checksTheTensDigitInRandomSecret = (randomSecret % 100) / 10; // Checking the tens digit in  randomSecret
    int checksTheHundredsDigitInRandomSecret = (randomSecret / 100) % 10; // Checking the hundreds digit in  randomSecret
    int checkingTheThousandsDigitInRandomSecret = randomSecret / 1000; // Checking the thousands digit in  randomSecret

    if (checkingTheUnityDigitInGuess == checkingTheUnityDigitInRandomSecret || checkingTheUnityDigitInGuess == checksTheTensDigitInRandomSecret || checkingTheUnityDigitInGuess == checksTheHundredsDigitInRandomSecret || checkingTheUnityDigitInGuess == checkingTheThousandsDigitInRandomSecret)
    {
        count++;
    }

    if (checksTheTensDigitInGuess == checkingTheUnityDigitInRandomSecret || checksTheTensDigitInGuess == checksTheTensDigitInRandomSecret || checksTheTensDigitInGuess == checksTheHundredsDigitInRandomSecret || checksTheTensDigitInGuess == checkingTheThousandsDigitInRandomSecret)
    {
        count++;
    }

    if (checksTheHundredsDigitInGuess == checkingTheUnityDigitInRandomSecret || checksTheHundredsDigitInGuess == checksTheTensDigitInRandomSecret || checksTheHundredsDigitInGuess == checksTheHundredsDigitInRandomSecret || checksTheHundredsDigitInGuess == checkingTheThousandsDigitInRandomSecret)
    {
        count++;
    }

    if (checkingTheThousandsDigitInGuess == checkingTheUnityDigitInRandomSecret || checkingTheThousandsDigitInGuess == checksTheTensDigitInRandomSecret || checkingTheThousandsDigitInGuess == checksTheHundredsDigitInRandomSecret || checkingTheThousandsDigitInGuess == checkingTheThousandsDigitInRandomSecret)
    {
        count++;
    }

    return count;





}



void startTheGame(int raunds, int randomSecret)
{
    int i = 0;
    int guess = 0;
    int counter = 0;
    int hits = 0;
    int misses = 0;
    int checkingTheUnityDigitInGuess = guess % 10; //
    int checksTheTensDigitInGuess = (guess % 100) / 10; // 
    int checksTheHundredsDigitInGuess = (guess / 100) % 10; // 
    int checkingTheThousandsDigitInGuess = guess / 1000; //

    int checkingTheUnityDigitInRandomSecret = randomSecret % 10; //
    int checksTheTensDigitInRandomSecret = (randomSecret % 100) / 10; // 
    int checksTheHundredsDigitInRandomSecret = (randomSecret / 100) % 10; //
    int checkingTheThousandsDigitInRandomSecret = randomSecret / 1000;

    for (i = raunds; i > 0; i--)
    {
        printf("\nWrite your guess(only 1 - 6, no ENTER is needed)\n");
        printf("%d guesses left\n", i);
        scanf(" %d", &guess);// לסדר את  הבעיה של הקליטה של ה4 מספרים



        hits = checksHowManHitsThereAre(guess, randomSecret);
        misses = checksHowManMISSESThereAre(guess, randomSecret);
        printf("You got   %d HITS %d MISSES", hits, misses);

    }
    while( checkingTheUnityDigitInGuess > 6 || checkingTheUnityDigitInGuess < 1 || checksTheTensDigitInGuess>6 || checksTheTensDigitInGuess < 1 || checksTheHundredsDigitInGuess>6 || checksTheHundredsDigitInGuess < 1 || checkingTheThousandsDigitInGuess>6 || checkingTheThousandsDigitInGuess < 1)
    {
        printf("Only 1-6 are allowed, try agin! ");

    } 
    
}

//char startPlayAgaunOrNot(int  raunds)
//{
//    char yes;
//    yes = y;
//
//    while (raunds < 1)
//    {
//        printf(Would you like to play again ? (y / n) : )
//    }
//}


int main()
{
    int level = 0;
    int randomSecret = 0;
    int raunds = 0;

    OpeningOfTheGame();
    level = gameMenu();
    randomSecret = makeRandomSecretCode();

    if (level == EASY) {

        raunds = 20;
        startTheGame(raunds, randomSecret);

    }
    else if (level == MODERATE) {

        raunds = 15;
        startTheGame(raunds, randomSecret);
    }
    else if (level == HARD) {

        raunds = 10;
        startTheGame(raunds, randomSecret);
    }
    // להוסיף שלב משוגע


}