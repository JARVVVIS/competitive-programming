#include<iostream>
using namespace std;


//make a class -> analogous of datatype
class Student{
    public:
     int rollnumber;
     int age;
    void display(){
        cout<< age << " " << rollnumber;
    }
    //default
    Student(){
        age = 10;
    }

};



int main(){

    //declaring statically
    Student s1;
    Student s2;
    //declaring dynamically
    Student *s3 = new Student;
    s1.age = 0;
    //setting properties
    cout<<s1.age;
    (*s3).rollnumber=21;
    s3->age =21;
    s1.display();
    Student s5(s1);
    return 0;
}