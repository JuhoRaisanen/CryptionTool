#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

unsigned char toUpper(unsigned char c); //Change char c to upperCase letter

char toChar(int a, string language); // Change int 0-28 to according char

int toNumber(unsigned char c); //Change char c to Number (0-28)

bool notSpace(unsigned char c);




int readInt(string text);

string readString(string text);





bool addChar(char c, vector<pair<char, int>> &charCounts); //Increase char c count for one in charCounts

void doChange(char c1, char c2, vector<pair<char, char>> & keys); //Change char c1 to c2 (and c2 to c1, if possible) in keys vector

typename vector<char>::iterator findChar(char c, vector<char> &chars); //Check if char c is in chars vector

typename vector<pair<char, char>>::iterator findKey(char c, vector<pair<char, char>> &keys); //Check if char c is in keys vector


int findOpposite(int number, int base);

void kantaEsitys(int number, int base);


void printAlphabet(string language);

void printAlphabet(string language, string keyWord, unsigned int a);

void printOutput(string encryptedString, vector<pair<char, char>> keys); //Decrypt and print encryptedString accoding to keys vector

#endif  