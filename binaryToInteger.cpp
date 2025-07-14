#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        vector<int> a;
        ListNode* temp = head;
        while (temp != nullptr) {
            a.push_back(temp->val);
            temp = temp->next;
        }
        int n = a.size();
        int power = 1;
        int sum = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            power *= 2;
            sum += power * a[i];
        }
        return sum;
    }
};

int main() {
    cout << "Enter binary digits (0 or 1), end with -1: ";
    int x;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    while (cin >> x && (x == 0 || x == 1)) {
        ListNode* newNode = new ListNode(x);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    if (!head) {
        cout << "No valid input provided." << endl;
        return 0;
    }

    Solution sol;
    int result = sol.getDecimalValue(head);
    cout << "Decimal value: " << result << endl;

    // Clean up linked list
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
