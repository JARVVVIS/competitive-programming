#include<iostream>
#include<vector>
using namespace std;
template <typename T>

class Node{
    public:
    //T type data
    T data;
    //a vector of Nodes (children of the node )
    vector<Node*> children;
    Node(T data){
        this->data = data;
    }
};