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
        cout<<this->numerator<<"/"<<this->denominator;
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
     Fraction add(Fraction f2){
        int lcm = this->denominator*f2.denominator;
        int x = lcm/denominator;
        int y = lcm/f2.denominator;

        int num = x*numerator+y*f2.numerator;
        int den = lcm;

        Fraction f3(num,den);
        f3.simplify();
        return f3;
    }

};




int main(){
    Fraction f1(1,4);
    Fraction f2(1,16);

    Fraction f3=f1.add(f2);
    cout<<f3.numerator<<"/"<<f3.denominator<<endl;
    f1.print();
    cout<<endl;
    f2.print();



    return 0;
}