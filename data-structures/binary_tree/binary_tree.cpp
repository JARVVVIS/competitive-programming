#include<bits/stdc++.h>
using namespace std;
template <typename T>

class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data){
        //fill the value of node
        this->data=data;
        //initialise left and right branches with null pointer
        left=NULL;
        right=NULL;
    }
    ~BinaryTreeNode(){
        //deconstructer to delete node
        delete left;
        delete right;
    }

};


BinaryTreeNode<int>* takeInput(){
    int rootdata;
    cout<<"Enter data "<<endl;
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new  BinaryTreeNode<int>(rootdata);
    BinaryTreeNode<int>* leftchild= takeInput();
    BinaryTreeNode<int>* rightchild=takeInput();
    root->left=leftchild;
    root->right=rightchild;
    return root;
}


void print(BinaryTreeNode<int>* root){
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





int main(){
    BinaryTreeNode<int>* root = takeInput();
    print(root);
    delete root;
    return 0;
}