#include<iostream>
#include<cmath>
using namespace std;

#include<iostream>
using namespace std;

class Fraction {
    public:
    int numerator;
    int denominator;
    //constructer to grab values
    Fraction(int n , int d){
        numerator = n;
        denominator = d;
    }
    void print(){
        cout<<this->numerator<<" "<<this->denominator<<" ";
    }
    int g(int a ,int b){
    if(a<b){
        return g(b,a);
    } 
    if (b == 0){
        return a;
    } 
    return g(b, a % b); 
    }


    void simplify(){
        int gcd = g(numerator,denominator);
        this->numerator = this->numerator/gcd;
        this->denominator = this->denominator/gcd;

    }
    void add(Fraction f2){
        int lcm = this->denominator*f2.denominator;
        int x = lcm/denominator;
        int y = lcm/f2.denominator;

        int num = x*numerator+y*f2.numerator;
        int den = lcm;

        this->numerator = num;
        this->denominator = den;

    }
    void devide(int a , int b){
        numerator = numerator*b;
        denominator = denominator*a;
    

    }
    void power(int folds){
        this->denominator = pow(4,folds);
    }
    void subtract(Fraction f2){
        int lcm = this->denominator*f2.denominator;
        int x = lcm/denominator;
        int y = lcm/f2.denominator;

        int num = x*numerator-y*f2.numerator;
        int den = lcm;

        this->numerator = num;
        this->denominator = den;

    }
    void multiply(Fraction f3){

        this->numerator = this->numerator*f3.numerator;
        this->denominator = this->denominator*f3.denominator;
    }
    
};


Fraction shift(int folds){
    if(folds==1){
     Fraction f3(0,1);
     return f3;
    }
    if(folds%2!=0){
        folds= folds-1;
    }
    Fraction temp(1,4);
    temp.devide(3,4);
    Fraction mult(1,4);
    mult.power(folds/2);
    Fraction unity(1,1);
    unity.subtract(mult);
    temp.multiply(unity);
    return temp;
}



int main(){
    int t;
    cin>>t;
    while(t--){
        int folds;
        cin>>folds;
        Fraction ans = shift(folds);
        if(folds%2==0){
            ans.simplify();
            ans.print();
        }
        else{
            Fraction temp(1,pow(2,folds));
            ans.add(temp);
            ans.simplify();
            ans.print();
        }

    }
    return 0;
}