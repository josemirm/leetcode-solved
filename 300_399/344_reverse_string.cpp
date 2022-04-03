#include <iostream>
#include <vector>

using namespace std;


void printVector(const vector<char>& v) {
	int size = v.size();

	if (size < 1) {
		cout << " (empty) ";
		return;
	}

	for (char c: v) {
		cout << c;
	}
}


void reverseString(vector<char>& s) {
	int left=0, right=s.size()-1;

	while (left < right) {
		char c = s[left];
		s[left] = s[right];
		s[right] = c;

		++left; --right;
	}
}

int main(void) {
	vector<char> v1 = {'H', 'e', 'l', 'l', 'o'};

	cout << "before:\t"; printVector(v1);
	cout << "\nafter:\t"; reverseString(v1); printVector(v1); cout << endl;

	return 0;
}