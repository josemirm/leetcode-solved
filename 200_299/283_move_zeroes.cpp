#include <iostream>
#include <vector>

using namespace std;


void moveZeroes(vector<int>& nums) {
	int size = nums.size();

	if (size < 2) {
		return;
	}

	int readPos=0, writePos=0, zeroCount=0;

	while ( writePos < (size - zeroCount) ) {
		while ( (readPos < size) && (nums[readPos] == 0) ) {
			++zeroCount;
			++readPos;
		}

		if (readPos >= size) {
			break;
		}

		nums[writePos++] = nums[readPos++];
	}

	while (writePos < size) {
		nums[writePos++] = 0;
	}
}

void printVec(const vector<int>& v) {
	int lastPos = v.size() - 1;
	
	for (int i=0; i<lastPos; ++i) {
		cout << v[i] << ", ";
	}
	
	cout << v[lastPos] << endl;
}

int main() {
	vector<int> v1 = {0,1,0,3,12};
	vector<int> v2 = {0,0};

	cout << "v1 before: ";
	printVec(v1);

	cout << "v1 after: ";
	moveZeroes(v1);
	printVec(v1);


	cout << "v2 before: ";
	printVec(v2);

	cout << "v2 after: ";
	moveZeroes(v2);
	printVec(v2);

	return 0;
}