#include "scripts.h"

void caesarAdd(int b, string language, string text, bool encrypt) {
	
	int eD = 1;
	if(!encrypt) {
		eD = -1;
	}
	
	int inputSize = text.length();
	int i;
	
	cout << endl;
	cout << "Result: ";
	for(i=0; i<inputSize; i++) {
		unsigned char c = text.at(i);
		
		if(notSpace(c)) {
			int a = toNumber(c);
			a += b*eD;
			
			cout << toChar(a, language);			
		} else {
			cout << c;
		}
	}
	
	cout << endl;
}

void caesarMultiple(int b, string language, string text) {
	
	int inputSize = text.length();
	int i;
	
	cout << endl;
	cout << "Result: ";
	for(i=0; i<inputSize; i++) {
		unsigned char c = text.at(i);
		
		if(notSpace(c)) {
			int a = toNumber(c);
			a *= b;
		
			cout << toChar(a, language);
		} else {
			cout << c;
		}
	}
	cout << endl;
}

void encryptAffini(int a, int b, string language, string text) {

	int inputSize = text.length();
	int i;
	
	cout << endl;
	cout << "Result: ";
	for(i=0; i<inputSize; i++) {
		unsigned char c = text.at(i);
		
		if(notSpace(c)) {
			int n = toNumber(c);
			n = n*a + b;
			
			cout << toChar(n, language);
		} else {
			cout << c;
		}
	}	
	cout << endl;	
}


void frequencyAnalysis(string language, string inputString) {
	
	vector<char> charValues;
	if(language == "1") {
		charValues = getCharValues(1);
	} else {
		charValues = getCharValues(0);
	}
	
	for_each(inputString.begin(), inputString.end(), [](char &cc) { cc = toUpper(cc); }); //Change input to upperCase letters
	cout << endl << "Input text: " << inputString << endl << endl; //Print input
	
	stringstream input(inputString); //Stringstream to handle characters of the input
	char c;
	int characters = 0; //Character count of input text
	vector<pair<char, int>> charCounts; //Count of each character in input text
	
	input >> c;
	while(input.good()) { 
				
		if(findChar(c, charValues) != charValues.end()) { //if valid character
			characters++;
			
			addChar(c, charCounts); //increase character c count in charCounts
		}
		
		input >> c;
	}
	
	auto cmp = [](pair<char, int> const &a, pair<char, int> const &b) {return a.second > b.second;}; //lambda function for sorting
	sort(charCounts.begin(), charCounts.end(), cmp); //sort charCounts to descending order
	
	
	cout << endl << endl;
	
	//Print charCounts
	int i = 0;
	for(auto & iter : charCounts) {
		cout << "Input character: " << iter.first << ", amount: " << iter.second << endl;
		i++;
	}
	
	cout << endl;
}
/*
	//Printing initial decryption
	cout << endl << "Calculating initial decryption keys... " << endl << endl;
	printOutput(inputString, decryptedChars);

	
	//Guess two-letter words of the input and change keys
	//cout << endl << "Guessing two-letter words right..." << endl;
	//checkSomeGrammar(inputString, decryptedChars, charValues, frequencies);
	
	vector<pair<char, char>> decryptedChars; //decryption keys
	auto iter = charValues.begin();
	for(auto iter2 = charCounts.begin(); iter2 != charCounts.end(); iter2++) {
		//create decryption keys by matching characters with greatest frequency to most common characters in the language
		decryptedChars.push_back(pair<char, char>{iter2->first, *iter});
		iter++;
	}
	//Print decrypted text
	printOutput(inputString, decryptedChars);
*/

void vigenere(string language, string inputString, string keyWord, bool encrypt) {

	int eD = 1;
	if(!encrypt) {
		eD = -1;
	}
	
	int w = keyWord.length();
	int inputSize = inputString.length();
	vector<int> keys;
	vector<int> input;
	
	int i;
	for(i=0; i<w; i++) {
		char c = keyWord.at(i);

		keys.push_back(toNumber(c));
	}
	
	for(i=0; i<inputSize; i++) {
		unsigned char c = inputString.at(i);

		input.push_back(toNumber(c));
	}
	
	cout << endl;
	cout << "Result: ";
	int j=0;
	for(i=0; i<inputSize; i++) {
		
		if(input.at(i) != 32) { //not space
			int a = (input.at(i) + eD*(keys.at(j)));

			cout << toChar(a, language);

			j++;
			
			if(j == w) {
				j = 0;
			}			
		} else {
			cout << " ";
		}
	}	
	cout << endl;
}