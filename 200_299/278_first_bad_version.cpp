#include <iostream>

using namespace std;


bool isBadVersion(int version) {
	return (version >= 5);
}

#define mean(a, b) ((a+b)/2)

int firstBadVersion(int n) {
	long good = 0, bad = n;

	if (!isBadVersion(n)) {
		return n;
	}

	while ((good + 1) < bad) {
		long meanVersion = mean(good, bad);
		if (isBadVersion((int) meanVersion)) {
			bad = meanVersion;
		} else {
			good = meanVersion;
		}
	}

	return ((int) bad);
}

int main() {
	cout << "first bad version: " << firstBadVersion(2126753390) << endl;

	return 0;
}