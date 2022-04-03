#include <iostream>
#include <vector>

using namespace std;


string fizzBuzzItem(int n) {
	string ret;
	if ( (n % 3 == 0) && (n % 5 == 0) ) {
		ret = "FizzBuzz";
	} else if (n % 3 == 0) {
		ret = "Fizz";
	} else if (n % 5 == 0) {
		ret = "Buzz";
	} else {
		ret = to_string(n);
	}

	return ret;
}

vector<string> fizzBuzz(int n) {
	vector<string> vec;
	for (int i=1; i<=n; ++i) {
		vec.push_back(fizzBuzzItem(i));
	}

	return vec;
}


void printVector(const vector<string>& vec) {
	for (int i=0; i<(vec.size()-1); ++i) {
		cout << vec[i] << ", ";
	}

	cout << vec[vec.size()-1] << endl;
}

int main() {
	int n=3;
	cout << "n = " << n << endl;
	printVector(fizzBuzz(n));

	n=5;
	cout << "n = " << n << endl;
	printVector(fizzBuzz(n));

	n=15;
	cout << "n = " << n << endl;
	printVector(fizzBuzz(n));

	return 0;
}