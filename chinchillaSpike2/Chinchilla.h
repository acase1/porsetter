#include<string>
#include<iostream>
#include<fstream>

using namespace std;

class Chinchilla
{

    private:
        string name;
        int age;
        
    public:
        Chinchilla();
        string getName()const;
        int getAge()const;
        void setName(string nameIn);
        void setAge(int ageIn);
        void display();
        void writeTextData(ofstream& textFile);
        void readTextData(ifstream& textFile);
        istream& operator>>(istream& in);
        ostream& operator<<(ostream& out);
        void writeBinaryData(ofstream& binaryFile);
        void readBinaryData(istream& binaryFile);
};