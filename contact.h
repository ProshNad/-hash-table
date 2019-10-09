#ifndef CONTACT_H
#define CONTACT_H
#include "string.h"
#include <string>
using namespace std;

class Contact
{

private:
public:
    string name,
           sname,
           lname,
           tel,
           email,
           comp,
           dl;
    Contact();
friend  istream&  operator >>(istream &c,  Contact &a);
friend  ostream&  operator << (ostream &c,const Contact &a);
};







#endif // CONTACT_H
