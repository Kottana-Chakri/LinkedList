#include<bits/stdc++.h>
using namespace std;
struct Node{
    public:
    int val;
    Node* next;
    public:
    Node(int val1){
        val=val1;
        next=nullptr;
    }
};
Node * buildLList(vector<int> a){
    Node * head = new Node(a[0]);
    Node * builder=head;
    for(int i=1;i<a.size();i++){
        Node * temp=new Node(a[i]);
        builder->next=temp;
        builder=temp;
    }
    return head;
}


Node* removeElements(Node* head, int val) {
        while (head != NULL && head->val == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        Node * curr=head;
        while(curr!=NULL && curr->next!=NULL){
            if(curr->next->val==val){
                Node * dummy = curr->next;
                curr->next = curr->next->next;
                delete dummy;
            }
            else {curr=curr->next;}
        }
        return head;
    }
void print(Node * head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
}
int main(){
    vector<int> a;
    int i;
    cout << "enter a array elements : ";
    while(cin >>  i && i!=-1){
        a.push_back(i);
    }
    cin.clear();
    Node * head = buildLList(a);
    head=removeElements(head,2);
    print(head);
    return 0;
    
}