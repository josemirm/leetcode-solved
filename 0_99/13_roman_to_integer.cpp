#include <iostream>

using namespace std;

int romanSymbolValue(char c) {
	switch (tolower(c)) {
		case 'i':
			return 1;
			break;
		
		case 'v':
			return 5;
			break;
		
		case 'x':
			return 10;
			break;
		
		case 'l':
			return 50;
			break;
		
		case 'c':
			return 100;
			break;
		
		case 'd':
			return 500;
			break;
		
		case 'm':
			return 1000;
			break;
		
		case '\0':
			return 0;
			break;
		default:
			cerr << "Not valid number\n";
			return 0;
	}
}

int romanToInt(string s) {
	int length = s.length();
	
	if (length < 1) {
		cerr << "Not valid string\n";
		return 0;
	}
	
	int count = 0;
	int firstVal = romanSymbolValue(s[0]);
	for (int i=0; i<length; ++i) {
		int secondVal = romanSymbolValue(s[i+1]);

		if (firstVal < secondVal) {
			count += (secondVal - firstVal);
			firstVal = romanSymbolValue(s[i+2]);
			++i;
		} else {
			count += firstVal;
			firstVal = secondVal;
		}
	}

	return count;
}

int main(int argc, char const *argv[]) {
	if (argc == 2) {
		cout << "Arabic numbers: " << romanToInt(string(argv[1])) << endl;
		return 0;
	}

	string input;
	cout << "Roman numbers:\n";
	cin >> input;
	cout << "Arabic numbers: " << romanToInt(input) << endl;
	return 0;
}