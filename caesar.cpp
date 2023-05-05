/*
 * caesar.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Katherine Gurgenian
 * gurgenia
 *
 * EECS 183: Project 3
 * Winter 2023
 *
 * Allows for encryption and decryption using the Caesar method
 */

#include "caesar.h"
#include <iostream>
#include "utility.h"

char shiftAlphaCharacter(char c, int n) {
    int i = 0;
    int leftover;
    char newChar;
    int charAsInt = int(c);
    int asciiValue = charAsInt;
    
    //change backward shift to a forward shift, there are 26 letters in the
    //alphabet
    if (n < 0) {
        n = (n % 26) + 26;
       }
    
    if (n > 0) {
        //account for any numbers that are shifted through the entire alphabet
        //x amount of times prior to reaching their destination
        n = (n % 26);
         
        //increase the char n times, 65 is A's ASCII value and 90 is Z's
        //ASCII value
        if (charAsInt >= 65 && charAsInt <= 90) {
            while (i != n) {
                ++asciiValue;
                ++i;
            }
            
            //to account for if char exceeds Z's ASCII value
            while (asciiValue > 90) {
                leftover = asciiValue - 90;
                //the 64 is the number right before A's ASCII value (65)
                asciiValue = 64 + leftover;
            }
        }
        //same thing as first branch of if-else statement above, but for
        //lowercase letters, 97 is a's ASCII value and 122 is z's ASCII value
        else if (charAsInt >= 97 && charAsInt <= 122) {
            while (i != n) {
                ++asciiValue;
                ++i;
            }
                 
            while (asciiValue > 122) {
                leftover = asciiValue - 122;
                //96 is the number right before a's ASCII value
                asciiValue = 96 + leftover;
            }
        }
             
        newChar = char(asciiValue);
    }
    else {
        //if n = 0, then no shift for c
        newChar = c;
    }
         
    return newChar;
}


string caesarCipher(string original, int key, bool encrypt) {
    string newOriginal = "";
    string holderForLetters[original.size()];
    string copyOriginalEncrypt = original;
    string copyOriginalDecrypt = original;
    
    //encrypt all alpha characters in the string int amount
    if (encrypt == true) {
        for (int i = 0; i < original.size(); ++i) {
            if (isalpha(original.at(i))) {
                copyOriginalEncrypt.at(i) =
                shiftAlphaCharacter(original.at(i), key);
            }
            else {
                copyOriginalEncrypt.at(i) = original.at(i);
            }
        }
        for (int j = 0; j < original.size(); ++j) {
            newOriginal += copyOriginalEncrypt.at(j);
        }
    }
    //decrypt all alpha characters in the string int amount
    else {
        key *= -1;
        
        for (int i = 0; i < original.size(); ++i) {
            if (isalpha(original.at(i))) {
                copyOriginalDecrypt.at(i) =
                shiftAlphaCharacter(original.at(i), key);
            }
            else {
                copyOriginalDecrypt.at(i) = original.at(i);
            }
        }
        
        for (int j = 0; j < original.size(); ++j) {
            newOriginal += copyOriginalDecrypt.at(j);
        }
    }
    
    return newOriginal;
}
