#include "values.h"
#include "scripts.h"
#include "functions.h"
#include <iostream>
#include <string>
#include <sstream>
#include <clocale>
#include <vector>


using namespace std;

//Guess two-letter words of the input and change keys --------------- working, only charValues vector need to change
//void checkSomeGrammar(string encryptedString, vector<pair<char, char>> & keys, vector<pair<char, double>> charValues, vector<pair<char, double>> frequencies);


int main() {
	
	setlocale(LC_ALL, "utf-8");
	
	cout << endl << "Welcome to use the KoodinMurtaja (encryption & decryption tool)!" << endl << endl;
	
	//Get input
	string language = readString("Select input language (0=English, 1=Finnish) > ");	
	if(language == "1") {
		cout << "Finnish selected" << endl;
	} else {
		language = "0";
		cout << "English selected" << endl << endl;
	}

	bool encryption = false;
	string inputString;
	string enc = readString("Using crypted (0) or plain (1) text? > ");
	cout << endl;
	if(enc == "1") {
		encryption = true;
		inputString = readString("Give plain text > ");
	} else {
		encryption = false;
		inputString = readString("Give encrypted input text > ");
	}

	
	//Loop, where user can change characters of the text
	while (true) {
		cout << endl << endl;
		cout << "**********************************************************************************************" << endl;
		cout << "Commands: <analysis> <affini> <caesar> <vigenere> <table> <congruence> <base> <restart> <quit>" << endl;
		cout << "-> ";
		string s;
		
		//User input
		getline(cin, s);
		while (s.length() == 0) {
			getline(cin, s);
		}
		
		if(s == "quit") {
			break;
			
		} 
		else if(s == "analysis") {
			frequencyAnalysis(language, inputString);
			
		} 
		else if (s == "affini") {
			int a = readInt("Give a-value > ");
			int b = readInt("Give b-value > ");

			encryptAffini(a, b, language, inputString);		
		}
		else if(s == "caesar") {
			cout << "Caesar" << endl;
			string method = readString("Select method: (0=addition, 1=multiplication) > ");
			int b = readInt("Give n-value: (1-28) > ");
			
			if(method == "1") {
				caesarMultiple(b, language, inputString);
			} else {
				caesarAdd(b, language, inputString, encryption);
			}
		} 
		else if(s == "vigenere") {
	
			string keyWord = readString("Give the keyWord >");			
			vigenere(language, inputString, keyWord, encryption);				
		}
		else if (s == "table") {
			int a = 0;
			string input = readString("Give keyWord (optional) > ");
			if(!input.empty()) {
				a = readInt("Give n-value: (0-28) > ");
			}			
			printAlphabet(language, input, a);
		}
		else if(s == "congruence") {
			cout << "Calculate an opposite of an congruence class" << endl;
			
			int a = readInt("Give an congruence class (integer) >");
			int base = readInt("Give a base (optional) >");
			if(base == 0) {
				base = 26;
			}
			int result = findOpposite(a, base);
			
			if(result == -1) {
				cout << "No result" << endl;
			} else {
				cout << "Result: " << result << " (" << a << "*" << result << " = 1 (mod " << base << ")) " << endl;
			}			
		}
		else if (s == "base") {
			
			int a = readInt("Give a number >");
			int b = readInt("Give a base >");
			kantaEsitys(a, b);
		}
		else if (s == "restart") {
			cout << endl << endl << "Restarting...." << endl;
			language = readString("Select input language (0=English, 1=Finnish) > ");	
			if(language == "1") {
				cout << "Finnish selected" << endl;
			} else {
				language = "0";
				cout << "English selected" << endl << endl;
			}

			enc = readString("Using crypted (0) or plain (1) text? > ");
			cout << endl;
			if(enc == "1") {
				encryption = true;
				inputString = readString("Give plain text > ");
			} else {
				encryption = false;
				inputString = readString("Give encrypted input text > ");
			}			
		}
		else if(s == "finish") {
			/*
			//Print decryption key and output text
			cout << endl << "Full decryption key: " << endl;
			for(auto & key : decryptedChars) {
				cout << "Input letter: " << key.first << ", Decrypted: " << key.second << endl;
			}
			
			cout << endl;
			printOutput(inputString, decryptedChars); 
			break;
			*/
		} 
		else {
			/*
			stringstream inputStream(s);
			char c1, c2, equal; //if user input is 'A=B', c1=A, c2=B and equal = '='.
			bool changeSuccess = false;
			inputStream >> c1;
			
			if(inputStream.good())
				c1 = toUpper(c1);
			
			inputStream >> equal;
			if(inputStream.good()) {
				if(equal == '=') {
					inputStream >> c2;
					if(inputStream.good()) {
						c2 = toUpper(c2);
						
						//check that c1 and c2 are valid letters
						if(findKey(c1, decryptedChars) != decryptedChars.end() && findChar(c2, charValues) != charValues.end()) {
							doChange(c1, c2, decryptedChars);
							changeSuccess = true;
						}
					}
				}
			}
			
			if(!changeSuccess) { //if didn't change anything, print some error
				cout << "Change attempt failed" << endl;
			} else {
				printOutput(inputString, decryptedChars); //print the text with updated keys
			}
*/			
		}
			
	}
	
	return 0;
}



/*
void checkSomeGrammar(string encryptedString, vector<pair<char, char>> & keys, vector<pair<char, double>> charValues, vector<pair<char, double>> frequencies) {
	
	//2-letter words
	vector<pair<string, int>> wordCounts; //count of different 2-letter words
	int wordLength = 0;
	
	for(unsigned int i = 0; i < encryptedString.length(); i++) {
		char c = encryptedString.at(i);
		
		if(c == ' ' || c == '.' || c == ',') { //if encoutered space between words, save 2-letter words
			if(wordLength == 2) {
				string word = encryptedString.substr(i-2, 2);
				bool found = false;
				for(auto & w : wordCounts) { //if word already exists in wordCounts
					if(w.first == word) {
						w.second++;
						found = true;
						continue;
					}
				}
				
				if(!found) { //create new pair if word doesn't exist
					wordCounts.push_back(pair<string, int>{word, 1});
				}
			}			
			wordLength = 0;
			
		} else {
			wordLength++;
		}
	}
	
	
	cout << endl << "Two-letter word counts: " << endl;
	if(wordCounts.size() > 0) {
		
		vector<double> valuesJA;
		vector<double> valuesON;
		
		for(auto & w : wordCounts) { //iterate through all the words and calculate probabilities for words 'JA' and 'ON'
			char c1 = w.first.at(0);
			char c2 = w.first.at(1);
			
			double valueJA = 0;
			double valueON = 0;
			
			//Calculate word "JA" probability (lower is better)	
			auto iter1 = findChar(c1, frequencies);
			auto iter2 = findChar(c2, frequencies);
			auto iter3 = findChar('J', charValues);
			auto iter4 = findChar('A', charValues);
			
			if(iter1 != frequencies.end() && iter2 != frequencies.end()) {
				valueJA = abs((iter1->second * 100) - iter3->second) + abs((iter2->second * 100) - iter4->second);
				valuesJA.push_back(valueJA);
			}
			
			//Calculate word "ON" probability (lower is better)
			iter3 = findChar('O', charValues);
			iter4 = findChar('N', charValues);
			
			if(iter1 != frequencies.end() && iter2 != frequencies.end()) {
				valueON = abs((iter1->second * 100) - iter3->second) + abs((iter2->second * 100) - iter4->second);
				valuesON.push_back(valueON);
			}
			
			cout << w.first << ": " << w.second << ", value ON: " << valueON << ", value JA: " << valueJA << endl;		
		}
		
		unsigned int smallestIndex_JA = 0;
		unsigned int smallestIndex_ON = 0;
		for(unsigned int i = 1; i < valuesJA.size(); i++) { //find words with best JA -value
			if(valuesJA[i] < valuesJA[smallestIndex_JA]) {
				smallestIndex_JA = i;
			}
		}
		for(unsigned int i = 1; i < valuesON.size(); i++) { //find words with best ON -value
			if(valuesON[i] < valuesON[smallestIndex_ON]) {
				smallestIndex_ON = i;
			}
		}
		
		for(unsigned int i = 0; i < wordCounts.size(); i++) { //Change words with best JA and ON values
				
			if(i == smallestIndex_JA) {
				string w = wordCounts[i].first;
				char c1 = w.at(0);
				char c2 = w.at(1);
				
				auto iter1 = findChar(c1, keys);
				auto iter2 = findChar(c2, keys);
				
				cout << "Change word " << w << " to JA" << endl;
				doChange(iter1->second, 'J', keys);
				doChange(iter2->second, 'A', keys);
				
			} else if (i == smallestIndex_ON) {
				string w = wordCounts[i].first;
				char c1 = w.at(0);
				char c2 = w.at(1);
				
				auto iter1 = findChar(c1, keys);
				auto iter2 = findChar(c2, keys);
				
				cout << "Change word " << w << " to ON" << endl;
				doChange(iter1->second, 'O', keys);
				doChange(iter2->second, 'N', keys);				
			}			
		}
	}
}
*/
















