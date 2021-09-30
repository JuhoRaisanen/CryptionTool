#ifndef SCRIPTS_H
#define SCRIPTS_H
#include <vector>
#include <string>
#include <utility>
#include <cmath>
#include <algorithm>
#include "functions.h"
#include "values.h"

using namespace std;

void caesarAdd(int b, string language, string text, bool encrypt);

void caesarMultiple(int b, string language, string text);

void encryptAffini(int a, int b, string language, string text);

void frequencyAnalysis(string language, string inputString);

void vigenere(string language, string inputString, string keyWord, bool encrypt);

#endif