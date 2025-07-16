struct Node {
    int val;
    Node* next;
    Node(int data) {
        val = data;
        next = nullptr;
    }
};

class MyLinkedList {
public:
    Node* head;

    MyLinkedList() {
        head = nullptr;
    }

    int length() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    int get(int index) {
        if (index < 0 || index >= length()) return -1;
        Node* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp->val;
    }

    void addAtHead(int val) {
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
    }

    void addAtTail(int val) {
        Node* new_Node = new Node(val);
        if (head == nullptr) {
            head = new_Node;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new_Node;
        }
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > length()) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 0; i < index - 1; ++i) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= length()) return;
        if (index == 0) {
            Node* del = head;
            head = head->next;
            delete del;
        } else {
            Node* temp = head;
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
        }
    }
};
#include <iostream>
using namespace std;

int main() {
    MyLinkedList* linkedList = new MyLinkedList();

    linkedList->addAtHead(1);
    linkedList->addAtHead(2);
    linkedList->addAtHead(3);

    linkedList->addAtTail(4);

    linkedList->addAtIndex(2, 99);

    cout << "Current List: ";
    for (int i = 0; i < linkedList->length(); i++) {
        cout << linkedList->get(i) << " ";
    }
    cout << endl;

    linkedList->deleteAtIndex(2);

    cout << "After deletion: ";
    for (int i = 0; i < linkedList->length(); i++) {
        cout << linkedList->get(i) << " ";
    }
    cout << endl;

    cout << "Get index 10: " << linkedList->get(10) << endl;

    delete linkedList;
    return 0;
}
