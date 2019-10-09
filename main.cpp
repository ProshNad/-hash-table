#include <iostream>
#include "contact.h"
#include "contact.cpp"
#include <Windows.h>
#include <vector>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <sstream>
#include <string>
#include "book.cpp"
#include "book.h"
using namespace std;
 book<string> s;
 int k1,p1;
 string fi1;

void f1(), f2(),f3(),f4(),f5(),f6(),f7(),
f41(int,int),f42(int,int),f43(int,int),f44(int,int),f45(int,int),f46(int,int),f47(int,int),
f61(string),f62(string),f63(string),f64(string),f65(string),f66(string),f67(string);

void (*functions [])() = {
 f1,f2,f3,f4,f5,f6,f7
};

void (*function4 [])(int,int)={
   f41,f42,f43,f44,f45,f46,f47
};


void (*function6 [])(string)={
   f61,f62,f63,f64,f65,f66,f67
};
int m1(),m2();


int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int i=m1();

   while(i!=8){
       if(i>0)
           (*functions[i-1])();
       i=m1();
   }

    return 0;
}

int m1(){
    string s1;
    cout<<endl<<"Choose:"
       <<endl<<"1-Insert new contact"
       <<endl<<"2-Print book"
       <<endl<<"3-Return back"
       <<endl<<"4-Change the element"
       <<endl<<"5-Delete the element"
       <<endl<<"6-Find element by field"
       <<endl<<"7-Find element by key"
       <<endl<<"8-Exit from Programm"<<endl;
    cin>>s1;
    if (s1.size()==1){
     return atoi(s1.c_str());}
    else return -1;
}
 int m2(){
     string s1;
     cout<<endl<<"Choose the field:"
        <<endl<<"1-Surname"
        <<endl<<"2-Name"
        <<endl<<"3-Last name"
        <<endl<<"4-Phone"
        <<endl<<"5-Email"
        <<endl<<"6-Company"
        <<endl<<"7-Position in the company"
        <<endl;
     cin>>s1;
     if (s1.size()==1){
      return atoi(s1.c_str());}
     else return -1;

 }

void f1(){
    cout<<"Enter the Contact:"<<endl;
    Contact con;
     cin>>con;
     s.insert(make_pair(con.sname,con));
     s.safe();
}

void f2(){
     cout<<s;
}
void f3(){
    int h;
    cout<<"enter the number:";
    cin>>h;
    s.back(h);
}
void f4(){
   int i=m2();
   if(i>0){
       cout<<"What element?Enter number of key,position:";
       int k,p;
       cin>>k>>p;
       (*function4[i-1])(k,p);}

}
void f5(){
    cout<<"What element? Enter number of key and position:";
    int k,p;
    cin>>k>>p;
    s.delett(k,p);
}

void f6(){
    int i=m2();
    if(i>0){
        cout<<endl<<"Enter the field:";
        string fi;
        cin>>fi;
        (*function6[i-1])(fi);}
}

void f7(){
    cout<<"Enter the Surname:";
    string stri;
    cin>>stri;
    cout<<endl<<"position of key of"<<stri<< "is :"<<s.findk(stri);
}

void f41(int k, int p){
     s.changesn(k,p);
}
void f42(int k, int p){
    s.changen(k,p);
}
void f43(int k, int p){
     s.changeln(k,p);
}
void f44(int k, int p){
    s.changet(k,p);
}
void f45(int k, int p){
     s.changem(k,p);
}
void f46(int k, int p){
    s.changec(k,p);
}
void f47(int k, int p){
     s.changed(k,p);
}

void f61(string fi){
     cout<<"You can conduct a search by sname in '7-Find element by key', please return in main menu"<<endl;
}
void f62(string fi){
    s.findn(fi);
}
void f63(string fi){
    s.findln(fi);
}
void f64(string fi){
    s.findtel(fi);
}
void f65(string fi){
    s.findemeil(fi);
}
void f66(string fi){
     s.findcomp(fi);
}
void f67(string fi){
     s.finddl(fi);
}





