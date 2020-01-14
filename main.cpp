#include"Course.h"
#include"Person.h"
#include"Student.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
void getData(ifstream &infile, Student stList[],int num);
void printGrade(ofstream &outfile,Student stList[],int num,double rate);

int main(){
    const int SIZE=10;
    Student st[SIZE];
    int noSt;
    double rate;
    ifstream in;
    ofstream out;
    in.open("stData.txt");
    if(!in){
        cout<<"Cannot open file"<<endl;
        return 1;
    }
    out.open("saleOut.txt");
    in>>noSt;
    in>>rate;
    getData(in,st,noSt);
    printGrade(out, st, noSt, rate);
    return 0;
}

void getData(ifstream &infile, Student stList[],int num){
    string f,l,cName,cNo;
    int id,noCourse,cr,count,i;
    char p;
    bool paid;
    Course course[6];
    char grade[6];
    for(count=0;count<num;count++){
        infile>>f>>l>>id>>p;
        if(paid=='Y')
            paid=true;
        else
            paid=false;
        infile>>noCourse;
        for(i=0;i<num;i++){
            infile>>cName>>cNo>>cr>>grade[i];
            course[i].setCourseInfo(cName, cNo, cr);
        }
        stList[count].setInfo(f,l,id,noCourse,paid,course,grade);
    }
}
void printGrade(ofstream &outfile,Student stList[],int num,double rate){
    int cnt;
    for(cnt=0;cnt<num;cnt++)
        stList[cnt].print(outfile,rate);
}


