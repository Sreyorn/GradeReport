#ifndef Person_h
#define Person_h
#include<iostream>
#include<string>
using namespace std;

class Person{
public:
    void setName(string first,string last);
    string getFirst()const;
    string getLast()const;
private:
    string fName;
    string lName;
};
void Person::setName(string f,string l){
    fName=f;
    lName=l;
}
string Person::getFirst()const{return fName;}
string Person::getLast()const{return lName;}
#endif /* Person_h */
