#include "book.h"
#include <iostream>
#include "contact.h"
#include <Windows.h>
#include <vector>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "SHA256.h"
#include "string"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <sstream>
#include <string>
#include <algorithm>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/function.hpp>
#include <boost/bind/bind.hpp>
#include "functional"

namespace pt = boost::property_tree;
using namespace std;


template <typename T>
book<T>::book()
{
   opr=0;

   pt::read_json("memory.json", root);

        opr=root.get<int>("opr");
            if(opr){

                for(int i=0;i<root.get<int>(nn(opr));i++){
                     for(int j=0;j<root.get<int>(in(opr,i));j++){
                         Contact co;
                         co=root.get<Contact>(ni(opr,i,j));
                         insert(make_pair(co.sname,co));
                         opr=root.get<int>("opr");
                     }
                     opr=root.get<int>("opr");
                }


            }

}

template <typename T>
void book<T>::insert(pair<string,Contact> t){
   opr++;
SHA256* hash_SHA256 = new SHA256();
int i;
for ( i=0;i<bk.size();i++){
   if(bk[i].first==hash_SHA256->hash(t.first).c_str()){
       bk[i].second.push_back(t.second);
       break;
   }
}
if(i==bk.size()){
   vector<Contact> c;
      c.push_back(t.second);

     bk.push_back(make_pair(hash_SHA256->hash(t.first).c_str(),c));

}

}

template <typename T>
void book<T>:: safe(){

    for(int i=0;i<bk.size();i++){     
         root.put(in(opr,i),bk[i].second.size());
        for(int j=0;j<bk[i].second.size();j++){
            root.put(ni(opr,i,j),bk[i].second[j]);
        }
    }

    root.put(nn(opr),bk.size());
    root.put("opr",opr);
    pt::write_json("memory.json", root);

}

template <typename T>
void book<T>::delett(int i,int j){
    opr++;
    bk[i].second.erase(bk[i].second.begin()+j);
    safe();
    bk.erase(bk.begin(),bk.end());
    book<string> rez;
    bk=rez.bk;

}

///изменщики////
template <typename T>
void book<T>:: changet(int i,int j){
    try {
        cout<<endl<<"You want to change this contact(enter 0 if 'No')?"<<endl<<bk[i].second[j]<<endl;
        int h; cin>>h;
        if(h){
          cout<<"Enter the new tel:";
          string k;
          cin>>k;
          bk[i].second[j].tel=k;
          opr++;
          safe();
        }

    }
    catch(exception ){
        cout<<"No element  on this position";
    }
}

template <typename T>
void book<T>:: changem(int i, int j){
    try {
        cout<<endl<<"You want to change this contact(enter 0 if 'No')?"<<endl<<bk[i].second[j]<<endl;
        int h; cin>>h;
        if(h){
          cout<<"Enter the new email:";
          string k;
          cin>>k;
          bk[i].second[j].email=k;
          opr++;
          safe();
        }

    }
    catch(exception ){
        cout<<"No element  on this position";
    }

}

template <typename T>
void book<T>:: changec(int i, int j){
    try {
        cout<<endl<<"You want to change this contact(enter 0 if 'No')?"<<endl<<bk[i].second[j]<<endl;
        int h; cin>>h;
        if(h){
          cout<<"Enter the new name of company:";
          string k;
          cin>>k;
          bk[i].second[j].comp=k;
          opr++;
          safe();
        }

    }
    catch(exception ){
        cout<<"No element  on this position";
    }

}

template <typename T>
void book<T>:: changed(int i, int j){
    try {
        cout<<endl<<"You want to change this contact(enter 0 if 'No')?"<<endl<<bk[i].second[j]<<endl;
        int h; cin>>h;
        if(h){
          cout<<"Enter the new position in the company:";
          string k;
          cin>>k;
          bk[i].second[j].dl=k;
          opr++;
          safe();
        }

    }
    catch(exception ){
        cout<<"No element  on this position";
    }
}

template <typename T>
void book<T>::changen(int i, int j){
    try {
        cout<<endl<<"You want to change this contact(enter 0 if 'No')?"<<endl<<bk[i].second[j]<<endl;
        int h; cin>>h;
        if(h){
          cout<<"Enter the new name:";
          string k;
          cin>>k;
          bk[i].second[j].name=k;
          opr++;
          safe();
        }

    }
    catch(exception ){
        cout<<"No element  on this position";
    }

}

template <typename T>
void book<T>::changeln(int i, int j){
    try {
        cout<<endl<<"You want to change this contact(enter 0 if 'No')?"<<endl<<bk[i].second[j]<<endl;
        int h; cin>>h;
        if(h){
          cout<<"Enter the new last name:";
          string k;
          cin>>k;
          bk[i].second[j].lname=k;
          opr++;
          safe();
        }

    }
    catch(exception ){
        cout<<"No element  on this position";
    }

}

template <typename T>
void book<T>::changesn(int i, int j){
    try {
        cout<<endl<<"You want to change this contact(enter 0 if 'No')?"<<endl<<bk[i].second[j]<<endl;
        int h; cin>>h;
        if(h){
          cout<<endl<<"Enter the new surname(Attention! The hash will be change!):";
          string k;
          cin>>k;
          Contact r;
          r=bk[i].second[j];
          r.sname=k;
          delett(i,j);
          insert(make_pair(r.sname,r));
          safe();
          bk.erase(bk.begin(),bk.end());
          book rez;
          bk=rez.bk;
        }
    }
    catch(exception ){
        cout<<"No element  on this position";
    }

}

template <typename T>
void book<T>:: back(int i){
    opr=opr-i;
    root.put("opr",opr);
    pt::write_json("memory.json", root);

    bk.erase(bk.begin(),bk.end());
    book rez;
    bk=rez.bk;

    book();

}

////поисковики////
template <typename T>
int book<T>:: findk(T key){
    SHA256* hash_SHA256 = new SHA256();
    int i;
    for (i=0;i<bk.size();i++){
     if(bk[i].first==hash_SHA256->hash(key).c_str()){
         return i;
     }
    }
    if(i==bk.size()) return -1;
}

template <typename T>
void book<T>:: findtel(string t){
    for(int i=0;i<bk.size();i++){
     for(int j=0;j<bk[i].second.size();j++){
         if(bk[i].second[j].tel.find(t)!=string::npos){
             cout<<"For key "<<bk[i].first<<endl<<"Find element:"<<bk[i].second[j];
         }
     }
    }
 }

template <typename T>
void book<T>::findemeil(string e){
    for(int i=0;i<bk.size();i++){

     for(int j=0;j<bk[i].second.size();j++){
         if(bk[i].second[j].email==e){
             cout<<"For key "<<bk[i].first<<endl<<"Find element:"<<bk[i].second[j];
         }
     }
    }
 }

template <typename T>
void book<T>::findcomp(string c){
    for(int i=0;i<bk.size();i++){
     for(int j=0;j<bk[i].second.size();j++){
         if(bk[i].second[j].comp==c){
             cout<<"For key "<<bk[i].first<<endl<<"Find element:"<<bk[i].second[j];
         }
     }
    }
}

template <typename T>
void book<T>::finddl(string d){
    for(int i=0;i<bk.size();i++){
     for(int j=0;j<bk[i].second.size();j++){
         if(bk[i].second[j].dl==d){
             cout<<"For key "<<bk[i].first<<endl<<"Find element:"<<bk[i].second[j];
         }
     }
    }
}

template <typename T>
void book<T>::findn(string d){
    for(int i=0;i<bk.size();i++){
     for(int j=0;j<bk[i].second.size();j++){
         if(bk[i].second[j].name==d){
             cout<<"For key "<<bk[i].first<<endl<<"Find element:"<<bk[i].second[j];
         }
     }
    }
}

template <typename T>
void book<T>::findln(string d){
    for(int i=0;i<bk.size();i++){
     for(int j=0;j<bk[i].second.size();j++){
         if(bk[i].second[j].lname==d){
             cout<<"For key "<<bk[i].first<<endl<<"Find element:"<<bk[i].second[j];
         }
     }
    }
}
template <typename T>
string book<T>::nn(int k){
   ostringstream ostrop;
   ostrop <<k;
   return "book"+ostrop.str()+".size";
}

template <typename T>
string book<T>::ni(int k, int m,int g){
   ostringstream ostrop,ostr,ostr1;
   ostrop <<k;
   ostr <<m;
   ostr1<<g;
   return "element"+ostrop.str()+"."+ostr.str()+ostr1.str();
}

template <typename T>
string book<T>::in(int k, int m){
   ostringstream ostrop,ostr;
   ostrop <<k;
   ostr <<m;
   return "size"+ostrop.str()+"."+ostr.str();
}

