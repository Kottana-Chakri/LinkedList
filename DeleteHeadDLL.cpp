#include<bits/stdc++.h>
using namespace std;
struct Node{
public:
    int val;
    Node* back;
    Node*next;
    public:
    Node(int data,Node*backk){
        val=data;
        back=backk;
        next=nullptr;
    }
    public:
    Node(int data){
        val=data;
        back=nullptr;
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
 Node * DeleteHead(Node*head){
    if(head==nullptr || head->next==nullptr) return nullptr;
    Node * prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;

    delete prev;
    return head;
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
    head=DeleteHead(head);
    print(head);
    return 0;

}