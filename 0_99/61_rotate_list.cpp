#include <iostream>
#include <vector>
#include <algorithm>

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
		cout << "(nullptr)";
		return;
	}

	while (first->next) {
		cout << first->val << ", ";
		first = first->next;
	}

	cout << first->val;
}

void deleteAllNodes(ListNode* first) {
	while (first) {
		ListNode* del = first;
		first = del->next;
		delete del;
	}
}

ListNode* rotateRight(ListNode* head, int k) {
	// - Treatment of special cases
	if (!head) {
		return nullptr;
	}

	if (!head->next) {
		return head;
	}

	if (k < 1) {
		return head;
	}

	// - Treatment of common cases
	// Get the ending node (tail) and the length of the list
	int length = 1;
	ListNode* tail = head;

	while (tail->next) {
		tail = tail->next;
		++length;
	}

	// Remove complete loops of 'k'
	if (k >= length) {
		k = k % length;
	}

	if (k == 0) {
		return head;
	}

	// Convert linear list to circular list
	tail->next = head;

	// Cut at the end
	int cuttingPoint = length - k - 1;
	ListNode* cuttingNode = head;
	for (int i=0; i<cuttingPoint; ++i) {
		cuttingNode = cuttingNode->next;
	}

	ListNode* startingPoint = cuttingNode->next;
	cuttingNode->next = nullptr;

	return startingPoint;
}


int main(void) {
	ListNode* list1 = nullptr;
	ListNode* list2 = nullptr;
	ListNode* list3 = nullptr;
	int k1 = 2, k2 = 4, k3=2;

	// Creating list 1
	ListNode** nextNode = &list1;

	for (int i=1; i<=5; ++i) {
		(*nextNode) = new ListNode(i);
		nextNode = &((**nextNode).next);
	}

	// Creating list 2
	nextNode = &list2;

	for (int i=0; i<=2; ++i) {
		(*nextNode) = new ListNode(i);
		nextNode = &((**nextNode).next);
	}
	
	// Creating list 3
	nextNode = &list3;

	for (int i=1; i<=2; ++i) {
		(*nextNode) = new ListNode(i);
		nextNode = &((**nextNode).next);
	}
	

	cout << "list1 before: "; printAllNodes(list1); cout << endl;
	cout << "list1 after: "; printAllNodes(rotateRight(list1, k1)); cout << endl;

	cout << "\nlist2 before: "; printAllNodes(list2); cout << endl;
	cout << "list2 after: "; printAllNodes(rotateRight(list2, k2)); cout << endl;

	cout << "\nlist3 before: "; printAllNodes(list3); cout << endl;
	cout << "list3 after: "; printAllNodes(rotateRight(list3, k3)); cout << endl;

	deleteAllNodes(list1);
	deleteAllNodes(list2);
	deleteAllNodes(list3);
	return 0;
}


/*
ListNode* rotateRightFirst(ListNode* head, int k) {
	if (k < 1) {
		return head;
	}

	if (head == nullptr) {
		return nullptr;
	}

	std::vector<ListNode*> v;

	ListNode* curr = head;
	while (curr) {
		v.push_back(curr);
		curr = curr->next;
	}

	int size = v.size();

	if (size < 2) {
		return head;
	}

	while (k > size) {
		k -= size;
	}

	if (k < (size / 2)) {
		// If 'k' is smaller to half of the vector, rotate right 'k' positions
		rotate(v.rbegin(), v.rbegin() + k, v.rend());
	} else {
		// If 'k' is bigger, rotate (size - k) to the left, achieving the same result with less
		// swaps.
		rotate(v.begin(), v.begin() + (size - k), v.end());
	}

	for (int i=0; i<size-1; ++i) {
		v[i]->next = v[i+1];
	}

	v[size-1]->next = nullptr;

	return v[0];
}
*/
