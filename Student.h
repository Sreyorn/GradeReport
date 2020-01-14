#ifndef Student_h
#define Student_h
#include"Person.h"
#include<string>
#include<iomanip>
#include<iostream>

using namespace std;
class Student:public Person{
public:
    void setInfo(string f,string l,int id, int noC,bool paid, Course co[], char gr[]);
    void print(ostream &out,double tuition);
    Student();
    int getHour()const;
    double getGPA();
    double billing(double rate);
private:
    void sortCourse();
    int sID;
    int numCourse;
    bool isPaid;
    Course course[6];
    char grade[6];
};
void Student::setInfo(string f,string l,int id, int noC,bool paid, Course co[], char gr[]){
    int i;
    setName(f,l);
    sID=id;
    isPaid=paid;
    for(i=0;i<noC;i++){
        course[i]=co[i];
        grade[i]=gr[i];
    }
    sortCourse();
}
Student::Student(){
    numCourse=0;
    sID=0;
    isPaid=false;
    for(int i=0;i<6;i++)
        grade[i]='*';
}
void Student::print(ostream &out,double rate){
    int i;
    out<<"Student Name: "<<getFirst()
    <<" "<<getLast()<<endl;
    out<<"Number of courses enrolled: "<<numCourse<<endl<<endl;
    out<<left;
    out<<"Course No"<<setw(15)<<"  CourseName"<<setw(8)<<"Credits"<<setw(6)<<"Grade"<<endl;
    out<<right;
    for(i=0;i<numCourse;i++){
        course[i].print(out);
        if(isPaid)
            out<<setw(4)<<grade[i]<<endl;
        else
            out<<setw(4)<<"***"<<endl;
    }
    out<<endl;
    out<<"Total number of credit hours: "<<getHour()<<endl;
    out<<fixed<<showpoint<<setprecision(2);
    if(isPaid)
        out<<"Mid-Semester GPA: "<<getGPA()<<endl;
    else{
        out<<"Grades are being held for not paying the tuition."<<endl;
        out<<"Amount Due: $"<<billing(rate)<<endl;
    }
}
int Student::getHour()const{
    int totalCre=0,i;
    for(i=0;i<numCourse;i++)
        totalCre+=course[i].getCredit();
    return totalCre;
}
double Student::billing(double rate){
    return rate*getHour();
}
double Student::getGPA(){
    int i;
    double sum=0.0;
    for(i=0;i<numCourse;i++){
        switch (grade[i]) {
            case 'A':
                sum+=course[i].getCredit()*4;
                break;
            case 'B':
                sum+=course[i].getCredit()*3;
                break;
            case 'C':
                sum+=course[i].getCredit()*2;
                break;
            case 'D':
                sum+=course[i].getCredit()*1;
                break;
            case 'F':
                break;
            default:
                cout<<"Invalid Grade."<<endl;
        }
    }
    return sum/getHour();
}
void Student::sortCourse(){
    int i,j,min;
    Course tmp;
    char gtmp;
    string c1,c2;
    for(i=0;i<numCourse-1;i++){
        min=i;
        for(j=i+1;j<numCourse;j++){
            c1=course[min].getcNum();
            c2=course[j].getcNum();
            if(c1>c2)
                min=j;
        }
        tmp=course[min];
        course[min]=course[i];
        course[i]=tmp;
        
        gtmp=grade[min];
        course[min]=course[i];
        grade[i]=gtmp;
    }
}
#endif /* Student_h */
