#include<iostream>
#include <queue>
using namespace std;
#include<cmath>
template <typename T>


class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }

};

BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter rootdata "<<endl;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
    BinaryTreeNode<int>* front =  pendingNodes.front();
    pendingNodes.pop();
    cout<<"Enter left child of "<<front->data<<endl;
    int leftChild;
    cin>>leftChild;
    if(leftChild!=-1){
        BinaryTreeNode<int>* child =  new BinaryTreeNode<int>(leftChild);
        front->left = child;
        pendingNodes.push(child);
    }
    cout<<"Enter right child of "<<front->data<<endl;
    int rightChild;
    cin>>rightChild;
    if(rightChild!=-1){
        BinaryTreeNode<int>* child =  new BinaryTreeNode<int>(rightChild);
        front->right = child;
        pendingNodes.push(child);
     }
    }
    return root;
}



void print_nodes(BinaryTreeNode<int>* root){
    if(root == NULL){
        return ;
    }
    cout<<root->data<<": ";
    if(root->left != NULL){
        cout<<"L: "<<root->left->data<<" ";
    }
    if(root->right !=NULL){
        cout<<"R: "<<root->right->data<<" ";
    }
    cout<<endl;
    print_nodes(root->left);
    print_nodes(root->right);
}

int count_nodes(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int leftCount = count_nodes(root->left);
    int rightCount = count_nodes(root->right);
    return leftCount+rightCount+1;
}

bool find_node(BinaryTreeNode<int>* root , int x){
    if(root == NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    return find_node(root->left,x) || find_node(root->right,x);
}


int height(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}

void mirror(BinaryTreeNode<int>* root){
    if(root == NULL){
        return ;

    }
    mirror(root->left);
    mirror(root->right);
    BinaryTreeNode<int>* temp = root->left;
    root->left = root->right;
    root->right = temp;
}




int main(){
    BinaryTreeNode<int>* root  = takeInput();
    print_nodes(root);
    cout<<endl<<"Total number of nodes: "<<count_nodes(root)<<endl;
    cout<<"Enter the node to be searched ";
    int x;
    cin>>x;
    cout<<find_node(root,x)<<endl;
    cout<<"Height of tree is: "<<height(root)<<endl;
    mirror(root);
    cout<<"mirrored tree is "<<endl;
    print_nodes(root);
    return 0;
}