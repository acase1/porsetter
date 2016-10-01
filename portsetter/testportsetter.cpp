#include"iostream"
#include<stdlib.h>
#include<fstream>
#include<cstring>

using namespace std;

int main(){
    //local variables
    int systemCode;
    int expSysCode;
    int testCount = 0;
    int testFailed = 0;
    int msgNotMatch = 0;
    string fileToCompare;
    string begCompStmnt = "diff test.txt ";
    
    
    //create file object
    ifstream testCases ("testCases.txt");
    
    
    if(testCases.is_open()){
        //loop through testCases.txt file until all tests have been performed.
        while(testCases.peek() != EOF){
            
            string input;
            
            //Reads in the test input value and turns into const char *
            getline(testCases, input);
            char * testInput = new char [input.length()+1];
            strcpy (testInput, input.c_str());

            //Reads in the expected return value from the test input
            getline(testCases, input);
            expSysCode = stoi(input); 
            
            //Reads in the file to compare the printed output to test.txt file
            getline(testCases, fileToCompare);
            string temp = begCompStmnt + fileToCompare;
            char * compStatement = new char [temp.length()+1];
            strcpy (compStatement, temp.c_str());
            
            //performs program call
            systemCode = system(testInput) / 256;
            
            //If system value returned is not equal to expected return test fails
            if (systemCode != expSysCode) {
                cout << "Test for '" << testInput << "' failed!" << endl;
                ++testFailed;
            } else {
                cout << "Test for '" << testInput << "' succeeded." << endl;
            }
            
            //compares the output given from the call to output expected
            systemCode = system(compStatement) / 256;
            
            //if output doesn't match fail test.
            if (systemCode != 0) {
                cout << "Output did not match.\n" << endl;
                ++msgNotMatch;
            } else {
                cout << "Output matched.\n" << endl;
            }
            
            ++testCount;
        }//end of while loop to read testInput file
    } else {
        cout << "File failed to open." << endl;
    }
    
    //prints results
    cout << "Results: " << endl;
    cout << "Tests performed: " << testCount << endl;
    cout << "Tests Failed: " << testFailed << endl;
    cout << "Outputs that didn't match: " << msgNotMatch << endl;
    
}