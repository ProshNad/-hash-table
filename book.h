#ifndef BOOK_H
#define BOOK_H

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


template<class T>
class book
{
private:
    vector<pair<T, vector <Contact> > >  bk;
    int opr;
    pt::ptree root,child;
public:
    book();

    void insert(pair<string,Contact>);

    int findk(T );

    void findtel(string);

    void findemeil(string);

    void findcomp(string);

    void finddl(string);

    void findn(string);

    void findln(string);

    void safe();

    void delett(int,int);

    void changet(int ,int );

    void changem(int , int );

    void changec(int , int );

    void changed(int, int );

    void changen(int , int );

    void changeln(int , int );

    void changesn(int, int);

    void back(int);

    string in(int,int);
    string ni(int,int,int);
    string nn(int);

    friend  ostream&  operator << (ostream &c, const book<T> &a){//вывод
        for(int i=0;i<a.bk.size();i++){
            c<<"Key"<<i<<":"<<a.bk[i].first<<endl<<endl;
            for(int j=0;j<a.bk[i].second.size();j++){
                c<<"Element "<<j<<":"<<a.bk[i].second[j]<<endl<<endl;

            }
        }
       return c;
    }

};


#endif // BOOK_H


