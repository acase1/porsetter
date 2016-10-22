#include<cstring>
#include<vector>
#include<iostream>
#include<fstream>

using namespace std;

struct Rat {
    char name[50];
    int age;
};

//------Text I/O-----//
void display(Rat& rat) {
    cout << rat.name << endl;
    cout << rat.age << endl;
}

void writeTextData(ofstream& textFile, Rat& rat) {
    // write out to textfile the same text and format as display()
    textFile << rat.name << endl;
    textFile << rat.age << endl;
}

void readTextData(ifstream& textFile, Rat& rat) {
    // read in from text file the same text and format as display()
    // write to rat
    textFile >> rat.name;
    textFile >> rat.age;
}

istream& operator>>(istream& in, Rat& rat) {
    // read an entire rat from input stream
    
    return in >> rat.name >> rat.age;
}

ostream& operator<<(ostream& out, Rat& rat) {
    // write an entire rate to output stream.
    
    return out << rat.name << '\n' << rat.age << endl;
}

void writeBinaryData(ofstream& binaryFile, Rat& rat) {
    // write out to binaryFile the same info in binary format
    //binaryFile.write(rat.name, sizeof(rat.name));
    //binaryFile.write (reinterpret_cast<const char*>(rat.age), sizeof(rat.age));
    binaryFile.write(reinterpret_cast<char*>(&rat), sizeof(rat));
}

void readBinaryData(ifstream& binaryFile, Rat& rat) {
    // read in from binaryFile the same info in binary format
    // write to rat
    
    //binaryFile.read((char*)rat.name, sizeof(rat.name));
    binaryFile.read(reinterpret_cast<char*>(&rat), sizeof(rat));
}

int main() {
    Rat r1, r2, r3, r4, r5, r6;
    
    // r1's name is Ben age 2
    strcpy(r1.name , "Ben");
    r1.age = 2;
    
    // r2's name is Willard and age is 3
    strcpy(r2.name,"Willard");  
    r2.age = 3;
    
    // display r1 and r2
    display(r1);
    display(r2);
    
    // open ofstream rf "ratfarm.txt"
    ofstream rf("ratfarm.txt");
    
    // writeTextData r1 & r2
    writeTextData(rf,r1);
    writeTextData(rf,r2);
    
    rf.close();
    
    // readTextData into r3 & r4
    ifstream rfin("ratfarm.txt");
    
    if (rfin.good()) {
        readTextData(rfin, r3);
        readTextData(rfin, r4);
    }
    
   
    // display r3 & r4
    display(r3);
    display(r4);
    
    // open ofstream rf2 "ratfarm2.txt"
    ofstream rf2("ratfarm2.txt");
    
    rf2 << r1;
    rf2 << r2;
    rf2 << r3;
    rf2 << r4;
    cout << r3;
    cout << r4;
}