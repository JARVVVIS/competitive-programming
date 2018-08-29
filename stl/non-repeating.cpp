/*
In a given string, find the first 
non-repeating character .You are given a string,
that can contain repeating characters.
Your task is to return the first character in this string that does not repeat. i.e., occurs
exactly once. The string will contain characters
only from English alphabet set, i.e., ('A' - 'Z') and ('a' - 'z')
If there is no non-repeating 
character print the first character of string.
*/


#include<bits/stdc++.h>
using namespace std;


char nonRepeat(string str){
    map<char,int> m;
    for(int i=0;i<str.size();i++){
        m[str[i]]++;
    }
    for (int i=0;i<str.size();i++){
        if(m[str[i]]==1){
            return str[i];
        }
    }
    return str[0];
}



int main(){
    string s;
    cin>>s;
    cout<<nonRepeat(s);
    return 0;
}