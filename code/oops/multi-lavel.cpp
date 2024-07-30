#include<iostream>
using namespace std;

class fruit{
    public:
    string name;
};

class mango : public fruit{
    public:
    int we;
};

class alphanso: public mango{
    public:
    int suger;
};

int main(){

    alphanso a;

    cout << a.name << " " << a.we << " " << a.suger << endl;

    
    return 0;
}