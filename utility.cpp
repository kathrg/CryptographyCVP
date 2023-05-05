/*
 * utility.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Katherine Gurgenian
 * gurgenia
 *
 * EECS 183: Project 3
 * Winter 2023
 *
 * Useful functions to be utilized in subsequent files for encryption and
 * decryption
 */

#include "utility.h"
#include <iostream>


string toUpperCase(string original) {
    string allCapitalized = original;
    
    //changes all alpha characters to uppercase
    for (int i = 0; i < original.size(); ++i) {
        if (isalpha(original.at(i))) {
            allCapitalized.at(i) = toupper(allCapitalized.at(i));
            }
    }
    
    return allCapitalized;
}

string removeNonAlphas(string original) {
    string newOriginal = "";
    
    //removes all nonalphas from a string
    for (int i = 0; i < original.size(); ++i) {
        if (isalpha(original.at(i))) {
            newOriginal += original.at(i);
        }
    }
    
    return newOriginal;
}

string removeDuplicate(string original) {
    string newOriginal = "";
    int sum = 0;
    
    //has to be outside nestled for loops because j cannot be negative
    newOriginal += original.at(0);
    
    //looks through the list for duplicates
    for (int i = 1; i < original.size(); ++i) {
        for (int j = i - 1; j > 0; --j) {
            
            if (original.at(i) == original.at(j)) {
                ++sum;
            }
        }
        
        //if no duplicates found, add char to new string
        if (sum == 0 && original.at(i) != original.at(0)) {
            newOriginal += original.at(i);
        }
        
        sum = 0;
    }

    return newOriginal;
}

int charToInt(char original) {
    int newInt = 0;
    int listOfNumbers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char correspondingNumChars[10] = {'0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9'};
    
    //reads through list of numbers until a matching value is found, and its
    //corresponding char is identified
    for (int i = 0; i <= 9; ++i) {
        if (correspondingNumChars[i] == original) {
            newInt = listOfNumbers[i];
        }
    }

    return newInt;
}

////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}
