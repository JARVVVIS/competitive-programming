#include<iostream>
using namespace std;
#include<stack>
#include "Node.h"


//alternating
void zigzag(Node<int>* root){
    if(root==NULL){
        return ;
    }
    queue<Node<int>*> q1;
    queue<Node<int>*> q2;
    q1.push(root);
    stack<Node<int>*> s;
    while(q1.size()!=0 || q2.size()!=0){
      
        while(q1.size()!=0){
            Node<int>*front = q1.front();
            cout<<front->data<<" ";
            if(front->left!=NULL){
                q2.push(front->left);

            }
            if(front->right!=NULL){
                q2.push(front->right);
            }
            q1.pop();
        }
        cout<<endl;
        while(q2.size()!=0){
            Node<int>*front = q2.front();
      
            if(front->left!=NULL){
                q1.push(front->left);

            }
            if(front->right!=NULL){
                q1.push(front->right);
            }
            s.push(front);
            q2.pop();
        }
        while(s.size()!=0){
            cout<<s.top()->data<<" ";
            s.pop();
        }
        cout<<endl;
    }
}


//after every 2
void zigzag_2(Node<int>* root){
    if(root==NULL){
        return ;
    }
    queue<Node<int>*> q;
    q.push(root);
    int i=1;
    bool reverse = false;
    stack<Node<int>*> s;
    while(q.size()!=0){
       int count_nodes=q.size();
        if(i==3){
            reverse = true;
        }
        if(i==5){
            reverse=false;
            i=1;
        }
        if(reverse){
                while(q.size()!=0){
                    s.push(q.front());
                    q.pop();
                }
                while(s.size()!=0){
                    q.push(s.top());
                    s.pop();
                }
            }

        while(count_nodes>0){
                Node<int>* front = q.front();
                cout<<front->data<<" ";
                if(front->left!=NULL){
                q.push(front->left);
                }
                if(front->right!=NULL){
                q.push(front->right);
                }
                q.pop();
                count_nodes--;
        }
        cout<<endl;
        i++;
    }
}


int main(){
    Node<int>* root = take_input();
    zigzag_2(root);
    return 0;
}


