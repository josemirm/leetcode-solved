#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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

void deleteAllNodes(ListNode* first) {
	while (first) {
		ListNode* del = first;
		first = del->next;
		delete del;
	}
}


ListNode* oddEvenList(ListNode* head) {
	// If there are less than three elements, there isn't any need to reorder them.
	if (!head || !(head->next) || !(head->next->next)) {
		return head;
	}

	ListNode *prevOdd=head, *firstOdd=head;
	ListNode *prevEven=head->next, *firstEven=head->next;

	head = prevEven->next;

	while (head) {
		prevOdd->next = head;
		head = head->next;
		prevOdd = prevOdd->next;

		if (!head) {
			break;
		}

		prevEven->next = head;
		head = head->next;
		prevEven = prevEven->next;
	}

	prevOdd->next = firstEven;
	prevEven->next = nullptr;

	return firstOdd;
}

int main(void) {
	ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4,
					new ListNode(5)))));

	ListNode* l2 = new ListNode(2, new ListNode(1, new ListNode(3, new ListNode(5, new ListNode(6,
					new ListNode(4, new ListNode(7)))))));

	cout << "List 1 before:\t"; printAllNodes(l1); cout << endl;
	cout << "List 1 after:\t"; printAllNodes(oddEvenList(l1)); cout << endl;

	cout << "List 2 before:\t"; printAllNodes(l2); cout << endl;
	cout << "List 2 after:\t"; printAllNodes(oddEvenList(l2)); cout << endl;

	deleteAllNodes(l1);
	deleteAllNodes(l2);

	return 0;
}