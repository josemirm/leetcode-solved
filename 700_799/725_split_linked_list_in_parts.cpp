#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode(): val(0), next(nullptr) {}
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode* next): val(x), next(next) {}
};

void printAllNodes(ListNode* first) {
	if (!first) {
		cout << "(empty)";
		return;
	}

	while (first->next) {
		cout << first->val << ", ";
		first = first->next;
	}

	cout << first->val;
}

void printNodeVector(const vector<ListNode*>& v) {
	cout << "[ ";
	
	int vecEndVal = v.size() - 1;

	for (int i=0; i<vecEndVal; ++i) {
		cout << "[";
		printAllNodes(v[i]);
		cout << "], ";
	}

	cout << "[";
	printAllNodes(v[vecEndVal]);
	cout << "] ]\n";
}

void deleteAllNodes(ListNode* first) {
	while (first) {
		ListNode* del = first;
		first = del->next;
		delete del;
	}
}

int getListLength(ListNode* head) {
	if (!head) {
		return 0;
	}

	int count = 1;

	while (head->next) {
		head = head->next;
		++count;
	}

	return count;
}

vector<ListNode*> splitListToParts(ListNode* head, int k) {
	vector<ListNode*> v;
	
	// - Special cases

	// Invalid 'k' value
	if (k < 1) {
		return v;
	}

	// Only one list
	if (k == 1) {
		v.push_back(head);
		return v;
	}

	// Null length
	int length = getListLength(head);
	if (length < 1) {
		for (int i=0; i<k; ++i) {
			v.push_back(nullptr);
		}

		return v;
	}

	// 'k' value too big
	if (k>=length) {
		for (int i=0; i<k; ++i) {
			ListNode* listStart = head;

			if (listStart) {
				head = head->next;
				listStart->next = nullptr;
			}

			v.push_back(listStart);
		}

		return v;
	}


	// - Common cases

	// List length bigger than 'k' value
	int elementsPerSplit = length / k;
	int elementsOutsideSplit = length % k;

	// Fill the rest of lists with the rest of the nodes
	for (int i=0; i<k; ++i) {
		ListNode* listStart = head;
		ListNode* listEnd = nullptr;
		int elemCount = elementsPerSplit;

		if (elementsOutsideSplit > 0) {
			++elemCount;
			--elementsOutsideSplit;
		}

		for (int elem=0; elem<elemCount; ++elem) {
			if (!head) {
				break;
			}

			listEnd = head;
			head = head->next;
		}

		if (listEnd) {
			listEnd->next = nullptr;
		}

		v.push_back(listStart);
	}

	return v;
}

int main() {
	ListNode* list1 = nullptr;
	int k1 = 5;

	ListNode* list2 = nullptr;
	int k2 = 3;

	ListNode* list3 = nullptr;
	int k3 = 3;

	ListNode** currList = &list1;
	for (int i=1; i<=3; ++i) {
		(*currList) = new ListNode(i);
		currList = &((*currList)->next);
	}

	currList = &list2;
	for (int i=1; i<=10; ++i) {
		(*currList) = new ListNode(i);
		currList = &((*currList)->next);
	}

	currList = &list3;
	for (int i=0; i<=4; ++i) {
		(*currList) = new ListNode(i);
		currList = &((*currList)->next);
	}

	cout << "list1 before: "; printAllNodes(list1); cout << endl;
	vector<ListNode*> vec1 = splitListToParts(list1, k1);
	cout << "list1 after: "; printNodeVector(vec1);
	
	cout << "list2 before: "; printAllNodes(list2); cout << endl;
	vector<ListNode*> vec2 = splitListToParts(list2, k2);
	cout << "list2 after: "; printNodeVector(vec2);

	cout << "list3 before: "; printAllNodes(list3); cout << endl;
	vector<ListNode*> vec3 = splitListToParts(list3, k3);
	cout << "list3 after: "; printNodeVector(vec3);

	for (ListNode* list: vec1) {
		deleteAllNodes(list);
	}

	for (ListNode* list: vec2) {
		deleteAllNodes(list);
	}

	for (ListNode* list: vec3) {
		deleteAllNodes(list);
	}

	return 0;
}