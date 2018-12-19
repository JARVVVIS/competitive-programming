//bst is basically an extension of binary trees
//in  bst the left subtree of a node contains only nodes with data less than the parent noe
// the right subtree contains nodes with data greater than parent node

//8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1

//operations like search can be done faster
#include "Node.h"

Node<int>* search(Node<int>* root,int k){
    if(root==NULL){
        return NULL;
    }
    if(root->data==k){
        return root;
    }
    if(root->data>k){
        return search(root->left,k);
    }
    if(root->data<k){
       return  search(root->right,k);
    }

}




int main(){
    Node<int>* root = take_input(); 
    int k;
    cout<<"enter the number "<<endl;
    cin>>k;
    cout<<search(root,k);  //node with data k
}