/*
 * ciphers.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Katherine Gurgenian
 * gurgenia
 *
 * EECS 183: Project 3
 * Winter 2023
 *
 * Encrypt and decrypt messages using three different cryptography methods:
 * Caesar, Vigenere, or Polybius
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;

void ciphers() {
    string inputCipherChoice;
    string inputCryptType;
    string message = "";
    string keywordStr;
    int keywordInt;
    string returnedMessage;
    char grid[SIZE][SIZE];
    int sumToEvaluate= 0;
    
    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): ";
    getline(cin, inputCipherChoice);
    cout << endl;
    
    //changes all chars to uppercase to allow for lowercase and mixed inputs to
    //be accepted
    for (int i = 0; i < inputCipherChoice.size(); ++i) {
        inputCipherChoice.at(i) = toupper(inputCipherChoice.at(i));
    }
    
    //ends program if input is improper
    if (!(inputCipherChoice == "CAESAR" || inputCipherChoice == "C" ||
          inputCipherChoice == "POLYBIUS" || inputCipherChoice == "P" ||
          inputCipherChoice == "VIGENERE" || inputCipherChoice == "V")) {
        cout << "Invalid cipher!";
        return;
    }
    
    
    cout << "Encrypt or decrypt: ";
    getline(cin, inputCryptType);
    cout << endl;
    
    //changes all chars to uppercase to allow for lowercase and mixed inputs to
    //be accepted
    for (int i = 0; i < inputCryptType.size(); ++i) {
        inputCryptType.at(i) = toupper(inputCryptType.at(i));
    }
    
    //ends program if input is improper
    if (!(inputCryptType == "E" || inputCryptType == "D"
          || inputCryptType == "ENCRYPT" || inputCryptType == "DECRYPT")) {
        cout << "Invalid mode!";
        return;
    }

    
    if (inputCipherChoice == "CAESAR" || inputCipherChoice == "C") {
        cout << "Enter a message: ";
        getline(cin, message);
        cout << endl;
        cout << "What is your key: ";
        cin >> keywordInt;
        cout << endl;
        
        //encrypts of decrypts messages (based on user input)
        if (inputCryptType == "ENCRYPT" || inputCryptType == "E") {
            
            returnedMessage = caesarCipher(message, keywordInt, true);
            cout << "The encrypted message is: " << returnedMessage;
        }
        else {
            returnedMessage = caesarCipher(message, keywordInt, false);
            cout << "The decrypted message is: " << returnedMessage;
        }
        
    }
    else if (inputCipherChoice == "VIGENERE" || inputCipherChoice == "V") {
        cout << "Enter a message: ";
        getline(cin, message);
        cout << endl;
        cout << "What is your key: ";
        getline(cin, keywordStr);
        cout << endl;
        
        //Checks for valid key
        for (int i = 0; i < keywordStr.size(); ++i) {
            if (isalpha(keywordStr.at(i))) {
                ++sumToEvaluate;
            }
        }
        if (sumToEvaluate == 0) {
            cout << "Invalid key!";
            return;
        }
        
        if (inputCryptType == "ENCRYPT" || inputCryptType == "E") {
            returnedMessage = vigenereCipher(message, keywordStr, true);
            cout << "The encrypted message is: " << returnedMessage;
        }
        else {
            returnedMessage = vigenereCipher(message, keywordStr, false);
            cout << "The decrypted message is: " << returnedMessage;
        }
        
    }
    else if (inputCipherChoice == "POLYBIUS" || inputCipherChoice == "P") {
        cout << "Enter a message: ";
        getline(cin, message);
        cout << endl;
        
        //Check for valid message
        for (int i = 0; i < message.size(); ++i) {
            if (!(isalpha(message.at(i)) || isdigit(message.at(i))
                  || isspace(message.at(i)))) {
                ++sumToEvaluate;
            }
        }
        
        if (sumToEvaluate > 0) {
            cout << "Invalid message!";
            return;
        }
        
        
        cout << "What is your key: ";
        getline(cin, keywordStr);
        cout << endl;
        
        //changes all chars to uppercase to allow for lowercase and mixed
        //inputs to be accepted for the below two four loops
        for (int i = 0; i < keywordStr.size(); ++i) {
            keywordStr.at(i) = toupper(keywordStr.at(i));
        }
        for (int i = 0; i < message.size(); ++i) {
            message.at(i) = toupper(message.at(i));
        }
        
        //encrypts of decrypts messages (based on user input)
        if (inputCryptType == "ENCRYPT" || inputCryptType == "E") {
            returnedMessage = polybiusSquare(grid, keywordStr, message, true);
            cout << "The encrypted message is: " << returnedMessage;
        }
        else {
            returnedMessage = polybiusSquare(grid, keywordStr, message, false);
            cout << "The decrypted message is: " << returnedMessage;
        }
        
    }
    
    return;
}
