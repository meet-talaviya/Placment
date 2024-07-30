#include <bits/stdc++.h>
using namespace std;

// class Animal
// {
// private:
//     int age;
//     int weight;

// public:
//     void eat()
//     {
//         cout << "Eating" << endl;
//     }

//     int getAge()
//     {
//         return this->age;
//     }

//     void setAge(int age)
//     {
//         return this->age = age;
//     }
// };

class Animal{
    public:
    int age;
    int we;

    void eat(){
        cout << "eating" << endl;
    }
};

class dog : public Animal{

};

int main()
{
    dog d1;
    d1.eat();

    return 0;
}