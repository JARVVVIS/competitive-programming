#include<bits/stdc++.h>
using namespace std;
//print a linked list in reverse order

class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
};


Node* input_linked(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1){
        Node *newnode = new Node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}


void print_rev(Node* head){
    if(head==NULL){
        return ;
    }
    print_rev(head->next);
    cout<<head->data<<" ";
}



int main(){
    Node *head=input_linked();
    print_rev(head);
    return  0;
}

