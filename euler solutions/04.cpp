#include<bits/stdc++.h>
using namespace std;



bool checkPal(int num){
    int temp=num;
    int reverse=0,rem=0;
    while(num!=0){
        rem=num%10;
        reverse=reverse*10+rem;
        num=num/10;
    }
    return reverse==temp;
}





int main(){
    int max=0;
    for(int i=999;i>100;i--){
        for(int j=999;j>100;j--){
            int product=i*j;
            if(checkPal(product) && product>max){
                max=product;
            }
        }
    }
    cout<<max;
    return 0;

}