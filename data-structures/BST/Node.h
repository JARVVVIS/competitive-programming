
#include<iostream>
#include<queue>
using namespace std;
template <typename T>


class Node{
    public:
    T data;
    Node* left;
    Node* right;

    Node(T data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    ~Node(){
        delete left;
        delete right;
    }
};



Node<int>* take_input(){
    int root_data;
    cout<<"enter root data "<<endl;
    cin>>root_data;
    if(root_data==-1){
        return NULL;
    }
    Node<int>* root = new Node<int>(root_data);
    queue<Node<int>*> pending_nodes;
    pending_nodes.push(root);
    while(pending_nodes.size()!=0){
        Node<int>* front = pending_nodes.front();
        pending_nodes.pop();
        int left_child;
        cout<<"Enter left child of "<<front->data<<endl;
        cin>>left_child;
        if(left_child!=-1){
            Node<int>* child = new Node<int>(left_child);
            front->left = child;
            pending_nodes.push(child);
        }
        int right_child;
        cout<<"Enter right child of "<<front->data<<endl;
        cin>>right_child;
        if(right_child!=-1){
            Node<int>* child = new Node<int>(right_child);
            front->right = child;
            pending_nodes.push(child);
        }
    }
        return root;
}


void print(Node<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<": ";
    if(root->left!=NULL){
        cout<<"L:"<<" "<<root->left->data<<" ";
    }
    if(root->right!=NULL){
        cout<<"R:"<<" "<<root->right->data;
    }
    cout<<endl;
    print(root->left);
    print(root->right);
}


void print_level_line(Node<int>* root){
    if(root==NULL){
        return ;
    }
    queue<Node<int>*> q1;
    queue<Node<int>*> q2;
    q1.push(root);
    while(q1.size()!=0 || q2.size()!=0){
        while(q1.size()!=0){
            Node<int>* front = q1.front();
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