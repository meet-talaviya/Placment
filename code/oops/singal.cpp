// #include<iostream>
// using namespace std;

// int main(){

//     return 0;
// }

#include<iostream>
using namespace std;

class car{
    public:
    string name;
    int we;
    int age;

    void spped(){
        cout << "spped" << endl;
    }
};

class scorpio : public car{

};

int main(){

    scorpio sc;
    sc.spped();
    
    return 0;
}
