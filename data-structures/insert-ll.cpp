#include<bits/stdc++.h>
using namespace std;



class Node{
    public:
        int data;
        Node *next;
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

Node* insert_rec(Node* head,int data,int i){
    if(head==NULL){
        return;
    }

    if(i==0){
        Node *newnode=new Node(data);
        newnode->next=head;
        return newnode;
    }
    head->next=insert_rec(head->next,data,i-1);
    return head;
}




int main(){
    Node *head = input_linked();
    int data,i;
    cout<<"enter the data,index to insert"<<endl;
    cin>>data>>i;
    head=insert_rec(head,data,i);
    return 0;
}