#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int val1) {
        val = val1;
        next = nullptr;
    }
};

Node* buildLList(const vector<int>& a) {
    if (a.empty()) return nullptr;
    Node* head = new Node(a[0]);
    Node* builder = head;
    for (int i = 1; i < a.size(); i++) { // Start from 1 to avoid duplicating a[0]
        Node* temp = new Node(a[i]);
        builder->next = temp;
        builder = temp;
    }
    return head;
}

int length(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp) {
        temp = temp->next;
        count++;
    }
    return count;
}

bool isPresent(Node* head, int data) {
    while (head) {
        if (head->val == data)
            return true;
        head = head->next;
    }
    return false;
}


class Solution {
public:
    Node* removeNthFromEnd(Node* head, int n) {
        Node* temp = head;
        int count = 0;

        while (temp != nullptr) {
            temp = temp->next;
            count++;
        }

        int k = count - n;

        if (k == 0) {
            Node* newHead = head->next;
            delete head;
            return newHead;
        }

        temp = head;
        for (int i = 0; i < k - 1; ++i) {
            temp = temp->next;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;

        return head;
    }
};

void print(Node* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> a;
    int i;
    cout << "Enter array elements (end with -1): ";
    while (cin >> i && i != -1) {
        a.push_back(i);
    }

    Node* head = buildLList(a);
    cout << "Length of list: " << length(head) << endl;

    int num;
    cout << "Enter number to search: ";
    cin >> num;
   cout << (isPresent(head, num) ? "Present\n" : "Not Present\n");


    int n;
    cout << "Enter n (to remove nth node from end): ";
    cin >> n;

    Solution sol;
    head = sol.removeNthFromEnd(head, n); 

    cout << "Final list: ";
    print(head);

    return 0;
}
