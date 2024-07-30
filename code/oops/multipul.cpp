#include<iostream>
using namespace std;

class A{
    public:
    int ph;
    int ch;
};

class B{
    public:
    int ch;
};

class C : public A , public B{
    public:
    int mh;

};

int main(){

    C c;
    cout << c.A::ch << " " << c.mh << " " << c.ph << endl;
    
    return 0;
}