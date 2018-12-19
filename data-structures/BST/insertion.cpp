#include "Node.h"

Node<int>* insert(Node<int>* root , int k){
    if(root==NULL){
        Node<int>* temp = new Node<int>(k);
        return temp;
    }
    if(root->data > k )
    {
        root->left =  insert(root->left , k);
    }
    else if( root->data < k){
        root-> right = insert(root->right,k);
    }
    return root;
}




int main(){
    Node<int>* root = take_input();
    int k;
    cout<<"Enter the number"<<endl;
    cin>>k;
    insert(root,k);
    print(root);
    return 0;
}