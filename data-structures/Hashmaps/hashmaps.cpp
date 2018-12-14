#include<iostream>
#include <string>
using namespace std;
#include<unordered_map>

int main(){
    unordered_map<string,int> m;
    //insert
    pair<string , int> p("abc",1);
    m.insert(p);
    //another way ->
    m["def"]  = 2;

    //find or access
    cout<<m["abc"]<<endl;

    //to check presence of a key
    //count returns either 0 or 1 depending key is there or not
    m.count("ghi");


    return 0;
}