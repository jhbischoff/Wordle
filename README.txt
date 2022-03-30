

                 Wordle
            By Jake Bischoff
               v1.1, 2022

This program is a command line interface
mimicing the online web app Wordle from 
The New York Times, developed in C.

RULES:
    You get 6 tries to guess the correct
    5-letter word. Letters which are in 
    the correct spot of the hidden word
    will appear capitalized and green. 
    Letters which are contained in the 
    word but are in the wrong spot will
    be colored yellow. Letters which are
    not in the hidden word (and thus can
    be discarded) are left uncolored.
    Try to guess the correct word using 
    this information in as little guesses
    as possible.

USAGE:
    Compiled with GCC (Linux) using:
        gcc -Wall Wordle.c -std=c99
        ./a.out

The words are contained in "words.h" housed
in the bin folder. Be sure to compile with
C file and bin folder in the same directory.
