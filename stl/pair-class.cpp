#include<bits/stdc++.h>
using namespace std;


//pair class is used to link two values-> pair of height and weight

int main(){
    //pair of int and char
    pair<int,char> p;

    //declaration as well as intialization
    pair<int,char> p2(1,'a');
    p = make_pair(2,'b');
    //acessing first and second values
    cout<<p2.first<<" "<<p.first<<endl;
    

    return 0;
}