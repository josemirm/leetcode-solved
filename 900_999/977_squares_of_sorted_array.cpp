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


vector<int> sortedSquares(vector<int>& nums) {
    vector<int> ret;
    ret.resize(nums.size());

    // Square the vector
    transform(nums.begin(), nums.end(), ret.begin(), [](int n) -> int { return n*n; });

    // Sort the vector
    sort(ret.begin(), ret.end());

    return ret;
}

int main() {
    /*
    Input: nums = [-4,-1,0,3,10]
    Output: [0,1,9,16,100]
    Explanation: After squaring, the array becomes [16,1,0,9,100].
    After sorting, it becomes [0,1,9,16,100].

    Input: nums = [-7,-3,2,3,11]
    Output: [4,9,9,49,121]
    */

    vector<int> v1 = {-4, -1, 0, 3, 10};
    vector<int> v2 = {-7, -3, 2, 3, 11};
    
    cout << "v1 before: ";
    printVector(v1);
    cout << endl;
    
    cout << "v1 after : ";
    printVector(sortedSquares(v1));
    cout << endl;
    
    cout << "v2 before: ";
    printVector(v2);
    cout << endl;
    
    cout << "v2 after : ";
    printVector(sortedSquares(v2));
    cout << endl;
    
    return 0;
}