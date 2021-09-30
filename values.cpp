#include "values.h"


std::vector<char> getCharValues(int language) {
	
	std::vector<char> charValues;
	
	if(language == 1) {
		//Suomi
		//Define letter frequencies
		charValues.push_back('A');
		charValues.push_back('I');	
		charValues.push_back('T');	
		charValues.push_back('N');	
		charValues.push_back('E');	
		charValues.push_back('S');	
		charValues.push_back('L');	
		charValues.push_back('O');	
		charValues.push_back('K');	
		charValues.push_back('U');	
		charValues.push_back(142);	
		charValues.push_back('M');	
		charValues.push_back('V');	
		charValues.push_back('R');	
		charValues.push_back('J');	
		charValues.push_back('H');	
		charValues.push_back('Y');	
		charValues.push_back('P');	
		charValues.push_back('D');	
		charValues.push_back(153);	
		charValues.push_back('G');	
		charValues.push_back('B');	
		charValues.push_back('F');
		charValues.push_back('Z');	
		charValues.push_back('C');	
		charValues.push_back('X');	
		charValues.push_back('W');	
		charValues.push_back(143);	
		charValues.push_back('Q');	
		
	} else if (language == 0) {
		//English
		charValues.push_back('E');
		charValues.push_back('T');	
		charValues.push_back('A');	
		charValues.push_back('O');	
		charValues.push_back('I');	
		charValues.push_back('N');	
		charValues.push_back('S');	
		charValues.push_back('R');	
		charValues.push_back('H');	
		charValues.push_back('L');	
		charValues.push_back('D');	
		charValues.push_back('C');	
		charValues.push_back('U');	
		charValues.push_back('M');	
		charValues.push_back('F');	
		charValues.push_back('G');	
		charValues.push_back('P');	
		charValues.push_back('W');	
		charValues.push_back('Y');	
		charValues.push_back('B');	
		charValues.push_back('V');
		charValues.push_back('K');	
		charValues.push_back('J');	
		charValues.push_back('X');	
		charValues.push_back('Z');	
		charValues.push_back('Q');
	}
	
	return charValues;
}


		/*
		frequencies if needed
		charValues.push_back(std::pair<char, double>{'A', 11.90});
		charValues.push_back(std::pair<char, double>{'I', 10.64});	
		charValues.push_back(std::pair<char, double>{'T', 9.77});
		charValues.push_back(std::pair<char, double>{'N', 8.67});
		charValues.push_back(std::pair<char, double>{'E', 8.21});
		charValues.push_back(std::pair<char, double>{'S', 7.85});
		charValues.push_back(std::pair<char, double>{'L', 5.68});
		charValues.push_back(std::pair<char, double>{'O', 5.34});
		charValues.push_back(std::pair<char, double>{'K', 5.24});
		charValues.push_back(std::pair<char, double>{'U', 5.06});
		charValues.push_back(std::pair<char, double>{142, 4.59});
		charValues.push_back(std::pair<char, double>{'M', 3.30});
		charValues.push_back(std::pair<char, double>{'V', 2.52});
		charValues.push_back(std::pair<char, double>{'R', 2.32});
		charValues.push_back(std::pair<char, double>{'J', 1.91});
		charValues.push_back(std::pair<char, double>{'H', 1.83});
		charValues.push_back(std::pair<char, double>{'Y', 1.79});
		charValues.push_back(std::pair<char, double>{'P', 1.74});
		charValues.push_back(std::pair<char, double>{'D', 0.85});
		charValues.push_back(std::pair<char, double>{153, 0.49});
		charValues.push_back(std::pair<char, double>{'G', 0.13});
		charValues.push_back(std::pair<char, double>{'B', 0.06});
		charValues.push_back(std::pair<char, double>{'F', 0.06});	
		charValues.push_back(std::pair<char, double>{'Z', 0.05});
		charValues.push_back(std::pair<char, double>{'C', 0.04});
		charValues.push_back(std::pair<char, double>{'X', 0.03});
		charValues.push_back(std::pair<char, double>{'W', 0.01});
		charValues.push_back(std::pair<char, double>{143, 0});
		charValues.push_back(std::pair<char, double>{'Q', 0});
		*/


