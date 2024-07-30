#include <bits/stdc++.h>
using namespace std;

class Animal{
    
    private:
    int wegit;
   
    public:
    //propertiy
    int age;
    string name;

    //default Constructor-----
    Animal(){
        this->wegit = 0;
        this->age = 0;
        this->name = "";
        cout << "Constructor called " << endl;
    }

    // parameter constructor-----
    Animal(int age){
        this->age = age;
        cout <<"parameter cons" << endl;
    }

    Animal(int age, int wegit){
        this->age = age;
        this->wegit = wegit;
        cout << "two paramete" << endl;
    }

    Animal(int age, int wegit, string name){
        this->age = age;
        this->wegit = wegit;
        this->name = name;
        cout << "three paramete" << endl;
    }

    // copy constryctor-----
    Animal(Animal &obj){
        this->age = obj.age;
        this->wegit= obj.wegit;
        this->name = obj.name;
        cout << "copy" << endl;
    }

    // behaviour : function : method-----
    void eat(){
        cout << "eating" << endl;
    }

    void sleep(){
        cout << "sleepling" << endl;

    }

    int getWegit(){
        return this->wegit;
    }

    // void setWegit(int w){
    //     wegit = w;
    // }

    void setWegit(int wegit){
        this->wegit = wegit;
    }

    void print(){
        cout << this->age << " " << this->wegit << " " << this->name << endl;
    }
   
    // Destructor ----
    ~Animal(){
        cout << "destructor" << endl;
    }
    
};

int main(){
    // cout << "Empty size of class : " << sizeof(Animal) << endl;
  
    // object create

    // static---------------- 
    // Animal a;
    // a.age = 12;
    // a.name = "Lion";
    // cout << "Age : " << a.age << endl;
    // cout << "name : " << a.name << endl;
    // a.eat();
    // a.sleep();

    // // cout << "wegit : " << a.wegit << endl;
    // a.setWegit(12);
    // cout << "wegit : " << a.getWegit()<< endl;


    // Dynamic------------

    // Animal* an = new Animal;

    // (*an).age = 13;
    // (*an).name = "cate";
 
    // // (* === ->)  both throw access
    // an->age = 17;
    // an->name = "dog";

    // an->eat();
    // an->sleep();

    // Animal a(100);

    // Animal b(100 , 5);

    // // object copy
    // Animal d = a;
    // Animal c(b);

    //  Animal a;
    //  a.age = 10;
    //  a.setWegit(101);
    //  a.name = "meet";

    //  Animal b = a;

    //  a.print();
    //  b.print();

    cout << "a object" << endl;
    Animal a;
    a.age = 5;

    cout << "b object" << endl;

    Animal* b = new Animal;
    b->age = 10;

    // manully
    delete b;



    return 0;
}
