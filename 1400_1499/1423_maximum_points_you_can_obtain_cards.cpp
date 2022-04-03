#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


int getMaxAcm(const vector<int>& cardPoints, const int k) {
    int points = 0;

    for (int i = 0; i < k; ++i) {
        points += cardPoints[i];
    }
    
    int left = k - 1;
    int right = cardPoints.size() - 1;

    int temp = points;
    for (int i=0; i<k; ++i) {
        temp -= cardPoints[left--];
        temp += cardPoints[right--];

        if (temp > points) {
            points = temp;
        }
    }

    return points; 
}

// Max score you can get with the sum of 'k' amount of items getting one by one from the left, the
// right, or both sides
int maxScore(vector<int>& cardPoints, int k) {
    int size=cardPoints.size();

    // If there isn't any item available or no item to pick, return zero score points.
    if (size < 1 || k < 1) {
        return 0;
    }

    
    // If the amount of items to pick is equal or bigger than the available return the sum of all.
    if (size <= k) {
        return accumulate(cardPoints.begin(), cardPoints.end(), 0);
    }
    
    return getMaxAcm(cardPoints, k);
}


int main() {
    vector<int> vec1 = {1,2,3,4,5,6,1};
    int k1 = 3;
    // Output: 12
    
    vector<int> vec2 = {2,2,2};
    int k2 = 2;
    // Output: 4

    vector<int> vec3 = {9,7,7,9,7,7,9};
    int k3 = 7;
    // Output: 55

    vector<int> vec4 = {11,49,100,20,86,29,72};
    int k4 = 4;
    // Output: 232

    cout << "vec 1 max score: " << maxScore(vec1, k1) << endl;
    cout << "vec 2 max score: " << maxScore(vec2, k2) << endl;
    cout << "vec 3 max score: " << maxScore(vec3, k3) << endl;
    cout << "vec 4 max score: " << maxScore(vec4, k4) << endl;
}