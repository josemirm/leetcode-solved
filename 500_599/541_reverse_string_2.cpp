#include <iostream>
#include <string>

using namespace std;


string reverseStr(string s, int k) {
	int len = s.length();

	if ( (len < 1) || (k < 1) ) {
		return s;
	}

	for (int i=0; i<len; i += 2*k) {
		int start=i, end=i+k-1;

		if (end >= len) {
			end = len-1;
		}

		while (start < end) {
			char c = s[start];
			s[start] = s[end];
			s[end] = c;
			++start;
			--end;
		}
	}

	return s;
}

int main(void) {
	string s1 = "abcdefg";
	string s2 = "abcd";
	int k1=2, k2=2;

	cout << "s1 before: " << s1 << "\ts1 after: " << reverseStr(s1, k1) << endl;
	cout << "s2 before: " << s2 << "\t\ts2 after: " << reverseStr(s2, k2) << endl;
	
	return 0;
}