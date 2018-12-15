//each level in a new line
#include<iostream>
#include<queue>
using namespace std;
#include "Node.h"

//using 1 queue
void level_order_1(Node<int>* root){
    queue<Node<int>*> pending_nodes;
    if(root==NULL){
        return;

    }
    pending_nodes.push(root);
    while(pending_nodes.size()!=0){
        int   node_count  = pending_nodes.size();
        while(node_count>0){
            Node<int>* front = pending_nodes.front();
            cout<<front->data<<" ";
            if(front->left!=NULL){
                pending_nodes.push(front->left);
            }
            if(front->right!=NULL){
                pending_nodes.push(front->right);
            }
            node_count--;
            pending_nodes.pop();
        }
        cout<<endl;          
    }
}



//using 2 queues
void level_order_2(Node<int>* root){
    if(root==NULL){
        return ;
    }
    queue<Node<int>*> q1;
    queue<Node<int>*> q2;
    q1.push(root);
    while(q1.size()!=0 || q2.size()!=0){  //jab tak dono empty nahi hongey
        while(q1.size()!=0){                // isme sarre odd level aayengey alternatively
            Node<int>* front = q1.front();     // phele ko bhar nikal
            cout<<front->data<<" ";             // print karwa
             if(front->left!=NULL){             // uske bachon ko dusre queue main daal

                q2.push(front->left);               
            }
            if(front->right!=NULL){
                q2.push(front->right);
            }
            q1.pop();                                //phele ko bhar nikal
        }
        cout<<endl;                                 //ab agla level dusre queue se aayega

        while(q2.size()!=0){
            Node<int>* front = q2.front();
            cout<<front->data<<" ";
            if(front->left!=NULL){            

                q1.push(front->left);               
            }
            if(front->right!=NULL){
                q1.push(front->right);
            }
            q2.pop();
        }
        cout<<endl;
    }
}

//one queue with null as demiliter
void level_order_3(Node<int>* root){
    if(root==NULL){
        return ;
    }
    queue<Node<int>*> pending_nodes;
    Node<int>* temp; //front walle ko store karne ke liye
    pending_nodes.push(root);
    pending_nodes.push(NULL);
    while(pending_nodes.size()>1) //kyunki ek toh null bhi hai isley >1 lagana padega
    {
         temp = pending_nodes.front();
         pending_nodes.pop();
         
        if(temp==NULL){
            cout<<endl;
            pending_nodes.push(NULL);
        }
        else{
                cout<<temp->data<<" ";
                if(temp->left!=NULL){
                pending_nodes.push(temp->left);
                }
                if(temp->right!=NULL){
                pending_nodes.push(temp->right);
                }
            
        }
    }
}





int main(){
    Node<int>* root = take_input();
    //level_order_1(root);
    //level_order_2(root);
    level_order_3(root);

    return 0;
}