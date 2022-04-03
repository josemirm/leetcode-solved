#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


bool isPalindrome(ListNode* head) {
    if (nullptr == head) {
        return false;
    }

    vector<ListNode*> nodes;
    ListNode* current = head;

    while (current) {
        nodes.push_back(current);
        current = current->next;
    }

    int i=0, j=(nodes.size()-1);

    while (i<j) {
        if (nodes[i]->val != nodes[j]->val) {
            return false;
        }

        i++;
        j--;
    }

    return true;
}

int main() {
    ListNode list1[3];
    
    list1[0].val = 1;
    list1[0].next = &list1[1];

    list1[1].val = 2;
    list1[1].next = &list1[2];

    list1[2].val = 3;
    list1[2].next = nullptr;
    

    ListNode list2[4];

    list2[0].val = 1;
    list2[0].next = &list2[1];

    list2[1].val = 2;
    list2[1].next = &list2[2];

    list2[2].val = 2;
    list2[2].next = &list2[3];

    list2[3].val = 1;
    list2[3].next = nullptr;

    cout << "is 'a' palindrome?: " << (isPalindrome(&list1[0])? "yes": "no") << endl;
    cout << "is 'b' palindrome?: " << (isPalindrome(&list2[0])? "yes": "no") << endl;

    return 0;
}