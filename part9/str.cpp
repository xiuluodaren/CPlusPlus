#include <iostream>
#include <cstring>
using namespace std;

class str{
    private :
        char *st;
    public :
        str(char *s);
        str(str &s);
        str& operator=(str& a);
        str& operator=(char *s);
        void print(){cout << st << endl;}
        ~str(){delete st;}
};

str::str(char *s)
{
    st = new char[strlen(s) + 1];
    strcpy(st, s);  //将字符串s复制到内存区st
}

str::str(str& a)
{
    st = new char[strlen(a.st) + 1];
    strcpy(st, a.st);
}

str& str::operator=(str& a)
{
    if (this == &a)
    {
        return *this;
    }

    delete st;

    st = new char[strlen(a.st) + 1];
    strcpy(st, a.st);
    return *this;
}

str& str::operator=(char *s)
{
    delete st;
    st = new char[strlen(s) + 1];
    strcpy(st, s);
    return *this;
}

int main(){
    str s1("We"), s2("They"), s3(s1);
    s1.print();s2.print();s3.print();
    s2 = s1 = s3;
    s3 = "Go home!";
    s3 = s3;
    s1.print();s2.print();s3.print();


    return 0;
}

