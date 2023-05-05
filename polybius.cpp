/*
 * polybius.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Katherine Gurgenian
 * gurgenia
 *
 * EECS 183: Project 3
 * Winter 2023
 *
 * Allows for encryption and decryption using the Polybius method
 */


#include "polybius.h"
#include "utility.h"
#include <string>
using namespace std;

string mixKey(string key) {
    //adds key and ALNUM together prior to removing duplicates
    string keyCopy = key + ALNUM;
    string finalProduct = removeDuplicate(keyCopy);

    return finalProduct;
}

void fillGrid(char grid[SIZE][SIZE], string content) {
    int k = 0;
    
    //fills in the grid with contents of the provided string
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            grid[i][j] = content.at(k);
            ++k;
        }
        
    }
    
    return;
}


string findInGrid(char c, char grid[SIZE][SIZE]) {
    string correspondingGridValue;
    
    //finds a char's corresponding row and columns values
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (grid[i][j] == c) {
                correspondingGridValue = to_string(i) + to_string(j);
            }
        }
    }

    return correspondingGridValue;
}

string polybiusSquare(char grid[SIZE][SIZE], string key,
                      string original, bool encrypt) {
    string messageMinusSpaces = "";
    string newMessage = "";
    string decodingMinusSpaces = "";
    string toBePutInGrid = mixKey(key);
    fillGrid(grid, toBePutInGrid);
    
    //encodes each letter to its corresponding row and column values
    if (encrypt == true) {
        for (int i = 0; i < original.size(); ++i) {
            if (isspace(original.at(i))) {
                newMessage += " ";
            }
            else {
                newMessage += findInGrid(original.at(i), grid);
            }
        }
    }
    //decodes every pair of numbers to its corresponding char
    else {
            for (int i = 0; i < original.size() - 1; i += 2) {
                if (isspace(original.at(i))) {
                    newMessage += " ";
                    ++i;
                    newMessage += grid[charToInt(original.at(i))]
                                        [charToInt(original.at(i + 1))];
                }
                else {
                    newMessage += grid[charToInt(original.at(i))]
                                        [charToInt(original.at(i + 1))];
                }
        }
    }

    
    
    return newMessage;
}
