#include<iostream>
using namespace std;

class Animal{
    public:
    void spak(){
        cout << "spking" << endl;
    }
};

class dog : public Animal{
    public:
   void spak(){
        cout << "brathing" << endl;
    }
};

int main(){

    // dog d;
    // d.spak();

    // Animal * a = new Animal();
    // a->spak();

    // dog *a = new dog();
    // a->spak();

    // UpCasting
    // Animal *a = new dog;
    // a->spak();

    // downCasting
    dog *a = (dog*)new Animal;
    a->spak();

    return 0;
}