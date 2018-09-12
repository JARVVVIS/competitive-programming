#include <bits/stdc++.h>
using namespace std;

//refer ques 16


void multiply(int *a,int no,int &next){
    int carry=0;
    for(int i=0;i<=next-1;i++){
        int product=a[i]*no+carry;
        a[i]=product%10;
        carry=product/10;
    }
    while(carry){
        a[next]=carry%10;
        carry=carry/10;
        next++;
    }
}






void power_sum(){
    int n=2;
    int power=1000;
    int next=1;
    int *arr=new int[1000]{0};
     arr[0]=1;
    while(power--){
        multiply(arr,n,next);
    }
    int sum=0;
    for(int i =next-1;i>=0;i--){
        sum+=arr[i];
    }
    cout<<sum<<endl;
}







int main() {
	power_sum();
	return 0;
}
