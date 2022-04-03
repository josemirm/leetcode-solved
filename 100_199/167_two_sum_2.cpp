#include <iostream>
#include <vector>

using namespace std;


void printVec(const vector<int>& v) {
	if (v.size() < 1) {
		cout << " (void) ";
		return;
	}

	int lastPos = v.size() - 1;
	
	for (int i=0; i<lastPos; ++i) {
		cout << v[i] << ", ";
	}
	
	cout << v[lastPos] << endl;
}


vector<int> twoSum(vector<int>& numbers, int target) {
	vector<int> sumPos;

	int minPos=0, maxPos=numbers.size() - 1;

	while (minPos < maxPos) {
		int sum = numbers[minPos] + numbers[maxPos];
		if (sum == target) {
			sumPos.push_back(minPos + 1);
			sumPos.push_back(maxPos + 1);

			return sumPos;
		}

		if (sum < target) {
			++minPos;
		} else {
			--maxPos;
		}
	}

	return sumPos;
}

int main() {
	vector<int> v1 = {2,7,11,15};
	vector<int> v2 = {2,3,4};
	vector<int> v3 = {-1,0};
	vector<int> v4 = {-3,3,4,90};

	int t1 = 9, t2 = 6, t3 = -1, t4 = 0;

	cout << "target 1: " << t1 << ", v1: "; printVec(v1);
	cout << "sum positions: "; printVec(twoSum(v1, t1));

	cout << "\ntarget 2: " << t2 << ", v2: "; printVec(v2);	
	cout << "sum positions: "; printVec(twoSum(v2, t2));
	
	cout << "\ntarget 3: " << t3 << ", v3: "; printVec(v3);
	cout << "sum positions: "; printVec(twoSum(v3, t3));

	cout << "\ntarget 4: " << t4 << ", v4: "; printVec(v4);
	cout << "sum positions: "; printVec(twoSum(v4, t4));

	return 0;
}