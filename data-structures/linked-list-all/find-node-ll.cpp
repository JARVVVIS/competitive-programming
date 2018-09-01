/*
Given a linked list and an integer n you need to find and return index where n is present in the LL. 
*/
#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data=data;
            this->next=next;
        }
};




Node* take_input(){
    int data;
    cin>>data;
    Node* head=NULL;
    Node *tail=NULL;
    while(data!=-1){
        Node *newnode=new Node(data);
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


int search(Node* head,int n,int i){
    if(head==NULL){
        return -1;
    }
    if(head->data==n){
        return i;
    }
    return search(head->next,n,i+1);


}





int main(){
    Node *head=take_input();
    cout<<"enter the integer to search";
    int n;
    cin>>n;
    cout<<search(head,n,0);
    return 0;
}