#include <iostream>
#include <string>

using namespace std;


#define isBlankSpace(c) ( (c == ' ') || (c == '\n') || (c == '\0') || (c == '\r') || (c == '\t') )

string reverseWords(string s) {
	int len = s.length();

	if (len < 2) {
		return s;
	}

	int start=0;

	while (start < len) {

		// Find the start of the word
		while (isBlankSpace(s[start]) && start < len) {
			++start;
		}

		if ( start >= (len - 1) ) {
			break;
		}

		// Find the end
		int end = start;

		do {
			++end;
		}
		while (!isBlankSpace(s[end]) && end < len);

		int wordEnd = --end;

		while (start < end) {
			char c = s[start];
			s[start] = s[end];
			s[end] = c;

			++start;
			--end;
		}

		start = wordEnd+1;
	}

	return s;
}


int main(void) {
	string s1 = "Let's take LeetCode contest";
	string s2 = "God Ding";

	cout << "s1 before: " << s1 << "\ts1 after: " << reverseWords(s1) << endl;
	cout << "s2 before: " << s2 << "\t\ts2 after: " << reverseWords(s2) << endl;

	return 0;
}