/*
Given a linked list and a position i,
delete the node of ith position from Linked List iteratively.
If position i is greater than length of LL, then you should return 
the same LL without any change.
*/

#include<bits/stdc++.h>
using namespace std;

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

void print(Node *head){
    while(head!=NULL){
            cout<<head->data<<" ";
            head=head->next;
    }
}



Node* delete_linked(Node *head,int i){
    if(i==0){
        head=head->next;
        return head;
    }
    Node *temp1=head;
    Node *temp2=head;
    int count=0;
    while(temp1!=NULL && count<i+1){
        temp1=temp1->next;
        count++;
    }
    count=0;
    while(count<i-1){
        temp2=temp2->next;
        count++;
    }
    temp2->next=temp1;
    return head;

}




int main(){
    //first we will take input of linked list
    Node *head = input_linked();
    print(head);
    cout<<endl;
    cout<<"enter what index would u like to delete";
    int i;
    cin>>i;
    head=delete_linked(head,i);
    print(head);
    return 0;
}