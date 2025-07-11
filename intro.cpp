#include<bits/stdc++.h>
using namespace std;
struct Node{
    public:
    int val;
    Node * next;

    public:
    Node(int val0,Node* val1){
        val=val0;
        next=val1;
    }
};
class Solution{

};
int main(){
    //Node x = Node(2,nullptr);
    //cout << x.val << endl;
    Node* x = new Node(2,nullptr);
    cout << x->val << endl;
    return 0;
}