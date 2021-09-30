#include "functions.h"

/*

Hello and welcome!

*/

unsigned char toUpper(unsigned char c) {

	if(c >= 97 && c <= 122) { //letters a to z
		return ::toupper(c);
	} else if (c == char(132)) { //letter ä
		return char(142);
	} else if (c == char(134)) { //letter å
		return char(143);
	} else if (c == char(148)) { //letter ö
		return char(153);
	}	
	return c;
}

char toChar(int a, string language) {
	int chars = 26;
	if(language == "1") {
		chars = 29;
	}
	
	while (a < 0) {
		a += chars;
	}	
	if(a >= chars) {
		a = a % chars;
	}
	
	a += 65;
	if(a > 90) { //å, ä, ö
		if(a == 91) {
			a = 143;
		} else if (a == 92) {
			a = 142;
		} else if (a == 93) {
			a = 153;
		}			
	}	
	return (char) a;
}

int toNumber(unsigned char c) {
	if(!notSpace(c)) {
		return 32;
	}
	
	c = toUpper(c);
	
	int a = (int) c;
	if(a > 90) {
		if(a == 143) {
			a = 91;
		} else if (a == 142) {
			a = 92;
		} else if (a == 153) {
			a = 93;
		}			
	}	
	a = a - 65;
	return a;
}

bool notSpace(unsigned char c) {
	if(c == 32) {
		return false;
	}
	return true;
}










int readInt(string text) {
	
	int result = 0;
	cout << text;
	
	string luku;
	getline(cin, luku);
	if(cin.good()) {
		stringstream ss(luku);		
		ss >> result;
	}
	
	return result;
}

string readString(string text) {
	
	cout << text;
	string temp, result;
	
	while (getline(cin, temp)){

		result += temp;
	}
	
	
	/*
		getline(cin, inputString);
	while (inputString.length() == 0) {
		getline(cin, inputString);
	}
	*/
	
	return result;
}










bool addChar(char c, vector<pair<char, int>> &charCounts) {
	for(auto & pair : charCounts) { //check if character c exists in charCounts, and increase it by one
		if(pair.first == c) {
			pair.second += 1;
			return true;
		}			
	}
	
	charCounts.push_back(pair<char, int>{c, 1}); //if doesn't exists, create new pair
	return true;
}

void doChange(char c1, char c2, vector<pair<char, char>> & keys) {
	//change character c1 in keys to char c2
	char changedElem;
	auto elem = findKey(c1, keys);
	changedElem = elem->first;
	elem->second = c2;
	cout << "Changed " << c1 << " to " << elem->second << endl;						
	
	for(auto & elem2 : keys) {
		if(elem2.second == c2 && elem2.first != changedElem) { //change character c2 to c1, but don't change the same char than above
			elem2.second = c1;
			cout << "Changed " << c2 << " to " << elem2.second << endl;
		}
	}	
}


typename vector<char>::iterator findChar(char c, vector<char> &chars) { //find if char c exists in vector chars
	typename vector<char>::iterator search = find_if(chars.begin(), chars.end(), [&c](const char & elem) { 
																											if(elem == c) 
																												return true;
																											return false; 
																											});
																											
	return search;
}

typename vector<pair<char, char>>::iterator findKey(char c, vector<pair<char, char>> &keys) { //find if char c exists in vector keys
	typename vector<pair<char, char>>::iterator search = find_if(keys.begin(), keys.end(), [&c](const pair<char, char> & elem) { 
																											if(elem.second == c)
																												return true;
																											return false; 
																											});
																											
	return search;	
}







int findOpposite(int number, int base) {
	
	if(number == 1) {
		return 1;
	}
	
	int i;
	for(i=2; i<base; i++) {
		if((i * number) % base == 1) {
			return i;
		}
	}
	
	return -1;
}

void kantaEsitys(int number, int base) {
	
	cout << number << " = ";
	int k = 0; 
	
	int i;
	for(i = 1; i < 32; i++) {
		if(pow(base, i) > number) {
			break;
		} else {
			k++;
		}		
	}
	
	for(i = k; i > 0; i--) {		
		int a = number / pow(base, i);
		cout << a << "*" << base << "^" << i << " + ";
		
		number = number - (pow(base, i)*a);
	}
	
	cout << number << endl;
}








void printAlphabet(string language) {
	cout << endl;
	
	int chars = 26;
	int i;
	if(language == "1") {
		chars = 29;
	}
	
	for(i = 0; i < chars; i++) {
		printf("%*d ", 3, i);
	}
	cout << endl;
	
	for(i = 0; i < 26; i++) {
		printf("%*c ", 3, i+65);
	}
	if(language == "1") {
		printf("%*c ", 3, 143);
		printf("%*c ", 3, 142);
		printf("%*c ", 3, 153);
	}
	cout << endl;
	cout << endl;
}


void printAlphabet(string language, string keyWord, unsigned int a) {
	cout << endl;
	
	unsigned int chars = 26;
	unsigned int i, j;
	if(language == "1") {
		chars = 29;
	}
	
	vector<char> word;
	vector<char> table;
	vector<char> result;
	
	for(i=0; i<keyWord.length(); i++) {
		char c = keyWord.at(i);
		c = toUpper(c);
		bool charNotFound = true;
		for(j=0; j<word.size(); j++) {
			if(word.at(j) == c) {
				charNotFound = false;
				continue;
			}
		}
		
		if(charNotFound) {
			word.push_back(c);
		}
	}
	
	for(i = 0; i < chars; i++) {
		char c = toChar(i, language);
		bool charNotFound = true;
		
		for(j=0; j<word.size(); j++) {
			if(word.at(j) == c) {
				charNotFound = false;
				continue;
			}
		}	
		
		if(charNotFound) {
			table.push_back(c);
		}
	}
	
	for(i=0; i<a; i++) {
		result.push_back(table.at(table.size()- a + i));
	}
	for(i=0; i < word.size(); i++) {
		result.push_back(word.at(i));
	}
	for(i=0; i<table.size() - a; i++) {
		result.push_back(table.at(i));
	}
	
	for(i = 0; i < chars; i++) {
		printf("%*d ", 3, i);
	}
	cout << endl;
	
	for(i = 0; i < chars; i++) {
		printf("%*c ", 3, result.at(i));
	}

	cout << endl;
	cout << endl;
}



void printOutput(string encryptedString, vector<pair<char, char>> keys) {
	stringstream output;
	for(unsigned int i = 0; i < encryptedString.length(); i++) { //change all the characters to the matching keys
		char cc = encryptedString.at(i);
		bool found = false;
		for(auto iter = keys.begin(); iter != keys.end(); iter++) {
			if(iter->first == cc) {
				output << iter->second;
				found = true;
				continue;
			}
		}
		
		if(!found) {
			output << cc;
		}
	}

	cout << "Decrypted string: " << output.str() << endl;	//pring output
}







