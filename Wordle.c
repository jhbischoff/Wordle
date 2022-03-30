/****************************************************************
|            Command line implementation of Wordle in C         |
|                                                               |
|                    Jake Bischoff, v1.1, 2022                  |
*****************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include "bin/words.h"

#define VERSION 1.1
#define WORD_COUNT 2499

char menuNav;
char word[5];
int wordleNumber;

void mainScreen();
void winScreen(int tries);
void loseScreen();
void adjustCursor(int guessNum);
void printWord(char word[5], int guessNum);
void getWord();

int main(){
    getWord();
    char guess[5];
    mainScreen();
    
    for(int i = 0; i < 6; i++){
        RETRY:
        for(int j = 0; j < 5; j++){
            guess[j] = '\0';
        }
        scanf("%s", guess);
        for(int j = 0; j < 5; j++){
            if(guess[j] == '\0'){
                printf("\033[F\r|      \b\b\b\b\b");
                goto RETRY;
            }
            guess[j] = toupper(guess[j]);
        }
        adjustCursor(i);
        printWord(guess, i);
        if(strcmp(guess, word) == 0){
            winScreen(i + 1);
            scanf("%c", &menuNav);
            return 0;
        }
    }
    loseScreen();
    return 0;
}

void mainScreen(){
    printf("\n\n|~~~~~~WORDLE~~~~~|\n");
    printf("|~~~~~~~v%.1lf~~~~~~|\n", VERSION);
    if(wordleNumber < 1000){
        printf("|       #%d      |\n", wordleNumber);
    } else {
        printf("|      #%d      |\n", wordleNumber);
    }
    printf("|   [         ]   |\n");
    printf("|   [         ]   |\n");
    printf("|   [         ]   |\n");
    printf("|   [         ]   |\n");
    printf("|   [         ]   |\n");
    printf("|   [         ]   |\n");
    printf("| Guess:          |\n");
    printf("|                 |\n");
    printf("|~~~~~~~~~~~~~~~~~|\033[F\r| ");
    return;
}

void winScreen(int tries){
    printf("\033[F\r");
    printf("|                 |\n");
    printf("|   You won in    |\n");
    printf("|        %d        |\n", tries);
    printf("|     tries!      |\n");
    printf("|                 |\n");
    printf("|~~~~~~~~~~~~~~~~~|\n");
}

void loseScreen(){
    printf("\033[F\r");
    printf("|                 |\n");
    printf("|    You lost!    |\n");
    printf("| the Wordle was: |\n");
    printf("|     %s       |\n", word);
    printf("|                 |\n");
    printf("|~~~~~~~~~~~~~~~~~|\n\n");
}

void adjustCursor(int guessNum){
    for(int i = 0; i < 8 - guessNum; i++){
            printf("\033[F\r");
    }
}

void printWord(char guess[5], int guessNum){
    printf("|   [");
    for(int i = 0; i < 5; i++){
        if(word[i] == guess[i]){
            printf("\033[0;32m");
            printf("%c ", guess[i]);
            printf("\033[0;0m");
        } else {
            for(int j = 0; j < 5; j++){
                if(guess[i] == word[j]){
                    printf("\033[0;33m");
                }
            }
            printf("%c ", tolower(guess[i]));
            printf("\033[0;0m");
        }
    }
    printf("\b]   |\n");
    for(int i = 0; i < 5 - guessNum; i++){
        printf("|   [         ]   |\n");
    }
    printf("| Guess:          |\n");
    printf("|                 |\n");
    printf("|~~~~~~~~~~~~~~~~~|\033[F\r| ");
    return;
}

void getWord(){
    srand(time(NULL));
    wordleNumber = rand() % WORD_COUNT;
    for(int i = 0; i < 5; i++){
        word[i] = toupper(wordList[wordleNumber][i]);
    }
}