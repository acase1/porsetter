#include"Chinchilla.h"

private string name;
private int age;

Chinchilla::Chinchilla() {
    name = "";
    age = 0;
}

string getName() {
    return name;
}

int Chinchilla::getAge() {
    return age;
}

void Chinchilla::display() {
    cout << name << endl;
    cout << age << endl;
}

void writeTextData(ofstream& textFile) {
    textFile << name << endl;
    textFile << age << endl;
}

void readTextData(ifstream& textFile) {
    textFile >> name;
    textFile >> age;
}