#ifndef Course_h
#define Course_h
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Course{
public:
    void setCourseInfo(string cname,string cno,int cr);
    void print(ostream &outFile);
    //get functions
    string getcName()const;
    string getcNum()const;
    int getCredit()const;
    Course(string cname="",string cno="",int cr=0);
private:
    string cName;
    string cNumber;
    int credit;
};
void Course::setCourseInfo(string cname,string cno,int cr){
    cName=cname;
    cNumber=cno;
    credit=cr;
}
void Course::print(ostream& outFile){
    outFile<<left;
    outFile<<setw(8)<<cNumber<<"   "
    <<setw(15)<<cName;
    outFile<<right;
    outFile<<setw(3)<<credit<<"   ";
}
Course::Course(string cname,string cno,int cr){
    cName=cname;
    cNumber=cno;
    credit=cr;
}

string Course::getcName()const{return cName;}
string Course::getcNum()const{return cNumber;}
int Course::getCredit()const{return credit;}
#endif /* Course_h */
