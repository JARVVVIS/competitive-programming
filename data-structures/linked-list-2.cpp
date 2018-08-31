//taking input of a linked list 

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



Node* input_node(){
    int data;
    cin>>data;
    //we will input the linked list until user gives -1
    Node *head=NULL;
    Node *tail =NULL;
    while(data!=-1){
        //some value has to entered as user has not entered -1
        //initialise a node
        Node *newnode=new Node(data);
        if(head==NULL){
            //will work only in first run
            //head is initialised and fixed now
            head = newnode;
            tail = newnode;
        }
        else{
            //update address
            tail->next=newnode;
            //update tail pointer so it is always at last
            tail=tail->next;
        
        }
        //take input for next node
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




int main(){
    //the input function will only return us the head of the given linked list 
    //we can access all properties of linked list using the head only
    Node *head=input_node();
    print(head);
    return 0;
}