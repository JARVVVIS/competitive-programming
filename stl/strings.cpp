#include<bits/stdc++.h>
using namespace std;

int main(){
    // strings are basically character arrays 
    //declare
    string s ="ruchit";
    //print
    cout<<s<<endl;
    //copies s in t
    string t(s);
    cout<<t<<endl;
    //starts from 2 and takes next 4 characters and make a substring
    string k(s,2,4);
    cout<<k<<endl;
    
    //substring
    //starts from 1 to next 4 character
    string s2=s.substr(1,4);
    cout<<s2<<endl;


    return 0;
}