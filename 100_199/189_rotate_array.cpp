#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void printVector(const vector<int>& vec) {
    int bigger_index = vec.size() - 1;

    for (int i=0; i<bigger_index; ++i) {
        cout << vec[i] << ", ";
    }

    cout << vec[bigger_index] << endl;
}

void rotate(vector<int>& nums, int k) {
	int size = nums.size();

	if (size < 2) {
		return;
	}

	if (k < 1) {
		return;
	}

	while (k > size) {
		k -= size;
	}

	if (k < (size / 2)) {
		// If 'k' is smaller to half of the vector, rotate right 'k' positions
		rotate(nums.rbegin(), nums.rbegin() + k, nums.rend());
	} else {
		// If 'k' is bigger, rotate (size - k) to the left, achieving the same result with less
		// swaps.
		rotate(nums.begin(), nums.begin() + (size - k), nums.end());
	}
}

int main() {

	/*
	Input: nums = [1,2,3,4,5,6,7], k = 3
	Output: [5,6,7,1,2,3,4]
	Explanation:
	rotate 1 steps to the right: [7,1,2,3,4,5,6]
	rotate 2 steps to the right: [6,7,1,2,3,4,5]
	rotate 3 steps to the right: [5,6,7,1,2,3,4]

	Input: nums = [-1,-100,3,99], k = 2
	Output: [3,99,-1,-100]
	Explanation: 
	rotate 1 steps to the right: [99,-1,-100,3]
	rotate 2 steps to the right: [3,99,-1,-100]
	*/

	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7};
	int k1 = 3;

	vector<int> v2 = {-1 ,-100, 3, 99};
	int k2 = 2;

	vector<int> v3 = {1, 2};
	int k3 = 3;

	cout << "v1 before: "; printVector(v1);
	cout << "v1 after: "; rotate(v1, k1); printVector(v1);

	cout << "\nv2 before: "; printVector(v2);
	cout << "v2 after: "; rotate(v2, k2); printVector(v2);

	cout << "\nv3 before: "; printVector(v3);
	cout << "v3 after: "; rotate(v3, k3); printVector(v3);

	return 0;
}