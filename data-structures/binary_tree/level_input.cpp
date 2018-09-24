#include<bits/stdc++.h>
using namespace std;

//implement binary tree node class
class BinaryTreeNode{
    public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

BinaryTreeNode* takeinputlevel(){
    int rootdata;
    cout<<"enter root data "<<endl;
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    BinaryTreeNode *root = new BinaryTreeNode(rootdata);
    queue<BinaryTreeNode*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinaryTreeNode *frontnode = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Left child of "<<frontnode->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata !=-1){
            BinaryTreeNode *child = new BinaryTreeNode(leftdata);
            frontnode->left=child;
            pendingNodes.push(child);
        }
        cout<<"Right child of "<<frontnode->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata !=-1){
            BinaryTreeNode *child = new BinaryTreeNode(rightdata);
            frontnode->right=child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void print(BinaryTreeNode *root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<root->left->data<<",";
    }
    if(root->right!=NULL){
        cout<<root->right->data;
    }
    cout<<endl;
    print(root->left);
    print(root->right);

}







int main(){
    BinaryTreeNode *root = takeinputlevel();
    print(root);
    return 0;
}