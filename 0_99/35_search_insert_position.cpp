#include <iostream>
#include <vector>

using namespace std;

#define mean(a, b) ((a+b)/2)

int searchInsert(vector<int>& nums, int target) {
	int left=0, right=nums.size(), mid=right/2;

	while ((left < mid) && (mid < right)) {
		// If finds the number, return its position
		if (nums[mid] == target) {
			return mid;
		}

		// If it doesn't, continues the binary search
		if (nums[mid] < target) {
			left = mid;
		} else {
			right = mid;
		}

		mid = mean(left, right);
	}

	// If the item of the left is bigger than the target, it should be at the left of that item, and
	// that means that the target should be in the 'left' position.
	if (nums[left] > target) {
		return left;
	}

	return right;
}

int main(void) {
	vector<int> vec = {1, 3, 5, 6};
	int target1 = 5, target2 = 2, target3 = 7, target4 = 0;

	cout << "vector: [1, 3, 5, 6]" << endl;

	cout << "target = " << target1 << " -> position " << searchInsert(vec, target1) << endl;
	cout << "target = " << target2 << " -> position " << searchInsert(vec, target2) << endl;
	cout << "target = " << target3 << " -> position " << searchInsert(vec, target3) << endl;
	cout << "target = " << target4 << " -> position " << searchInsert(vec, target4) << endl;

	return 0;
}