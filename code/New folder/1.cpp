#include<iostream>
#include<string>

using namespace std;

class Person {
	string name;
	string city;
public:
	
};

int main() {

	string st1 = "Ahmedabad";
	string st2 = " Nadiad";

	int index = st1.find(string("med"));
	cout << index << endl;

	cout << st1 << endl << st2 << endl;
	

	return 0;
}