/**
 * test.cpp
 *
 *
 * Katherine Gurgenian
 * gurgenia
 *
 * EECS 183: Project 3
 * Winter 2023
 *
 * Testing functions for caesar.cpp, vigenere,cpp, polybius.cpp, utility.cpp, and cipher.cpp implementation
 *
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;


string toUpperCase(string original);
string removeNonAlphas(string original);
int charToInt(char original);
string removeDuplicate(string original);
char shiftAlphaCharacter(char c, int n);
string caesarCipher(string original, int key, bool encrypt);
string vigenereCipher(string original, string keyword, bool encrypt);
string mixKey(string key);
void printGrid(const char grid[SIZE][SIZE]);
void fillGrid(char grid[SIZE][SIZE], string content);
string findInGrid(char c, char grid[SIZE][SIZE]);
string polybiusSquare(char grid[SIZE][SIZE], string key, string original,
                      bool encrypt);

void test_toUpperCase();
void test_removeNonAlphas();
void test_charToInt();
void test_removeDuplicate();
void test_shiftAlphaCharacter();
void test_caesarCipher();
void test_vigenereCipher();
void test_mixKey();
void test_fillGrid();
void test_findInGrid();
void test_polybiusSquare();

void startTests() {
    cout << "\nExecuting your test cases\n";
    
    test_toUpperCase();
    test_removeNonAlphas();
    test_charToInt();
    test_removeDuplicate();
    test_shiftAlphaCharacter();
    test_caesarCipher();
    test_vigenereCipher();
    test_mixKey();
    test_fillGrid();
    test_findInGrid();
    test_polybiusSquare();

    return;
}


void test_toUpperCase() {
    cout << "Now testing function toUpperCase()\n";
    
    cout << "\"katy\": Expected: Katya, Actual: " << toUpperCase("katya")
    << endl << endl;
    
    return;
}

void test_removeNonAlphas() {
    cout << "Now testing function removeNonAlphas()\n";
    
    cout << "\"Diag @ 11 p.m.\": Expected: Diagpm, Actual: "
    << removeNonAlphas("Diag @ 11 p.m.") << endl << endl;
    
    return;
}

void test_charToInt() {
    cout << "Now testing function charToInt()\n";
    
    cout << "'1': Expected: 1, Actual: " << charToInt('1') << endl;
    cout << "'7': Expected: 7, Actual: " << charToInt('7') << endl << endl;
    
    return;
}

void test_removeDuplicate() {
    cout << "Now testing function removeDuplicate()\n";
    
    cout << "\"HELLOHWORLD\": Expected: HELOWRD, Actual: "
    << removeDuplicate("HELLOHWORLD") << endl << endl;
    
    return;
}

void test_shiftAlphaCharacter() {
    cout << "Now testing function shiftAlphaCharacter()\n";
    
    cout << "'a': Expected: a, Actual: " << shiftAlphaCharacter('a', 0)
    << endl;
    cout << "'b': Expected: d, Actual: " << shiftAlphaCharacter('b', 2)
    << endl;
    cout << "'X': Expected: V, Actual: " << shiftAlphaCharacter('X', 50)
    << endl;
    cout << "'X': Expected: W, Actual: " << shiftAlphaCharacter('Z', 127)
    << endl;
    cout << "'C': Expected: M, Actual: " << shiftAlphaCharacter('C', -42)
    << endl << endl;
    
    return;
}

void test_caesarCipher() {
    cout << "Now testing function caesarCipher()\n";
    
    cout << "\"Meet me at the Diag at 11 p.m.\": Expected:"
    << "Cuuj cu qj jxu Tyqw qj 11 f.c., Actual: " <<
    caesarCipher("Meet me at the Diag at 11 p.m.", 42, true) << endl;
    cout << "\"Cuuj cu qj jxu Tyqw qj 11 f.c.\": Expected:"
    << "Meet me at the Diag at 11 p.m., Actual: "
    << caesarCipher("Cuuj cu qj jxu Tyqw qj 11 f.c.", 42, false)
    << endl << endl;
    
    return;
}

void test_vigenereCipher() {
    cout << "Now testing function vigenereCipher()\n";
    
    cout << "\"Meet me at the Diag at 11 p.m.\": Expected:"
    << "Euyb dv ee lxy Lzrk ll 11 f.g., Actual: " <<
    vigenereCipher("Meet me at the Diag at 11 p.m.", "Squirrel!", true)
    << endl;
    cout << "\"Euyb dv ee lxy Lzrk ll 11 f.g.\": Expected:"
    << "Meet me at the Diag at 11 p.m., Actual: " <<
    vigenereCipher("Euyb dv ee lxy Lzrk ll 11 f.g.", "Squirrel!", false)
    << endl << endl;
    
    return;
}

void test_mixKey() {
    cout << "Now testing function mixKey()\n";
    
    cout << "\"POLYBIUS\": Expected: POLYBIUSACDEFGHJKMNQRTVWXZ0123456789,"
    << "Actual: " << mixKey("POLYBIUS") << endl << endl;
    return;
}

void test_fillGrid() {
    char grid[SIZE][SIZE];
    
    cout << "Now testing function fillGrid()\n";
    
    cout << "\"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\": Expected:"
    << "(insert depiction of a 6x6 grid), Actual: ";
    fillGrid(grid, ALNUM);
    printGrid(grid);
    cout << endl;
    
    return;
}

void test_findInGrid() {
    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);
    
    cout << "Now testing function findInGrid()\n";
    
    cout << "'X': Expected: 35, Actual: " << findInGrid('X', grid)
    << endl << endl;
    
    return;
}


void test_polybiusSquare() {
    char grid[SIZE][SIZE];
    
    cout << "Now testing function polybiusSquare()\n";
    
    cout << "\"EECS 183 IS THE BEST\": Expected: 11110533 000102 1533 341411"
    << "04113334, Actual: "
    << polybiusSquare(grid, "183", "EECS 183 IS THE BEST", true) << endl;
    cout << "\"11110533 000102 1533 341411 04113334\": Expected: EECS 183 IS"
    << "THE BEST, Actual: " <<
    polybiusSquare(grid, "183", "11110533 000102 1533 341411 04113334", false)
    << endl;
    return;
}
