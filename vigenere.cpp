/*
 * vigenere.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Katherine Gurgenian
 * gurgenia
 *
 * EECS 183: Project 3
 * Winter 2023
 *
 * Allows for encryption and decryption using the Vigenere method
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include <iostream>
#include <cmath>

string vigenereCipher(string original, string keyword, bool encrypt) {
    
    //placeholder is meant to account for spaces
    int placeholder = 0;
    string newOriginal = "";
    string finalOriginal = original;
    
    //Strip keyword and original of everything but alphas
    string keywordOnlyAlphas = removeNonAlphas(keyword);
    string originalOnlyAlphas = removeNonAlphas(original);
    
    string keywordWithRepitions = keywordOnlyAlphas;
    string keywrodFinal;
    

    int shiftForEachLetter[26] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
        14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    char eachLetterOrdered[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
        'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
        'X', 'Y', 'Z'};
    
    //This is needed to find the total amount of times the keyword needs to be
    //repeated after its last letter
    double differenceInLength =
        originalOnlyAlphas.size() - keywordOnlyAlphas.size();
    int totalAmountOfRepitions =
        ceil(differenceInLength / keywordOnlyAlphas.size());
    
    //Attaining keyword with the necessary amount of repetitions
    for (int i = 0; i < totalAmountOfRepitions; ++i) {
        keywordWithRepitions += keywordOnlyAlphas;
    }
    
    int amountToShiftEncode[keywordWithRepitions.size()];
    int amountToShiftDecode[keywordWithRepitions.size()];
    
    //Move each char in keywordWithRepitions to an array
    for (int i = 0; i < keywordWithRepitions.size(); ++i) {
        amountToShiftEncode[i] = toupper(keywordWithRepitions.at(i));
    }
    
    //Match char to letter in alphabet, and take on its corresponding number
    //that determines amount to be shifted
    for (int i = 0; i < keywordWithRepitions.size(); ++i) {
        for (int j = 0; j < 26; ++j) {
            if (amountToShiftEncode[i] == eachLetterOrdered[j]) {
                amountToShiftEncode[i] = shiftForEachLetter[j];
            }
        }
    }
    

    if (encrypt) {
        //encrypt original string (excluding any none alpha characters)
        for (int k = 0; k < originalOnlyAlphas.size(); ++k) {
            newOriginal += shiftAlphaCharacter(originalOnlyAlphas.at(k),
                                               amountToShiftEncode[k]);
            }
        
        //have the original string take on the encrypted string's chars ONLY at
        //alpha sites (purpose of placeholder)
        for (int k = 0; k < original.size(); ++k) {
            if (isalpha(finalOriginal.at(k))) {
                finalOriginal.at(k) = newOriginal.at(k - placeholder);
            }
            else {
                ++placeholder;
            }
        }
    }
    else {
        //change encoding values (positive and forward) to decoding values
        //(negative and backward)
        for (int k = 0; k < keywordWithRepitions.size(); ++k) {
            amountToShiftDecode[k] = amountToShiftEncode[k] * -1;
        }
        
        //decrypt original string (excluding any none alpha characters)
        for (int k = 0; k < originalOnlyAlphas.size(); ++k) {
            newOriginal += shiftAlphaCharacter(originalOnlyAlphas.at(k),
                                               amountToShiftDecode[k]);
        }
        //have the original string take on the decrypted string's chars ONLY
        //at alpha sites (purpose of placeholder)
        for (int k = 0; k < original.size(); ++k) {
            if (isalpha(finalOriginal.at(k))) {
                finalOriginal.at(k) = newOriginal.at(k - placeholder);
            }
            else {
                ++placeholder;
            }
        }
    }
    
    return finalOriginal;
}

