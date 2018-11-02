#include<iostream>
#include "Node.h"
using namespace std;


Node<int>* takeInput(){
    int rootData;
    cout<<"Enter data: "<<endl;
    cin>>rootData;
    Node<int>* root = new Node<int>(rootData);

    int n;
    cout<<"enter number of children of "<<rootData<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        Node<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}






void print_tree(Node<int>* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data <<":";
    for(int i=0;i<root->children.size();i++){
        cout<< root->children[i]->data << ",";

    }
    cout<<endl;

    for(int i=0;i<root->children.size();i++){
        print_tree(root->children[i]);
    }
}





int main(){
    Node<int>* root = takeInput();
    print_tree(root);


    return 0;
}