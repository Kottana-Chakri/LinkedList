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
    for(int i=0;i<a.size();i++){
        Node * temp=new Node(a[i]);
        builder->next=temp;
        builder=temp;
    }
    return head;
}
int length(Node * head){
    int count=0;
    Node*temp=head;
    while(temp){
        temp=temp->next;
        count++;
    }
    return count;

}
int isPresent(Node*head,int data){
    Node*temp=head;
    while(temp){
        if(temp->val==data)
            return 1;
        temp=temp->next;
    }
    return 0;
}

int main(){
    vector<int> a;
    int i;
    cout << "enter a array elements : ";
    while(cin >>  i){
        a.push_back(i);
    }
    cin.clear();
    Node * head = buildLList(a);
    cout<< length(head)<<endl;
    int num;
    cout << "enter a num : ";
    cin >> num;
    cout<< isPresent(head,num);
    
}