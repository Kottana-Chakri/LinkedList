#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int val;
    Node * back;
    Node * next;
    public:
    Node(int data){
        val=data;
        back=nullptr;
        next=nullptr;
    }
        Node(int data,Node*backk){
        val=data;
        back=backk;
        next=nullptr;
    }
};
Node * DLList(vector<int> &arr){
    Node * head = new Node(arr[0]);
    Node*prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],prev);
        prev->next=temp;
        prev=prev->next;

    }
    return head;
}
Node * InsertionBeforeHead(Node * head,int data){
    Node * newhead = new Node(data);
    newhead->next=head;
    head->back = newhead;
    return newhead;
}
void print(Node*head){
    while(head!=nullptr){
        cout<<head->val<<" ";
        head=head->next;
    }
}

int main(){
    vector<int> arr={1,2,3,4};
    Node * head = DLList(arr);
    head=InsertionBeforeHead(head,10);
    print(head);
    return 0;

}