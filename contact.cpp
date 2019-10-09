#include "contact.h"
using namespace std;
#include "iostream"
#include <Windows.h>

Contact::Contact()
{
}
  istream&  operator >> (istream &c,  Contact &a){//ввод
    c>>a.sname>>a.name>> a.lname>>a.tel>>a.email>>a.comp>>a.dl;
   return c;
}
 ostream&  operator << (ostream &c,const Contact &a){//вывод
     SetConsoleCP(1251);
     SetConsoleOutputCP(1251);
   return c<<endl<<a.sname<<endl
          <<a.name<<endl<<a.lname
         <<endl<<a.tel<<endl<<a.email<<endl
        <<a.comp<<endl<<a.dl;

}


