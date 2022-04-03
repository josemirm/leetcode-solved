#include <iostream>
#include <vector>

using namespace std;

int minimumDeletions(vector<int>& nums) {
	// minimunDeletiums: Counts the minimun elements necessary to delete from the left or from the
	// right to remove the minimun and the maximum

	int size=nums.size(), min, max, minPos, maxPos;

	// For cases where there are only zero or one elements
	if (size < 2) {
		return size;
	}

	// Rest of cases
	minPos = maxPos = 0;
	min = max = nums[0];

	for (int i=1; i<size; ++i) {
		if (nums[i] < min) {
			minPos = i;
			min = nums[i];
		}

		if (nums[i] > max) {
			maxPos = i;
			max = nums[i];
		}
	}

	int left, right;
	if (minPos < maxPos) {
		left = minPos;
		right = maxPos;
	} else {
		left = maxPos;
		right = minPos;
	}

	// There are three options to pick the minimum elements to delete
	int opt[3];

	// Option 1: Removing from the left until finding the right value
	opt[0] = right + 1;

	// Option 2: Removing from the right until finding the left value
	opt[1] = size - left;

	// Option 3: Removing from left until finding the left value, and from the right until finding
	// the right value.
	opt[2] = (left + 1) + (size - right);

	// Picks the minimun
	int toDelete = opt[0];

	for (int i=1; i<3; ++i) {
		if (toDelete > opt[i]) {
			toDelete = opt[i];
		}
	}

	return toDelete;
}

int main() {
	vector<int> v1 = {2,10,7,5,4,1,8,6};
	cout << "vector v1 min. deletions: " << minimumDeletions(v1) << endl;
	// Output: 5
	
	vector<int> v2 = {0,-4,19,1,8,-2,-3,5};
	cout << "vector v2 min. deletions: " << minimumDeletions(v2) << endl;
	// Output: 3

	vector<int> v3 = {101};
	cout << "vector v3 min. deletions: " << minimumDeletions(v3) << endl;
	// Output: 1

	vector<int> v4 = {-1,-53,93,-42,37,94,97,82,46,42,-99,56,-76,-66,-67,-13,10,66,85,-28};
	cout << "vector v4 min. deletions: " << minimumDeletions(v4) << endl;
	// Output: 11

	return 0;
}