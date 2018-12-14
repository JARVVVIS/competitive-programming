//postorder traversal


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


void postorder(Node<int>* root){
    if(root==NULL){
        return ;

    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}


int main(){
    Node<int>* root = take_input();
    postorder(root);

    return 0;
}