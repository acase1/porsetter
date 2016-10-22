#include<string>
#include<iostream>
#include<fstream>

using namespace std;

class Chinchilla {
private:
    std::string name;
    int age;
    
public:
    Chinchilla(std::string, int);
    void display();
};

Chinchilla::Chinchilla(string n, int a) {
    name = n;
    age = a;
}

void Chinchilla::display() {
    cout << name << endl;
    cout << age << endl;
}

int main() {
    Chinchilla c1 = Chinchilla("Ben",2);
    Chinchilla c2 = Chinchilla("Willard",3);
    
    c1.display();
    c2.display();
}