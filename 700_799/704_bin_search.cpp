#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int>& vec) {
    int size = vec.size();
    cout << "[";
    for (int i=0; i<(size-1); ++i) {
        cout << vec[i] << ", ";
    }
    cout << vec[size - 1] << "]\n";
}

#define mean(a, b) ((a+b)/2)

int search(vector<int>& nums, int target) {
        if (nums.size() < 1) {
            return -1;
        }

        int left = 0, right = nums.size(), mid = right/2;
        while (left < right) {
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target) {
                if (left == mid) {
                    return -1;
                }

                left = mid;
            } else {
                if (right == mid) {
                    return -1;
                }
                right = mid;
            }

            mid = mean(left, right);
        }
        
        return -1;
}

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    print_vector(nums);

    cout << "Search '12': " << search(nums, 12) << endl;

}